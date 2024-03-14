/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_case_one_help1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:23:23 by youbihi           #+#    #+#             */
/*   Updated: 2024/03/14 01:29:05 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_1(t_data **stack_a)
{
	if (((*stack_a)->num > (*stack_a)->next->num) && \
		((*stack_a)->num > (*stack_a)->next->next->num) && \
		((*stack_a)->next->num) < (*stack_a)->next->next->num)
	{
		ra(stack_a);
		return (1);
	}
	else if (((*stack_a)->num > ((*stack_a)->next)->num) && \
		(((*stack_a)->next)->num < (((*stack_a)->next)->next)->num) && \
		((*stack_a)->num < (((*stack_a)->next)->next)->num))
	{
		sa(stack_a);
		return (1);
	}
	else if ((*stack_a)->num > ((*stack_a)->next)->num && \
		(*stack_a)->num > (((*stack_a)->next)->next)->num)
	{
		sa(stack_a);
		rra(stack_a);
		return (1);
	}
	return (0);
}

void	ra_case(t_data	**stack_a, t_data	**stack_b, int c)
{
	while (c > 0)
	{
		ra(stack_a);
		c--;
	}
	pb(stack_a, stack_b);
}

void	rra_case(t_data	**stack_a, t_data	**stack_b, int c)
{
	while (c < (*stack_a)->stack_size)
	{
		rra(stack_a);
		c++;
	}
	pb(stack_a, stack_b);
}

void	change_positions(t_data	**stack_a)
{
	t_data	*head_stack_a;
	int		i;

	i = 0;
	head_stack_a = *stack_a;
	while (head_stack_a != NULL)
	{
		head_stack_a->position = i;
		i++;
		head_stack_a = head_stack_a->next;
	}
}

void	index_is_zero(t_data	**stack_a, t_data	**stack_b, t_data	*head_a)
{
	if (head_a->position <= 2)
		ra_case(stack_a, stack_b, head_a->position);
	else
		rra_case(stack_a, stack_b, head_a->position);
}
