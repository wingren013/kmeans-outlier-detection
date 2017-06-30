//mean_i = 1/i * (sum(1, x, n))

void	assign_means(double **meanset, size_t k, size_t datasize)
{
	size_t	i = 0;
	
	*meanset = (double*)calloc(k, sizeof(double));
	
	while (i < k)
	{
		*meanset[i] = data[rand() % datasize];
		i++;
	}
}