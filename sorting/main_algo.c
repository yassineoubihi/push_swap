/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:58:17 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/21 18:25:20 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_size(t_data	**stack)
{
	t_data	*temp_head;
	int		i;

	i = 0;
	temp_head = *stack;
	while (temp_head != NULL)
	{
		i++;
		temp_head = temp_head->next;
	}
	return (i);
}

int	get_big_value(t_data	**stack)
{
	int	big;
	big = (*stack)->index;
	while (*stack != NULL)
	{
		if ((*stack)->index > big)
			big = (*stack)->index;
		(*stack) = (*stack)->next;
	}
}

int	get_button_value(t_data	**stack)
{
	int	buttom;

	while ((*stack) != NULL)
	{
		buttom = (*stack)->index;
		*stack = (*stack)->next;
	}
}

void	main_algo(t_data	**stack_a, t_data	**stack_b)
{
	int		lastp1;
	int		p1;
	int		p2;
	int		big_value;
	int		buttom_value;
	t_data	*head_a;

	head_a = *stack_a;
	lastp1 = -1;
	p1 = stack_size(stack_a) / 3;
	p2 = stack_size(stack_a) / 6;
	while (stack_size(stack_a) > 3)
	{
		while (stack_size(stack_b) < p1)
		{
			if (head_a->index < p1)
				pb(stack_a,stack_b);
			else
				ra(stack_a);
		}
		lastp1 = p1;
		p1 += stack_size(stack_a) / 3;
		p2 = stack_size(stack_a) / 6 + lastp1;
	}
	sort_3(stack_a);
	big_value = get_big_value(stack_a);
	buttom_value = get_button_value(stack_a);
	
}
