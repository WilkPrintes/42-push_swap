/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:09:24 by wprintes          #+#    #+#             */
/*   Updated: 2022/04/14 01:50:42 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(int type)
{
	ft_putstr("Error\n");
	return (type);
}

void	moviments(int *a, int *b, int len_a, int len_b)
{
	int	mov;
	int	mov_temp;

	mov = 0;
	while (right_order(a, len_a, len_b) != 0)
	{
		if (a[1] < a[0])
			mov = mov + sa(&a);
		else if (a[len_a - 1] < a[0])
			mov = mov + rra(&a, len_a, 0);
		else if (len_b == 0)
		{
			pb(&a, &b, &len_b, &len_a);
			mov_temp = mov;
		}
		else if (len_b != 0 && mov_temp != mov)
			pa(&a, &b, &len_b, &len_a);
		else if (mov > mov_temp && len_b > 0)
			pa(&a, &b, &len_b, &len_a);
		else
			pb(&a, &b, &len_b, &len_a);
	}
	free(a);
}
