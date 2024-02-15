/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:19:33 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/09 08:59:40 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_putnbr_hex_upp(unsigned long nb, int *b, char *str)
{
	if (nb < 16)
		ft_putchar_c(str[nb], b);
	else
	{
		ft_putnbr_hex_upp(nb / 16, b, str);
		ft_putnbr_hex_upp(nb % 16, b, str);
	}
}

void	ft_puthex_upp(unsigned int str, int *b)
{
	unsigned long	add;

	add = (unsigned long)str;
	ft_putnbr_hex_upp(add, b, "0123456789ABCDEF");
}
