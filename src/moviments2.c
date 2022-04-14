/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:57:28 by wprintes          #+#    #+#             */
/*   Updated: 2022/04/14 01:39:17 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(int **a, int len_a)
{
	int	i;
	int	init;
	int	*temp;

	i = 0;
	init = a[0][len_a - 1];
	temp = malloc (sizeof(int) * len_a);
	while (i + 1 < len_a)
	{
		temp[i + 1] = a[0][i];
		i++;
	}
	temp[0] = init;
	i = 0;
	while (i < len_a)
	{
		a[0][i] = temp[i];
		i++;
	}
	free(temp);
	ft_putstr("rra\n");
}

int	rrb(int **b, int len_b)
{
	int	i;
	int	init;
	int	*temp;

	i = 0;
	init = b[0][len_b - 1];
	temp = malloc (sizeof(int) * len_b);
	while (i + 1 < len_b)
	{
		temp[i + 1] = b[0][i];
		i++;
	}
	temp[0] = init;
	i = 0;
	while (i < len_b)
	{
		b[0][i] = temp[i];
		i++;
	}
	free(temp);
	ft_putstr("rrb\n");
}

int	sb(int **b, int type)
{
	int	temp;

	temp = b[0][0];
	b[0][0] = b[0][1];
	b[0][1] = temp;
	if (type == 0)
		ft_putstr("sb\n");
	return (1);
}

int	ss(int **a, int **b)
{
	int	temp;

	temp = a[0][0];
	a[0][0] = a[0][1];
	a[0][1] = temp;
	temp = b[0][0];
	b[0][0] = b[0][1];
	b[0][1] = temp;
	ft_putstr("ss\n");
	return (1);
}
