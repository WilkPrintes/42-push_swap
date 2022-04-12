/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:21:56 by wprintes          #+#    #+#             */
/*   Updated: 2022/04/12 01:09:19 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	*a;
	int	len_a;

	if (argc > 1)
	{		
		a = char_to_int(argc, argv);
		len_a = argc - 1;
		if (right_order(a, argc - 1, 0) == 0)
		{
			free(a);
			return (0);
		}
		marge_sort(a, len_a);
	}
	else
		return (0);
}

void	marge_sort(int *a, int len_a)
{
	int	*b;
	int	len_b;

	b = malloc(sizeof(int) * len_a);
	len_b = 0;
	push_b(&a, &len_a, &b, &len_b);
	push_a(a, len_a, b, len_b);
	free(b);
}
