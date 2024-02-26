/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:58:17 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/26 16:48:04 by youbihi          ###   ########.fr       */
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
	int i;

	i = 0;
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

void	algo_step_2(t_data	**stack_a, t_data	**stack_b)
{
	sort_3(stack_a);
	while (stack_size(stack_b) > 0)
	{
		if (((*stack_a)->index - 1) == (*stack_b)->index)
			pa(stack_a, stack_b);
		else
			rb(stack_b);
	}

	t_data *temp;

	temp = *stack_a;
	while (temp != NULL)
	{
		printf("num = %d\n",temp->num);
		temp = temp->next;
	}
}

void	main_algo(t_data	**stack_a, t_data	**stack_b)
{
	algo_step_1(stack_a, stack_b);
	algo_step_2(stack_a, stack_b);
}
