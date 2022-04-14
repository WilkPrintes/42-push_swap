/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:46:40 by wprintes          #+#    #+#             */
/*   Updated: 2022/04/14 01:44:02 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_b(int**a, int **b, int *len_b);
int		*init_temp(int**a, int **b, int *len_b, int *len_a);

int	sa(int **a)
{
	int	temp;

	temp = a[0][0];
	a[0][0] = a[0][1];
	a[0][1] = temp;
	ft_putstr("sa\n");
	return (1);
}

int	pb(int **a, int **b, int *len_b, int *len_a)
{
	int	*temp;
	int	i;

	init_b(a, b, len_b);
	i = 0;
	len_a[0]--;
	temp = malloc (sizeof(int) * (len_a[0]));
	while (i < len_a[0])
	{
		temp[i] = a[0][i + 1];
		i++;
	}
	free(a[0]);
	a[0] = malloc (sizeof(int) * len_a[0]);
	i = 0;
	while (i < len_a[0])
	{
		a[0][i] = temp[i];
		i++;
	}
	free(temp);
	len_b[0]++;
	ft_putstr("pb\n");
	return (1);
}

void	init_b(int**a, int **b, int *len_b)
{
	int	*temp;
	int	i;

	i = 0;
	temp = malloc (sizeof(int) * (len_b[0] + 1));
	while (i < len_b[0])
	{
		temp[i] = b[0][i];
		i++;
	}
	b[0][0] = a[0][0];
	i = 0;
	while (i < len_b[0])
	{
		b[0][i + 1] = temp[i];
		i++;
	}
	free (temp);
}

int	pa(int **a, int **b, int *len_b, int *len_a)
{
	int	*temp;
	int	i;

	i = 0;
	temp = init_temp(a, b, len_b, len_a);
	free(a[0]);
	len_a[0]++;
	a[0] = malloc (sizeof(int) * len_a[0]);
	i = 0;
	while (i < len_a[0])
	{
		a[0][i] = temp[i];
		i++;
	}
	free(temp);
	len_b[0]--;
	ft_putstr("pa\n");
	return (1);
}

int	*init_temp(int**a, int **b, int *len_b, int *len_a)
{
	int	*temp;
	int	i;

	i = 0;
	temp = malloc (sizeof(int) * (len_a[0] + 1));
	temp[i] = b[0][0];
	if (len_b[0] > 0)
	{
		while (i < len_b[0])
		{
			b[0][i] = b[0][i + 1];
			i++;
		}
	}
	i = 0;
	while (i < len_a[0])
	{
		temp[i + 1] = a[0][i];
		i++;
	}
	return (temp);
}
