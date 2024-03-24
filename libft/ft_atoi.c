/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:13:17 by youbihi           #+#    #+#             */
/*   Updated: 2024/03/24 15:22:06 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../push_swap.h"
#include <stdio.h>

void	check_atoi(long res, int neg, const char	*s)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (s[i] == '0')
	{
		i++;
	}
	while (s[i])
	{
		i++;
		c++;
	}
	if (c > 12)
	{
		ft_printf("Error\n");
		exit (1);
	}
	if (res * neg > INT_MAX || res * neg < INT_MIN)
	{
		ft_printf("Error\n");
		exit (1);
	}
}

static int	func(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\r' || c == '\f');
}

static long	func0(const char	*s, int i, int neg)
{
	t_atoi_vars	vars;

	vars.res = 0;
	vars.digitnbr = 0;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		vars.digitnbr++;
		if (vars.digitnbr == 20)
		{
			if (neg == -1)
				return (0);
			else
				return (-1);
		}
		vars.res = (vars.res * 10) + (s[i++] - '0');
	}
	if (vars.res >= LLONG_MAX)
	{
		if (neg == -1)
			return (0);
		else
			return (-1);
	}
	check_atoi(vars.res, neg, s);
	return (((long) vars.res) * neg);
}

long	ft_atoi(const char *s)
{
	int	i;
	int	neg;

	i = 0;
	neg = 1;
	while (s[i] && (s[i] == ' ' || func(s[i])))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			neg *= -1;
		i++;
	}
	while (s[i] && s[i] == '0')
		i++;
	return (func0(s, i, neg));
}
