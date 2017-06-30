#include <math.h>
#include <stdlib.h>
#include "standardscale.h"

#define ZSCORE (VAL, STD, CLUSTERMEAN) (VAL - CLUSTERMEAN) / STD;

//mean_center(&data[floor], ceiling, mean);
void	mean_center(double *data, size_t datasize, double clustermean)
{
	size_t	i = 0;
	
	while (i < data_size)
	{
		data[i] = data[i] - clustermean;
		i++;
	}
}

double	zscore(double val, double std, double *clustermean)
{
		return (val - *clustermean / std);
}