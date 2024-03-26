/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:13:53 by youbihi           #+#    #+#             */
/*   Updated: 2024/03/26 20:29:58 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check(const char *str, va_list args, int index, int *c)
{
	if (str[index] == 'c')
		ft_putchar_c(va_arg(args, int), c);
	else if (str[index] == 's')
		ft_putstr(va_arg(args, char *), c);
	else if (str[index] == 'd' || str[index] == 'i')
		ft_putnbr(va_arg(args, int), c);
	else if (str[index] == 'u')
		ft_putunsigned(va_arg(args, int), c);
	else if (str[index] == 'p')
		ft_putaddres(va_arg(args, void *), c);
	else if (str[index] == 'x')
		ft_puthex(va_arg(args, unsigned int), c);
	else if (str[index] == 'X')
		ft_puthex_upp(va_arg(args, unsigned int), c);
	else
		ft_putchar_c(str[index], c);
}

int	ft_printf(const char	*str, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		*c;

	va_start (args, str);
	i = 0;
	count = 0;
	c = &count;
	while (str[i])
	{
		while (str[i] != '%' && str[i])
			ft_putchar_c(str[i++], c);
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				break ;
			check(str, args, i, c);
			i++;
		}
	}
	va_end(args);
	return (count);
}
