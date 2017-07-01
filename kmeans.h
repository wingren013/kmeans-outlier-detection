#ifndef KMEANS_H
# define KMEANS_H

#define ABS(X) ((X)<0 ? -(X) : (X))

typedef struct	centroid_s
{
	double	*cords;
	size_t	points;
	size_t	dimensions;
}				centorid_t;

extern centroid_t	*centroids;

#endif