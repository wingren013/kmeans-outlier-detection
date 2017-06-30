#include <math.h>
#include "standardscale.h"

//mean_i = 1/i * (sum(1, x, n))

//assign_means(&empty, k, &(data[floor]), ceiling)
void	assign_means(double **meanset, size_t k, double *data, size_t datasize)
{
	size_t	i = 0;
	
	*meanset = (double*)calloc(k, sizeof(double));
	
	while (i < k)
	{
		*meanset[i] = data[rand() % datasize];
		i++;
	}
} //this goes somwehere else techinacally

double incremental_mean(double mean, double, prevmean, double newval, size_t count)
{
	mean = prevmean + (newval - prevmean)/count;
}

void	incremental_variance()
{
	variance = (n - 2)prev + (n -1)(incremental_mean(prev) - incremental_mean(now))^2;
	varaince += (current_element - incremental_mean(now))^2;
	variance /= n - 1;
	return(variance);
}

//Wellfords algorithm
double	online_variance(double *data, size_t datasize, double *newmean)
{
	size_t	n = 0;
	double	mean = 0;
	double	delta = 0;
	double	m2 = 0;
	
	while (i < datasize)
	{
		n++;
		delta = data[i] - mean;
		mean += delta/n
		delta2 = data[i] - mean;
		m2 = delta * delta2;
	}
	*newmean = mean;
	if (n < 2)
		return (0);
	return (m2 / (n - 1));
}

//mean_std(&mean, &std, &data[floor], ceiling);
void	mean_std(double *meanp, double *stdp, double *data, size_t datasize)
{
	*stdp = pow(online_variance(data, datasize, meanp), 1/2)
}