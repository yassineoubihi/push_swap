/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:58:17 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/28 20:05:05 by youbihi          ###   ########.fr       */
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
	return (big);
}

int	get_button_value(t_data	**stack)
{
	int	buttom;

	while ((*stack) != NULL)
	{
		buttom = (*stack)->index;
		*stack = (*stack)->next;
	}
	return (buttom);
}
void	algo_step_1(t_data	**stack_a, t_data	**stack_b)
{
	int	lspv;
	int	pv1;
	int	pv2;

	lspv = -1;
	pv1 = stack_size(stack_a) / 3;
	pv2 = stack_size(stack_a) / 6;
	while (stack_size(stack_a) != 3)
	{
		if ((*stack_a)->index < pv1)
		{
			pb(stack_a, stack_b);
			if (stack_size(stack_b) > 1 &&
				(*stack_b)->index >= lspv && (*stack_b)->index <= pv2)
					rb(stack_b);	
		}
		else
			ra(stack_a);
		if (stack_size(stack_b) == pv1)
		{
			lspv = pv1;
			pv1 = pv1 + stack_size(stack_a) / 3;
			pv2 = pv2 + stack_size(stack_a) / 6;
		}
	}
}

int	get_position(int index, t_data	**stack_b)
{
	t_data	*temp;
	int		i;
	
	i = 0;
	temp = *stack_b;
	while(i <= stack_size(stack_b) / 2)
	{
		if (index == temp->index)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	algo_step_2(t_data	**stack_a, t_data	**stack_b)
{
	int	biggest_value;
	int	button_value;

	sort_3(stack_a);
	button_value = get_button_value(stack_a);
	biggest_value = get_button_value(stack_a);
	while (stack_size(stack_b))
	{
		if (button_value < (*stack_b)->index || button_value == biggest_value)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			button_value = get_button_value(stack_a);
		}
		else
		{
			while ((*stack_b)->index != (*stack_a)->index - 1)
				rb(stack_b);
		}
	}
}

void	main_algo(t_data	**stack_a, t_data	**stack_b)
{
	algo_step_1(stack_a, stack_b);
	algo_step_2(stack_a, stack_b);
}
