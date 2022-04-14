/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:13:46 by wprintes          #+#    #+#             */
/*   Updated: 2022/04/14 01:14:15 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(int **a, int len_a)
{
	int	i;
	int	init;
	int	*temp;

	i = 0;
	init = a[0][0];
	temp = malloc (sizeof(int) * len_a);
	while (i < len_a - 1)
	{
		temp[i] = a[0][i + 1];
		i++;
	}
	temp[i] = init;
	i = 0;
	while (i < len_a)
	{
		a[0][i] = temp[i];
		i++;
	}
	free(temp);
	ft_putstr("ra\n");
}

int	rb(int **b, int len_b)
{
	int	i;
	int	init;
	int	*temp;

	i = 0;
	init = b[0][0];
	temp = malloc (sizeof(int) * len_b);
	while (i + 1 < len_b)
	{
		temp[i] = b[0][i + 1];
		i++;
	}
	temp[i] = init;
	i = 0;
	while (i < len_b)
	{
		b[0][i] = temp[i];
		i++;
	}
	free(temp);
	ft_putstr("rb\n");
}
