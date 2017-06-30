centroid_t	*centroids;

centroid_t	newcentroid()
{
	
}

void	assign_means(size_t k, double *data, size_t dimensions)
{
	size_t	i = 0;
	size_t	j = 0;
	size_t	x = 0;
	
	centroids = calloc(centroid_t, k);
	while (i < k - 1)
	{
		centroid[i] = newcentroid();
		i++;
	}
	
	i = 0;
	while (i < k - 1)
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

void	update(double *data, size_t size)
{
	zscores[zi] = aggregate_z(data, size);
	cluster = find_closest_mean(data, size);
	update_points_in_cluster(cluster);
	update_center(cluster);
}