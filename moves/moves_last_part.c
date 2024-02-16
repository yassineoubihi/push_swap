/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_last_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 00:49:16 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/16 00:50:14 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*rrr : rra and rrb at the same time.*/
void	rrr(t_data	**stack_a, t_data	**stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
