#include "kmeans.h"

double	find_dist(double *data, size_t size)
{
	double	ret = 0;
	size_t	i = 0;
	
	while (i < size)
	{
		ret += data[i] * data[i]; // (a_1 - a_2)^2 = a_1^2 when a_2 is 0
		i++;
	}
	return (pow(ret, 1/2));
}

double	centroid_dist(centroid_t centroid)
{
	return (find_dist(centroid.cords, centroid.dimensions));
}

size_t	find_closest_mean(double *data, size_t size, size_t k)
{
	size_t	i = 1;
	double	dist;
	double	cdist;
	size_t	ret;
	
	dist = find_dist(data, size);
	cdist = centroid_dist(centroids[0]);
	while (i < k)
	{
		if (ABS(centroid_dist(centroids[i]) - dist) < ABS(cdist - dist))
		{
			cdist = centroid_dist(centroids[i]);
			ret = i;
		}
		i++;
	}
	return (i);
}