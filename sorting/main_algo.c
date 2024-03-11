/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:58:17 by youbihi           #+#    #+#             */
/*   Updated: 2024/03/11 16:40:15 by youbihi          ###   ########.fr       */
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
	int		big;
	t_data	*temp;

	temp = *stack;
	big = temp->index;
	while (temp != NULL)
	{
		if (temp->index > big)
			big = temp->index;
		temp = temp->next;
	}
	return (big);
}

int	get_button_value(t_data	**stack)
{
	int		buttom;
	t_data	*temp;

	temp = *stack;
	while (temp != NULL)
	{
		buttom = temp->index;
		temp = temp->next;
	}
	return (buttom);
}

void fix_stack(t_data	**stack_b)
{
	while (*stack_b)
	{
		printf("%p\n",*stack_b);
		*stack_b = (*stack_b)->next;
	}
	*stack_b = NULL;
	printf("%p\n",*stack_b);
}

void	algo_step_1(t_data	**stack_a, t_data	**stack_b)
{
	int	lspv;
	int	pv1;
	int	pv2;
	int	flag;

	lspv = -1;
	flag = 0;
	pv1 = stack_size(stack_a) / 3;
	pv2 = stack_size(stack_a) / 6;
	while (stack_size(stack_a) != 3)
	{
		if ((*stack_a)->index < pv1)
		{
			pb(stack_a, stack_b);
			if (flag == 0)
				(*stack_b)->next = NULL;
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
		flag++;
	}
}

int	get_position(int index, t_data	**stack_b)
{
	t_data	*temp;
	int		i;
	
	i = 0;
	temp = *stack_b;
	while (temp != NULL && temp->index != index)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	stack_sorted(t_data	**stack_a)
{
	t_data	*temp;

	temp = *stack_a;
	while(temp->next != NULL)
	{
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	algo_step_2(t_data	**stack_a, t_data	**stack_b)
{
	int	biggest_value;
	int	button_value;
	
	biggest_value = get_button_value(stack_a);
	button_value = get_button_value(stack_a);
	while (*stack_b)
	{
		while ((*stack_b) != NULL && (*stack_b)->index + 1 != (*stack_a)->index)
		{

			if (get_position((*stack_a)->index , stack_b) > stack_size(stack_b) / 2)
			{
				if ((button_value < (*stack_b)->index) || button_value == biggest_value)
				{
					pa(stack_a, stack_b);
					ra(stack_a);
					button_value = get_button_value(stack_a);
				}
				else if (*stack_b)
					rrb(stack_b);
			}
			else
			{
				if ((button_value < (*stack_b)->index) || button_value == biggest_value)
				{
					pa(stack_a, stack_b);
					ra(stack_a);
					button_value = get_button_value(stack_a);
				}
				else if (*stack_b)
					rb(stack_b);
			}
		}
		while (*stack_b && (*stack_b)->index == (*stack_a)->index - 1)
			pa(stack_a, stack_b);
		if ((*stack_a)->index - 1 == button_value)
		{
			while (button_value == (*stack_a)->index - 1)
			{
				rra(stack_a);
				button_value = get_button_value(stack_a);
			}
		}
		if (stack_sorted(stack_a) == 1 && *stack_b == NULL)
			break ;
	}
}

void	main_algo(t_data	**stack_a, t_data	**stack_b)
{
	algo_step_1(stack_a, stack_b);
	sort_3(stack_a);
	algo_step_2(stack_a, stack_b);
}
