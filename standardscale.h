#ifndef STANDARDSCALE_H
# define STANDARDSCALE_H

#include <math.h>
#include <stdlib.h>

#define ZSCORE (VAL, STD, CLUSTERMEAN) (VAL - CLUSTERMEAN) / STD;

//standardscale.c

//computes incremental mean
double incremental_mean(double mean, double, prevmean, double newval, size_t count);

//computes incremental variance. Also assigns the appropriate incremental mean to newmean. Use mean_std instead. Returns INT_MIN in case of error
double	online_variance(double *data, size_t datasize, double *newmean);

//assigns the satandard deviation and mean to the given pointers.
//mean_std(&mean, &std, &data[floor], ceiling);
void	mean_std(double *meanp, double *stdp, double *data, size_t datasize);

/*
**
*/

//zscores.c

// mean centers a data subset
void	mean_center(double *data, size_t datasize, double clustermean);

// computes the zscore for a given value
double	zscore(double val, double std, double *clustermean);

#endif