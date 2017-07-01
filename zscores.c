#include "standardscale.h"

//mean_center(&data[floor], ceiling, mean);
void	mean_center(double *data, size_t datasize, double clustermean)
{
	size_t	i = 0;
	
	while (i < datasize)
	{
		data[i] = data[i] - clustermean;
		i++;
	}
}

double	zscore(double val, double std, double *clustermean)
{
		return (val - *clustermean / std);
}