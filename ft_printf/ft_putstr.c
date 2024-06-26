/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:16:34 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/09 08:59:47 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_putstr(char *s, int *b)
{
	int	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		(*b) += 6;
	}
	else
	{
		while (s[i])
		{
			write (1, &s[i], 1);
			i++;
			(*b)++;
		}
	}
}
