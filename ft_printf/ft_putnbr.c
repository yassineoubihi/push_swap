/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:23:16 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/09 09:00:01 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_putnbr(int nb, int *b)
{
	unsigned int	n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar_c('-', b);
		n *= -1;
	}
	if (n < 10)
		ft_putchar_c(n + '0', b);
	else
	{
		ft_putnbr(n / 10, b);
		ft_putnbr(n % 10, b);
	}
}
