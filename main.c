//include
#include <stdlib.h>
#include "standardscale.h"
#include "kmeans.h"
#include <stdio.h>
#include <fcntl.h>

#define USAGE printf("./app inputfile.csv k"); return (0)

double	myparse(char *str)
{
	double	ret;
	
	sscanf(str, "%lf", &d);
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
	return (atoi(str));
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		USAGE;
	int 	fd = open(argv[1], O_RDONLY);
	size_t	k = atoi(argv[2]);
	int		mode = 1;
	
	while (1)
	{
		push_data(fd, &mode, k, get_dmensions(argv[1]));
	}
}

void	push_data(int fd, int *mode, size_t k, size_t dimensions)
{
	size_t	i = 0;
	size_t	x = 0;
	char	c;
	char	*buf = calloc(1, 1);
	double	*data = calloc(1, sizeof(double));
	
	while(*mode == 1)
	{
		size_t	j = 0;
		while (read(fd, &c, 1))
		{
			if (c == ',')
				break ;
			buf[j] = c;
			j++;
			realloc(buf, j + 1)
			buf[j] = 0;
		}
		data[i] = myparse(buf);
		if (i % dimensions == 0)
			x++;
		i++;
		realloc(data, sizeof(double) * i + 1);
		free(buf);
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
			realloc(buf, j + 1)
			buf[j] = 0;
		}
		data[i] = myparse(buf);
		if (i % dimensions == 0)
		{
			update(&data[i - (dimensions - 1)], dimensions, k);
			i = -1;
		}
		i++;
		realloc(data, sizeof(double) * i + 1);
		free(buf);
	}
}