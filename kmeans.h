#ifndef KMEANS_H
# define KMEANS_H

#include <stdlib.h>
#include <math.h>

#define ABS(X) ((X)<0 ? -(X) : (X))

typedef struct	centroid_s
{
	double	*cords;
	size_t	points;
	size_t	dimensions;
}				centroid_t;

extern centroid_t	*centroids;

void	assign_means(size_t k, double *data, size_t dimensions);
void	update(double *data, size_t size, size_t k);
double	centroid_dist(centroid_t centroid);
double	find_dist(double *data, size_t size);
size_t	find_closest_mean(double *data, size_t size, size_t k);

#endif