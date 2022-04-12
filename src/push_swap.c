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

void marge_sort(int *a, int len_a);
int *find_min(int *a, int len_a, int divs);
void push_b(int **a, int *len_a, int **b, int *len_b);
void push_a(int *a, int len_a, int *b, int len_b);
void init_found(int **found, int divs, int *a);
int exist(int *a, int len, int value);
int find_max(int *b, int len_b);

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        int *a;
        int len_a;
        
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

void marge_sort(int *a, int len_a)
{
    int *b;
    int len_b;

    b = malloc(sizeof(int) * len_a);
    len_b = 0;
    push_b(&a, &len_a, &b, &len_b);
    push_a(a, len_a, b, len_b);
}

void push_b(int **a, int *len_a, int **b, int *len_b)
{
    int i;
    int *values;
    int divs;
    int push;
    int len_v;

    push = 0;
    divs = my_sqrt(len_a[0]);
    if (divs > 10)
        divs = 10;
    i = 0;
    len_v = len_a[0] / divs;
    while (i < divs)
    {
        values = find_min(a[0], len_a[0], len_v);
        while (push < len_v)
        {
            if (exist(values, len_v, a[0][0]) != 0)
            {
                pb(a, b, len_b, len_a);
                push++;
            }
            else
                ra(a, len_a[0]);
        }
        i++;
        push = 0;
    }
    while (len_a[0] != 0)
        pb(a, b, len_b, len_a);
}

int *find_min(int *a, int len_a, int divs)
{
    int min;
    int i;
    int *found;
    int f_len;

    f_len = 0;
    found = malloc (sizeof(int) * divs);
    init_found(&found, divs, a);
    i = 0;
    min = 2147483647;
    while (f_len < divs)
    {
        while (i < len_a)
        {
            if (a[i] < min && exist(found, divs, a[i]) == 0)
                min = a[i];
            i++;
        }
        i = 0;
        found[f_len] = min;
        min = 2147483647;
        f_len++;
    }
    return (found);
}

void init_found(int **found, int divs, int *a)
{
    int i;

    i = 0;
    while (i < divs)
    {
        found[0][i] = 2147483647;
        i++;
    }
}

int exist(int *a, int len, int value)
{
    int i;

    i = 0;
    while(i < len)
    {
        if (a[i] == value)
            return (1);
        i++;
    }
    return(0);
}

void push_a(int *a, int len_a, int *b, int len_b)
{
    int max;

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