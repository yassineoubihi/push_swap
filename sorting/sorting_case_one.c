/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_case_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 00:41:22 by youbihi           #+#    #+#             */
/*   Updated: 2024/03/14 01:31:15 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_2(t_data	**stack_a)
{
	sa(stack_a);
}

void	sort_3(t_data	**stack_a)
{
	if (check_1(stack_a) == 0)
		return ;
	if ((*stack_a)->num < ((*stack_a)->next)->num && \
		((*stack_a)->next)->num < (((*stack_a)->next)->next)->num)
		return ;
	else if ((*stack_a)->num < ((*stack_a)->next)->num && \
		((*stack_a)->next)->num > (((*stack_a)->next)->next)->num)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (((*stack_a)->num < ((*stack_a)->next)->num) && \
		(((*stack_a)->next)->num > (((*stack_a)->next)->next)->num) && \
		((*stack_a)->num > (((*stack_a)->next)->next)->num))
		rra(stack_a);
}

void	sort_4(t_data	**stack_a, t_data	**stack_b)
{
	t_data	*head_a;

	head_a = *stack_a;
	while (head_a != NULL)
	{
		if (head_a->index == 0)
		{
			index_is_zero(stack_a, stack_b, head_a);
			break ;
		}
		head_a = head_a->next;
	}
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_data	**stack_a, t_data	**stack_b)
{
	t_data	*head_a;

	head_a = *stack_a;
	while (head_a != NULL)
	{
		if (head_a->index == 0)
		{
			index_is_zero(stack_a, stack_b, head_a);
			break ;
		}
		head_a = head_a->next;
	}
	change_positions(stack_a);
	stack_size(stack_a);
	head_a = *stack_a;
	while (head_a != NULL)
	{
		if (head_a->index == 1)
		{
			index_is_one(stack_a, stack_b, head_a);
			break ;
		}
		head_a = head_a->next;
	}
	sort_rest(stack_a, stack_b);
}

void	sort_four_and_five(t_data	**stack_a, t_data	**stack_b, int c)
{
	if (c == 4)
		sort_4(stack_a, stack_b);
	else if (c == 5)
		sort_5(stack_a, stack_b);
}
