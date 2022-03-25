/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:46:40 by wprintes          #+#    #+#             */
/*   Updated: 2022/03/25 23:48:24 by wprintes         ###   ########.fr       */
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

int rra(int **a, int len)
{
    int *result;
    int temp;
    int i;

    i = 0;
    result = malloc(sizeof(int) * len);
    len--;
    result[i] = a[0][len];
    while(i < len)
    {
        result[i + 1] = a[0][i];
        i++;
    }
    while(i >= 0)
    {
        a[0][i] = result[i];
        i--;
    }
    free(result);
    printf("rra\n");
    return (1);
} 

int ra(int **a, int len)
{
    int temp;

    temp = a[0][len - 1];
    a[0][len - 1] = a[0][len - 2];
    a[0][len - 2] = temp;
    printf("ra\n");
    return (1);
}
