/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_case_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 00:41:22 by youbihi           #+#    #+#             */
/*   Updated: 2024/03/26 20:29:44 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_data	**stack_a)
{
	if (check_sorted(stack_a) == 0)
		return ;
	else if (check_tow_conditions(stack_a) == 1)
		return ;
	else if ((*stack_a)->index > ((*stack_a)->next)->index && \
	((*stack_a)->next)->index < (((*stack_a)->next)->next)->index && \
	(*stack_a)->index > (((*stack_a)->next)->next)->index)
		ra(stack_a);
	else if ((*stack_a)->index < ((*stack_a)->next)->index && \
	((*stack_a)->next)->index > (((*stack_a)->next)->next)->index && \
	(*stack_a)->index < (((*stack_a)->next)->next)->index)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else
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

void	push_to_b_sort_5(t_data	**stack_a, t_data	**stack_b)
{
	if ((get_position(0, stack_a) >= stack_size(stack_a) / 2) == 1)
		while ((*stack_a)->index != 0)
			ra(stack_a);
	else
		while ((*stack_a)->index != 0)
			rra(stack_a);
	pb(stack_a, stack_b);
	if ((get_position(1, stack_a) >= stack_size(stack_a) / 2) == 1)
		while ((*stack_a)->index != 1)
			ra(stack_a);
	else
		while ((*stack_a)->index != 1)
			rra(stack_a);
	pb(stack_a, stack_b);
}

void	sort_5(t_data	**stack_a, t_data	**stack_b)
{
	t_data	*head_a;

	head_a = *stack_a;
	push_to_b_sort_5(stack_a, stack_b);
	sort_rest(stack_a, stack_b);
}

void	sort_four_and_five(t_data	**stack_a, t_data	**stack_b, int c)
{
	int	b;

	b = 0;
	if (c == 4)
		sort_4(stack_a, stack_b);
	else if (c == 5)
	{
		b = check_worst_case(stack_a);
		if (b == 1)
		{
			pb(stack_a, stack_b);
			pb(stack_a, stack_b);
			sort_3(stack_a);
			pa(stack_a, stack_b);
			ra(stack_a);
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else
			sort_5(stack_a, stack_b);
	}
}
