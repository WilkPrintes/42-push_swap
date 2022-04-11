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
    int *values;
    int i;
    int temp;
    int max;
    int places;

    len_a = argc - 1;
    len_b = 0;
    i = 0;
    places = my_sqrt(len_a);
    b = malloc (sizeof(int) * (argc - 1));
    while (len_a > 0)
    {
        values = sort(a, b, len_a, len_b);
        temp = len_a;
        while (i < temp)
        {
            if (exist(values, places, a[0]) != 0)
                pb(&a, &b, &len_b, &len_a);
            else
                ra(&a, len_a);
            i++;
        }
        i = 0;
    }
    while (len_b > 0)
    {
        max = find_max(b, len_b);
        if (max == 0)
            pa(&a, &b, &len_b, &len_a);
        else if (max > len_b / 2)
        {
            while (find_max(b, len_b) != 0)
                rrb(&b, len_b);
        }
        else
        {
            while (find_max(b, len_b) != 0)
                rb(&b, len_b);
        }
    }
}

int find_min(int *a, int len_a, int *values, int places)
{
    int i;
    int index;

    i = 0;
    index = 0;
    while (i < len_a)
    {
        while(index < places)
        {
            if (a[i] == values[index])
                return(i);
            index++;
        }
        index = 0;
        i++;
    }
}

int find_max(int *b, int len_b)
{
    int i;
    int temp;
    int result;

    i = 0;
    result = 0;
    temp = b[i];
    while (i < len_b)
    {
        if (b[i] > temp)
        {
            temp = b[i];
            result = i;        
        }
        i++;
    }
    return (result);
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

int *sort(int *a, int *b, int len_a, int len_b)
{
    int subs;
    int *values;
    int index;
    int i;
    int temp;
    int temp_temp;

    i = 0;
    index = 0;
    subs = (int) my_sqrt(len_a);
    values = malloc (subs * sizeof(int));
    while (i < subs)
    {
        values[i] = a[i];
        i++;
    }
    i = 0;
    while(i < len_a)
    {
        while (index < subs)
        {
            if (values[index] > a[i])
            {
                if (exist(values, subs, a[i]) == 0)
                {
                    temp = values[index];
                    values[index] = a[i];
                    while(index < subs)
                    {
                        if(values[index] > temp)
                        {
                            temp_temp = values[index];
                            values[index] = temp;
                            temp = temp_temp;
                        }
                        index++;
                    }
                }
            }
            index++;
        }
        index = 0;
        i++;
    }
    return(values);
}

int exist(int *values, int len_value, int value)
{
    int i;

    i = 0;
    while (i < len_value)
    {
        if (values[i] == value)
            return (1);
        i++;
    }
    return(0);
}