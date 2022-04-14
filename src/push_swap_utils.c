/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:51:04 by wprintes          #+#    #+#             */
/*   Updated: 2022/04/14 01:34:55 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	right_order(int *a, int len_a, int len_b)
{
	int	i;

	i = 0;
	if (len_b != 0)
		return (1);
	while ((i + 1) < len_a)
	{
		if (a[i] > a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	*char_to_int(int argc, char **argv)
{
	int			i;
	int			*a;
	long int	temp;

	i = 0;
	a = malloc (sizeof(int) * (argc - 1));
	while ((i + 1) < argc)
	{
		temp = ft_atoi(argv[i + 1]);
		if (exist(a, i, temp) == 1)
		{
			free(a);
			return (NULL);
		}	
		if (temp > 2147483647)
			return (NULL);
		if (temp < -2147483648)
			return (NULL);
		a[i] = (int) temp;
		i++;
	}
	return (a);
}

size_t	my_sqrt(int number)
{
	size_t	i;

	i = 0;
	while (i * i <= (size_t)number)
	{
		if (i * i == (size_t)number)
			return (i);
		i++;
	}
	return (i - 1);
}

void	init_found(int **found, int divs, int *a)
{
	int	i;

	i = 0;
	while (i < divs)
	{
		found[0][i] = 2147483647;
		i++;
	}
}

int	exist(int *a, int len, int value)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (a[i] == value)
			return (1);
		i++;
	}
	return (0);
}
