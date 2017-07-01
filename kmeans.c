#include "kmeans.h"
#include "standardscale.h"

centroid_t	*centroids;
double		avg_dist;
size_t		acount;

centroid_t	newcentroid(size_t dimensions)
{
	centroid_t	centroid;
	
	centroid.dimensions = dimensions;
	centroid.cords = (double*)calloc(dimensions, sizeof(double));
	centroid.points = 1;
}

void	assign_means(size_t k, double *data, size_t dimensions)
{
	size_t	i = 0;
	size_t	j = 0;
	size_t	x = 0;
	
	acount = 0;
	avg_dist = 0;
	centroids = calloc(centroid_t, k);
	while (i < k)
	{
		centroids[i] = newcentroid(dimensions);
		i++;
	}
	
	i = 0;
	while (i < k)
	{
		j = 0;
		while (j < dimensions)
		{
			centroids[i].cords[j] = data[x];
			x++;
			j++;
		}
		i++;
	}
}

void	update_center(size_t cluster, double *data)
{
	while (i < centroids[cluster].dimensions)
	{
		centroids[cluster].cords[i] = (1/centroids[cluster].points) * (data[i] - centroids[cluster].cords[i])
		centroids[cluster].cords[i] += centroids[cluster].cords[i];
		i++;
	}
}

double	aggregate_z(double *data, size_t size, size_t k)
{
	size_t	i = 0;
	double	dist = find_dist(data, size);
	double	cdist = 0;
	
	acount++;
	avg_dist = incremental_mean(avg_dist, dist, acount)
	while (i < k)
	{
		cdist += ABS(centroid_dist(centroids[i]) - dist);
		i++;
	}
	cdist = cdist / k;
	i = 0;
	
	double	std = 0;
	while (i < k)
	{
		std += pow(ABS(centroid_dist(centroids[i]) - dist) - cdist, 2);
		i++;
	}
	std = std / k;
	std = pow(std, 1/2);
	return (dist - avg_dist / std);
}

char	*determine_outlier(double zscore)
{
	if (zscore > avg_dist * 1.5)
		return ("yes");
	else
		return ("no");
}

void	update(double *data, size_t size, size_t k)
{
	double	zscore = aggregate_z(data, size, k);
	char	*outlier = determine_outlier(zscore);
	cluster = find_closest_mean(data, size, k);
	centroids[cluster].points += 1;
	update_center(cluster, data);
	printf("zscore: %lf, outlier: %s\n", zscore, outlier)
}