#include <limits.h>
#include "standardscale.h"

//mean_i = 1/i * (sum(1, x, n))

double incremental_mean(double prevmean, double newval, size_t count)
{
	double	mean;
	
	mean = prevmean + (newval - prevmean)/count;
	return (mean);
}

/*void	incremental_variance()
{
	variance = (n - 2)prev + (n -1)(incremental_mean(prev) - incremental_mean(now))^2;
	varaince += (current_element - incremental_mean(now))^2;
	variance /= n - 1;
	return(variance);
}*/

//Wellfords algorithm

double	online_variance(double *data, size_t datasize, double *newmean)
{
	size_t	n = 0;
	double	mean = 0;
	double	delta = 0;
	double	delta2 = 0;
	double	m2 = 0;
	
	while (n < datasize)
	{
		n++;
		delta = data[n] - mean;
		mean += delta/n;
		delta2 = data[n] - mean;
		m2 += delta * delta2;
	}
	*newmean = mean;
	if (n < 2)
		return (INT_MIN);
	return (m2 / (n - 1));
}

//mean_std(&mean, &std, &data[floor], ceiling);
void	mean_std(double *meanp, double *stdp, double *data, size_t datasize)
{
	*stdp = pow(online_variance(data, datasize, meanp), 1/2);
}