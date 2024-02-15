/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:48:20 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/09 08:59:34 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_putnbr_adress(unsigned long nb, int *b, char *str)
{
	if (nb < 16)
		ft_putchar_c(str[nb], b);
	else
	{
		ft_putnbr_adress(nb / 16, b, str);
		ft_putnbr_adress(nb % 16, b, str);
	}
}

void	ft_putaddres(void *str, int *b)
{
	unsigned long	add;

	add = (unsigned long)str;
	ft_putstr("0x", b);
	ft_putnbr_adress(add, b, "0123456789abcdef");
}
