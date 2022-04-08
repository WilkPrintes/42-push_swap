/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:46:05 by wprintes          #+#    #+#             */
/*   Updated: 2022/04/08 16:30:36 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void quick_sort_a(int **a, int **b, int *len_a, int *len_b)
{
    int pivot;
    int i;
    int temp;
    int index;

    temp = len_a[0];
    index = right_max_a(a[0], len_a[0]);
    pivot = a[0][index];
    i = 0;
    while (i < temp)
    {
        if (a[0][0] < pivot)
        {
            pb(a, b, len_b, len_a);
        }
        else if (a[0][0] > pivot)
        {
            ra(a, len_a[0]);
        }
        else
            break ;
        i++;
    }
    index = right_max_a(a[0], len_a[0]);
    if(index == 1)
        sa(a);
}

void quick_sort_b(int **a, int **b, int *len_a, int *len_b) 
{
    int pivot;
    int i;
    int temp;
    int index;

    i = 0;
    index = right_max_b(b[0], len_b[0]);
    pivot = b[0][index];
    temp = len_b[0];
    i = 0;
    while (i < temp)
    {
        if (b[0][0] > pivot)
        {
            pa(a, b, len_b, len_a);
        }
        else if (b[0][0] < pivot)
        {
            rb(b, len_b[0]);
        }
        else
            break ;
        i++;
    }
    index = right_max_b(b[0], len_b[0]);
    if (index == 1)
        sb(b);
}

int right_max_a(int *a, int len_a)
{
    int index;
    int i;

    index = len_a - 1;
    i = 0;
    while(index >= 0)
    {
        while(i <= index)
        {
            if (a[index] < a[index - i])
                return (index);
            i++;
        }
        i = 0;
        index--;
    }
    return(-1);
}

int right_max_b(int *b, int len_b)
{
    int index;
    int i;

    index = len_b - 1;
    i = 0;
    while(index >= 0)
    {
        while(i <= index)
        {
            if (b[index] > b[index - i])
                return (index);
            i++;
        }
        i = 0;
        index--;
    }
    return(-1);
}