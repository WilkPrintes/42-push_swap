/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:51:04 by wprintes          #+#    #+#             */
/*   Updated: 2022/03/25 23:51:17 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int right_order(int *a, int len_a, int len_b)
{
    int i;

    i = 0;
    if (len_b != 0)
        return (1);
    while ((i + 1) < len_a)
    {
        if(a[i] > a[i + 1])
            return (1);
        i++;
    }
    return (0);
}

int *char_to_int(int argc, char **argv)
{
    int i;
    int *a;

    i = 0;
    a = malloc (sizeof(int) * (argc - 1));
    while ((i + 1) < argc)
    {
        a[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    return (a);
}

size_t    my_sqrt(int number)
{
    size_t    i;

    i = 0;
    while (i * i <= (size_t)number)
    {
        if (i * i == (size_t)number)
        {
            return (i);
        }
        i++;
    }
    return (i - 1);
}