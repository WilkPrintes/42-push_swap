/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:30:06 by wprintes          #+#    #+#             */
/*   Updated: 2022/03/25 23:51:53 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

int sa(int **a);
int rra(int **a, int len);
int ra(int **a, int len);
int pb(int **a, int **b, int *len_b, int *len_a);
int pa(int **a, int **b, int *len_b, int *len_a);
int *char_to_int(int argc, char **argv);
int right_order(int *a, int len_a, int len_b);

#endif