/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_case_one_help.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:04:35 by youbihi           #+#    #+#             */
/*   Updated: 2024/03/26 21:43:16 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_2(t_data	**stack_a)
{
	sa(stack_a);
}

int	check_sorted(t_data	**stack_a)
{
	if (((*stack_a)->index < ((*stack_a)->next)->index) && \
		((((*stack_a)->next)->index) < (((*stack_a)->next)->next)->index) && \
		((*stack_a)->index < (((*stack_a)->next)->next)->index))
		return (0);
	return (1);
}

int	check_tow_conditions(t_data	**stack_a)
{
	if ((*stack_a)->index > ((*stack_a)->next)->index && \
		((*stack_a)->next)->index < (((*stack_a)->next)->next)->index && \
		(*stack_a)->index < (((*stack_a)->next)->next)->index)
	{
		sa(stack_a);
		return (1);
	}
	else if ((*stack_a)->index > ((*stack_a)->next)->index && \
	((*stack_a)->next)->index > (((*stack_a)->next)->next)->index && \
	(*stack_a)->index > (((*stack_a)->next)->next)->index)
	{
		sa(stack_a);
		rra(stack_a);
		return (1);
	}
	return (0);
}

int	check_worst_case(t_data	**stack_a)
{
	if (((*stack_a)->index == 4) && (((*stack_a)->next)->index == 3) && \
		((((*stack_a)->next)->next)->index == 2) && \
		(((((*stack_a)->next)->next)->next)->index == 1) && \
		((((((*stack_a)->next)->next)->next)->next)->index == 0))
		return (1);
	return (0);
}
