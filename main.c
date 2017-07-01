//include
#include <stdlib.h>
#include "standardscale.h"
#include "kmeans.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define USAGE printf("./app inputfile.csv k"); return (0)

double	myparse(char *str)
{
	double	ret;
	
	sscanf(str, "%lf", &ret);
	return (ret);
}

size_t	get_dimensions(char *str)
{
	while (*str)
	{
		if (*str == '_')
			break ;
		str++;
	}
	*str++;
	while (*str)
	{
		if (*str == '_')
			break ;
		str++;
	}
	*str++;
	return (atoi(str));
}


void	push_data(int fd, int *mode, size_t k, size_t dimensions)
{
	size_t	i = 0;
	size_t	x = 0;
	char	c;
	char	*buf = calloc(1, 1);
	double	*data = calloc(1, sizeof(double));
	size_t	j = 0;
	
	while(*mode == 1)
	{
		j = 0;
		while (read(fd, &c, 1))
		{
			if (c == ',')
				break ;
			buf[j] = c;
			j++;
			buf = realloc(buf, j + 1);
			buf[j] = 0;
		}
		data[i] = myparse(buf);
		if (i % dimensions == 0)
			x++;
		i++;
		data = realloc(data, sizeof(double) * i + 1);
		//online mode check
		if (x == k)
			break ;
	}
	if (*mode == 1)
	{
		*mode = 2;
		assign_means(k, data, dimensions);
		return ;
	}
	while(*mode == 2)
	{
		j = 0;
		while (read(fd, &c, 1))
		{
			if (c == ',')
				break ;
			buf[j] = c;
			j++;
			buf = realloc(buf, j + 1);
			buf[j] = 0;
		}
		data[i] = myparse(buf);
		if (i % dimensions == 0)
		{
			update(&data[i - (dimensions - 1)], dimensions, k);
			i = -1;
		}
		i++;
		data = realloc(data, sizeof(double) * i + 1);
	}
}

int	main(int argc, char **argv)
{
	//if (argc < 2)
		//USAGE;
	int 	fd = open(argv[1], O_RDONLY);
	size_t	k = atoi(argv[2]);
	int		mode = 1;
	
	while (1)
	{
		push_data(fd, &mode, k, get_dimensions(argv[1]));
	}
	return (0);
}