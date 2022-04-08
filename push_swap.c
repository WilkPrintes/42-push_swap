/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:21:56 by wprintes          #+#    #+#             */
/*   Updated: 2022/04/08 16:23:24 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        int *a;
        int *result;
        
        a = char_to_int(argc, argv);
        if (right_order(a, argc - 1, 0) == 0)
        {
            free(a);
            return (0);
        }
        low_sort(argc, a);
    }
    else
        return (0);
}

void print_int(int *a, int len_a)
{
    int i;

    i = 0;
    while(i < len_a)
    {
        printf("%d | ", a[i]);
        i++;
    }
    printf("\n");
}

int *low_sort(int argc, int *a)
{
    int *b;
    int len_b;
    int len_a;
    int mov;
    int mov_temp;
    
    len_a = argc - 1;
    len_b = 0;
    mov = 0;
    b = malloc (sizeof(int) * (argc - 1));
    while(right_order(a, len_a, len_b) != 0)
    {
        if (len_b > 0 && right_max_b(b, len_b) != -1)
            quick_sort_b(&a, &b, &len_a, &len_b);
        else if (len_a > 0 && right_max_a(a, len_a) != -1)
            quick_sort_a(&a, &b, &len_a, &len_b);
        else if (right_max_a(a, len_a) == -1)
        {
            if (len_b > 0 && right_max_b(b, len_b) == -1)
            {
                while(len_b > 0)
                    pa(&a, &b, &len_b, &len_a);
            }
        }  
    }
}

int *find_index(int *a, int len_a)
{
    int *indexs;
    int i;
    int *temp;
    int min;
    int index;

    i = 0;
    indexs = malloc (sizeof(int) * len_a);
    temp = malloc (sizeof(int) * len_a);
    while(i < len_a)
    {
        temp[i] = a[i];
        i++;
    }
    i = 0;
    while(i < len_a)
    {
        if (temp[i] < min)
        {
            min = temp[i];
            index = i;
        }
        i++;
    }
}