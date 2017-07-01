#include "kmeans.h"

centroid_t	*centroids;

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

void	update(double *data, size_t size, size_t k)
{
	double	zscore = aggregate_z(data, size);
	cluster = find_closest_mean(data, size, k);
	centroids[cluster].points += 1;
	update_center(cluster, data);
	printf("zscore: %lf, outlier: %s\n", zscore, outlier)
}