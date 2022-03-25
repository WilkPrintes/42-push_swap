/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:21:56 by wprintes          #+#    #+#             */
/*   Updated: 2022/03/25 23:51:40 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *low_sort(int argc, int *a);
void print_int(int *a, int len_a);

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
        if (a[1] < a[0])
            mov = mov + sa(&a);
        else if (a[len_a - 1] < a[0])
            mov = mov + rra(&a, len_a);
        else if (len_b == 0)
        {
            pb(&a, &b, &len_b, &len_a);
            mov_temp = mov;
        }
        else if (len_b != 0 && mov_temp != mov)
            pa(&a, &b, &len_b, &len_a);
        else if (mov > mov_temp && len_b > 0)
            pa(&a, &b, &len_b, &len_a);
        else
            pb(&a, &b, &len_b, &len_a);
    }
}
