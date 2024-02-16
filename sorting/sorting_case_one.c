/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_case_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 00:41:22 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/16 11:33:31 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_case_one(t_data	**stack_a)
{
	if ((*stack_a)->num < ((*stack_a)->next)->num && ((*stack_a)->next)->num < (((*stack_a)->next)->next)->num)
		return ;
	else if (((*stack_a)->num > ((*stack_a)->next)->num) &&
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
		rra(stack_a);
	else if ((*stack_a)->num < ((*stack_a)->next)->num &&
		((*stack_a)->next)->num > (((*stack_a)->next)->next)->num)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else
		ra(stack_a);
}

void	sort_case_two(t_data	**stack_a, t_data	**stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_case_one(stack_a);
	if ((*stack_b)->num > ((*stack_a)->next)->num)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
		pa(stack_a, stack_b);
	}
	else
	{
		sb(stack_b);
		pa(stack_a, stack_b);
		ra(stack_a);
		pa(stack_a, stack_b);
	}
}
