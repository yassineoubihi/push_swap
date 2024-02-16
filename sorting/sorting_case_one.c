/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_case_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 00:41:22 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/16 02:03:00 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_case_one(t_data	**stack_a)
{
	if (((*stack_a)->num > ((*stack_a)->next)->num) &&
		(((*stack_a)->next)->num < (((*stack_a)->next)->next)->num))
		sa(stack_a);
	else if ((*stack_a)->num > ((*stack_a)->next)->num &&
		(*stack_a)->num > (((*stack_a)->next)->next)->num)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (((*stack_a)->num < ((*stack_a)->next)->num) &&
		(((*stack_a)->next)->num > (((*stack_a)->next)->next)->num))
		ra(stack_a);
	else if ((*stack_a)->num < ((*stack_a)->next)->num &&
		((*stack_a)->next)->num > (((*stack_a)->next)->next)->num)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else
		rra(stack_a);
}
