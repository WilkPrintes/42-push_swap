/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:46:40 by wprintes          #+#    #+#             */
/*   Updated: 2022/03/30 19:12:50 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sa(int **a)
{
    int temp;

    temp = a[0][0];
    a[0][0] = a[0][1];
    a[0][1] = temp;
    printf("sa\n");
    return (1);
}

int pb(int **a, int **b, int *len_b, int *len_a)
{
    int *temp;
    int i;

    i = 0;
    temp = malloc (sizeof(int) * (len_b[0] + 1));
    while (i < len_b[0])
    {
        temp[i] = b[0][i];
        i++;
    }
    b[0][0] = a[0][0];
    i = 0;
    while (i < len_b[0])
    {
        b[0][i + 1] = temp[i];
        i++;
    }
    free(temp);
    i = 0;
    len_a[0]--;
    temp = malloc (sizeof(int) * (len_a[0]));
    while (i < len_a[0])
    {
        temp[i] = a[0][i + 1];
        i++;
    }
    free(a[0]);
    a[0] = malloc (sizeof(int) * len_a[0]);
    i = 0;
    while (i < len_a[0])
    {
        a[0][i] = temp[i];
        i++;
    }
    len_b[0]++;
    printf("pb\n");
    return (1);
}

int pa(int **a, int **b, int *len_b, int *len_a)
{
    int *temp;
    int i;

    i = 0;
    temp = malloc (sizeof(int) * (len_a[0] + 1));
    temp[i] = b[0][0];
    if (len_b[0] > 0)
    {
        while(i < len_b[0])
        {
            b[0][i] = b[0][i + 1];
            i++;
        }
    }
    i = 0;
    while (i < len_a[0])
    {
        temp[i + 1] = a[0][i];
        i++;
    }
    free(a[0]);
    len_a[0]++;
    a[0] = malloc (sizeof(int) * len_a[0]);
    i = 0;
    while (i < len_a[0])
    {
        a[0][i] = temp[i];
        i++;
    }
    len_b[0]--;
    printf("pa\n");
    return (1);
}

int ra(int **a, int len_a)
{
    int i;
    int init;
    int *temp;

    i = 0;
    init = a[0][0];
    temp = malloc (sizeof(int) * len_a);
    while(i < len_a - 1)
    {
        temp[i] = a[0][i + 1];
        i++;    
    }
    temp[i] = init;
    i = 0;
    while(i < len_a)
    {
        a[0][i] = temp[i];
        i++;    
    }
    free(temp);
    printf("ra\n");
}

int rb(int **b, int len_b)
{
    int i;
    int init;
    int *temp;

    i = 0;
    init = b[0][0];
    temp = malloc (sizeof(int) * len_b);
    while(i + 1 < len_b)
    {
        temp[i] = b[0][i + 1];
        i++;    
    }
    temp[i] = init;
    i = 0;
    while(i < len_b)
    {
        b[0][i] = temp[i];
        i++;    
    }
    free(temp);
    printf("rb\n");
}

int rra(int **a, int len_a)
{
    int i;
    int init;
    int *temp;

    i = 0;
    init = a[0][len_a - 1];
    temp = malloc (sizeof(int) * len_a);
    while(i + 1 < len_a)
    {
        temp[i + 1] = a[0][i];
        i++;    
    }
    temp[0] = init;
    i = 0;
    while(i < len_a)
    {
        a[0][i] = temp[i];
        i++;
    }
    free(temp);
    printf("rra\n");
}

int rrb(int **b, int len_b)
{
    int i;
    int init;
    int *temp;

    i = 0;
    init = b[0][len_b - 1];
    temp = malloc (sizeof(int) * len_b);
    while(i + 1 < len_b)
    {
        temp[i + 1] = b[0][i];
        i++;    
    }
    temp[0] = init;
    i = 0;
    while(i < len_b)
    {
        b[0][i] = temp[i];
        i++;
    }
    free(temp);
    printf("rrb\n");
}

int sb(int **b)
{
    int temp;

    temp = b[0][0];
    b[0][0] = b[0][1];
    b[0][1] = temp;
    printf("sb\n");
    return (1);
}

int ss(int **a, int **b)
{
    int temp;

    temp = a[0][0];
    a[0][0] = a[0][1];
    a[0][1] = temp;  
    temp = b[0][0];
    b[0][0] = b[0][1];
    b[0][1] = temp;
    printf("ss\n");
    return (1);
}