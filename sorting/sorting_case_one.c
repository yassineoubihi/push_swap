/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_case_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 00:41:22 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/17 12:01:13 by youbihi          ###   ########.fr       */
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

int	get_index(t_data	**stack_a)
{
	int b;
	int	index;
	int	min;

	index = 1;
	min = 0;
	b = (*stack_a)->num;
	(*stack_a) = (*stack_a)->next;
	while (*stack_a != NULL)
	{
		if (b > (*stack_a)->num)
		{
			b = (*stack_a)->num;
			min = index;
		}
		(*stack_a) = (*stack_a)->next;
		index++;
	}
	return (min);
}

void	sort_case_two(t_data	**stack_a, t_data	**stack_b, int list_size)
{
	int	i;
	int	loop;

	loop = 2;
	while (loop)
	{
		i = get_index(stack_a);
		if (i <= list_size / 2)
		{
			ra(stack_a);
			ra(stack_a);
			pb(stack_a, stack_b);
		}
	}
	sort_case_one(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
