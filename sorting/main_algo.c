/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:58:17 by youbihi           #+#    #+#             */
/*   Updated: 2024/03/26 21:43:06 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handel_case(t_data **stack_a, t_data **stack_b,
	int *button_value, int biggest_value)
{
	while ((*stack_a)->index - 1 != (*stack_b)->index)
	{
		if ((*button_value < (*stack_b)->index) || \
			*button_value == biggest_value)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			*button_value = get_button_value(stack_a);
		}
		else
			rrb(stack_b);
	}
	pa(stack_a, stack_b);
}

void	handel_case_2(t_data **stack_a, t_data **stack_b,
	int *button_value, int biggest_value)
{
	while ((*stack_a)->index - 1 != (*stack_b)->index)
	{
		if ((*button_value < (*stack_b)->index) || \
			*button_value == biggest_value)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			*button_value = get_button_value(stack_a);
		}
		else
			rb(stack_b);
	}
	pa(stack_a, stack_b);
}

void	algo_step_2(t_data	**stack_a, t_data	**stack_b)
{
	int	biggest_value;
	int	button_value;
	int	pos;

	pos = 0;
	biggest_value = get_button_value(stack_a);
	button_value = get_button_value(stack_a);
	while (*stack_b)
	{
		while ((*stack_b) && (*stack_b)->index == (*stack_a)->index - 1)
			pa(stack_a, stack_b);
		while ((*stack_a)->index == button_value + 1)
		{
			rra(stack_a);
			button_value = get_button_value(stack_a);
		}
		pos = (stack_size(stack_b) / 2) - \
			(get_position((*stack_a)->index - 1, stack_b));
		if (pos < 0 && (*stack_b))
			handel_case(stack_a, stack_b, &button_value, biggest_value);
		else if (pos >= 0 && (*stack_b))
			handel_case_2(stack_a, stack_b, &button_value, biggest_value);
	}
}

void	main_algo(t_data	**stack_a, t_data	**stack_b)
{
	algo_step_1(stack_a, stack_b);
	sort_3(stack_a);
	algo_step_2(stack_a, stack_b);
	while (get_button_value(stack_a) == (*stack_a)->index - 1)
		rra(stack_a);
}
