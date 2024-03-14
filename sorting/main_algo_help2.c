/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo_help2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:58:10 by youbihi           #+#    #+#             */
/*   Updated: 2024/03/14 00:59:10 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo_step_1(t_data	**stack_a, t_data	**stack_b)
{
	t_algo_first	vars;

	vars.lspv = -1;
	vars.flag = 0;
	vars.pv1 = stack_size(stack_a) / 3;
	vars.pv2 = stack_size(stack_a) / 6;
	while (stack_size(stack_a) != 3)
	{
		if ((*stack_a)->index < vars.pv1)
		{
			pb(stack_a, stack_b);
			if (vars.flag == 0)
				(*stack_b)->next = NULL;
			if (stack_size(stack_b) > 1 && \
				(*stack_b)->index >= vars.lspv && (*stack_b)->index <= vars.pv2)
				rb(stack_b);
		}
		else
			ra(stack_a);
		if (stack_size(stack_b) == vars.pv1)
			update_values(&vars.lspv, &vars.pv1, &vars.pv2, stack_a);
		vars.flag++;
	}
}

int	get_position(int index, t_data	**stack_b)
{
	t_data	*temp;
	int		i;

	i = 1;
	temp = *stack_b;
	while (temp)
	{
		if (temp->index == index)
			break ;
		temp = temp->next;
		i++ ;
	}
	return (i);
}

int	stack_sorted(t_data	**stack_a)
{
	t_data	*temp;

	temp = *stack_a;
	while (temp->next != NULL)
	{
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
	}
	return (1);
}
