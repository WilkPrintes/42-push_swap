/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:21:56 by wprintes          #+#    #+#             */
/*   Updated: 2022/04/14 01:35:19 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		validations(char *argv[], int argc);
int		low_sort(int *a, int len_a);

int	main(int argc, char *argv[])
{
	int	*a;
	int	len_a;

	if (argc > 1)
	{
		if (validations(argv, argc) == 1)
			return (0);
		a = char_to_int(argc, argv);
		if (a == NULL)
			return (error(0));
		len_a = argc - 1;
		if (right_order(a, argc - 1, 0) == 0)
		{
			free(a);
			return (0);
		}
		if (len_a <= 5)
		{
			low_sort(a, len_a);
			return (0);
		}
		marge_sort(a, len_a);
	}
	else
		return (0);
}

int	validations(char *argv[], int argc)
{
	int	len;
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		while (index < len)
		{
			if (ft_isdigit(argv[i][index]) == 0)
			{
				ft_putstr("Error\n");
				exit (1);
			}
			index++;
		}
		index = 0;
		i++;
	}
	return (0);
}

int	low_sort(int *a, int len_a)
{
	int	*b;
	int	len_b;

	len_b = 0;
	b = malloc (sizeof(int) * len_a);
	moviments(a, b, len_a, len_b);
	free(b);
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
