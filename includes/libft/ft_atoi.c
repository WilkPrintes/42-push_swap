/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 23:33:03 by wprintes          #+#    #+#             */
/*   Updated: 2022/04/13 00:11:35 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_var(long int *n1, long int *n2, int *n3);
static int	is_whitespace(const char c);

long int	ft_atoi(const char *str)
{
	long int		result;
	long int		increment;
	int				negative;

	init_var(&result, &increment, &negative);
	if (*str == '\0')
		return (0);
	while (is_whitespace(*str))
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			negative++;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		result = result * increment + *str - '0';
		str++;
	}
	if (negative == 1)
		result = result * -1;
	return (result);
}

static void	init_var(long int *n1, long int *n2, int *n3)
{
	*n1 = 0;
	*n2 = 10;
	*n3 = 0;
}

static int	is_whitespace(const char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}
