/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:30:06 by wprintes          #+#    #+#             */
/*   Updated: 2022/04/14 01:39:38 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "libft.h"

int		sa(int **a, int type);
int		sb(int **b, int type);
int		ss(int **a, int **b);
int		pb(int **a, int **b, int *len_b, int *len_a);
int		pa(int **a, int **b, int *len_b, int *len_a);
int		ra(int **a, int len_a);
int		rb(int **b, int len_b);
int		rra(int **a, int len_a);
int		rrb(int **b, int len_b);
int		*char_to_int(int argc, char **argv);
int		right_order(int *a, int len_a, int len_b);
int		exist(int *a, int len, int value);
int		find_max(int *b, int len_b);
int		*sort(int *a, int *b, int len_a, int len_b);
int		*find_min(int *a, int len_a, int divs);
void	marge_sort(int *a, int len_a);
void	push_b(int **a, int *len_a, int **b, int *len_b);
void	push_a(int *a, int len_a, int *b, int len_b);
void	init_found(int **found, int divs, int *a);
size_t	my_sqrt(int number);
void	moviments(int *a, int *b, int len_a, int len_b);
int		error(int type);
#endif