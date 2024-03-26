/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo_help_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:55:21 by youbihi           #+#    #+#             */
/*   Updated: 2024/03/25 22:44:47 by youbihi          ###   ########.fr       */
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

void	update_values(int *lspv, int *pv1, int *pv2, t_data	**stack_a)
{
	*lspv = *pv1;
	*pv1 = *pv1 + stack_size(stack_a) / 3;
	*pv2 = *pv2 + stack_size(stack_a) / 6;
}
