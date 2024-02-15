/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:15:14 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/09 08:59:42 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_putnbr_hex(unsigned long int nb, int *b, char *str)
{
	if (nb < 16)
		ft_putchar_c(str[nb], b);
	else
	{
		ft_putnbr_hex(nb / 16, b, str);
		ft_putnbr_hex(nb % 16, b, str);
	}
}

void	ft_puthex(unsigned int str, int *b)
{
	unsigned long int	add;
	long int			add2;

	add = (unsigned long int)str;
	add2 = (long int)str;
	ft_putnbr_hex(add, b, "0123456789abcdef");
}
