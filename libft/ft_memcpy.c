/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:01:39 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/13 18:17:11 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../push_swap.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	size_t	i;

	if (!source && !destination)
		return (0);
	if (num == 0)
		return (destination);
	i = 0;
	while (i < num)
	{
		*(char *)destination = *(char *)source;
		i++;
		destination++;
		source++;
	}
	return (destination - i);
}
