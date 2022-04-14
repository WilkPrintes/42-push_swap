/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marge_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:20:07 by wprintes          #+#    #+#             */
/*   Updated: 2022/04/14 01:51:31 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_var(int *push, int *divs, int *len_a);

void	push_b(int **a, int *len_a, int **b, int *len_b)
{
	int	*values;
	int	divs;
	int	push;
	int	len_v;

	divs = my_sqrt(len_a[0]);
	len_v = init_var(&push, &divs, len_a);
	while (divs > 0)
	{
		values = find_min(a[0], len_a[0], len_v);
		while (push < len_v)
		{
			if (exist(values, len_v, a[0][0]) != 0)
				push = push + pb(a, b, len_b, len_a);
			else
				ra(a, len_a[0], 0);
		}
		free(values);
		divs--;
		push = 0;
	}
	while (len_a[0] != 0)
		pb(a, b, len_b, len_a);
}

int	init_var(int *push, int *divs, int *len_a)
{
	push[0] = 0;
	if (divs[0] > 10)
		divs[0] = 10;
	return (len_a[0] / divs[0]);
}

void	push_a(int *a, int len_a, int *b, int len_b)
{
	int	max;

	while (len_b > 0)
	{
		max = find_max(b, len_b);
		if (max == 0)
			pa(&a, &b, &len_b, &len_a);
		else if (max > len_b / 2)
		{
			while (find_max(b, len_b) != 0)
				rrb(&b, len_b, 0);
		}
		else
		{
			while (find_max(b, len_b) != 0)
				rb(&b, len_b, 0);
		}
	}
	free(a);
}

int	*find_min(int *a, int len_a, int divs)
{
	int	min;
	int	i;
	int	*found;
	int	f_len;

	f_len = 0;
	found = malloc (sizeof(int) * divs);
	init_found(&found, divs, a);
	i = 0;
	min = 2147483647;
	while (f_len < divs)
	{
		while (i < len_a)
		{
			if (a[i] < min && exist(found, divs, a[i]) == 0)
				min = a[i];
			i++;
		}
		i = 0;
		found[f_len] = min;
		min = 2147483647;
		f_len++;
	}
	return (found);
}

int	find_max(int *b, int len_b)
{
	int	i;
	int	temp;
	int	result;

	i = 0;
	result = 0;
	temp = b[i];
	while (i < len_b)
	{
		if (b[i] > temp)
		{
			temp = b[i];
			result = i;
		}
		i++;
	}
	return (result);
}
