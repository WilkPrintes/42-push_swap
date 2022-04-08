/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:30:06 by wprintes          #+#    #+#             */
/*   Updated: 2022/04/07 16:38:09 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

int sa(int **a);
int sb(int **b);
int ss(int **a, int **b);
int pb(int **a, int **b, int *len_b, int *len_a);
int pa(int **a, int **b, int *len_b, int *len_a);
int ra(int **a, int len_a);
int rb(int **b, int len_b);
int rra(int **a, int len_a);
int rrb(int **b, int len_b);
int right_order(int *a, int len_a, int len_b);
int *char_to_int(int argc, char **argv);
void quick_sort_a(int **a, int **b, int *len_a, int *len_b);
void quick_sort_b(int **a, int **b, int *len_a, int *len_b);
int *low_sort(int argc, int *a);
void print_int(int *a, int len_a);
int *find_index(int *a, int len_a);
int right_max_a(int *a, int len_a);
int right_max_b(int *b, int len_b);

#endif