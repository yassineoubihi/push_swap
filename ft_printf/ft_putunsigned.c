/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:47:12 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/09 08:59:50 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_putunsigned(unsigned int n, int *b)
{
	if (n < 10)
		ft_putchar_c(n + '0', b);
	else
	{
		ft_putunsigned(n / 10, b);
		ft_putunsigned(n % 10, b);
	}
}
