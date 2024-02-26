/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_part_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 00:46:16 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/26 16:49:52 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*ra : Shift up all elements of stack a by 1. The first element becomes the last one.*/
void	ra(t_data	**stack_a)
{
	t_data	*temp;
	t_data	*last;

	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	last = temp;
	while (last->next != NULL)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	ft_printf("ra\n");
}

/*rb : Shift up all elements of stack b by 1.The first element becomes the last one */
void	rb(t_data	**stack_b)
{
	t_data	*temp;
	t_data	*last;

	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	last = temp;
	while (last->next != NULL)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	ft_printf("rb\n");
}

/*rr : ra and rb at the same time */
void	rr(t_data	**stack_a, t_data	**stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}

/*rra : Shift down all elements of stack a by 1. The last element becomes the first one.*/
void	rra(t_data	**stack_a)
{
	t_data	*temp;
	t_data	*second_last;

	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		temp = *stack_a;
		second_last = NULL;
		while (temp->next != NULL)
		{
			second_last = temp;
			temp = temp->next;
		}
		second_last->next = NULL;
		temp->next = *stack_a;
		*stack_a = temp;
		ft_printf("rra\n");
	}
}

/*rrb : Shift down all elements of stack b by 1. The last element becomes the first one.*/
void	rrb(t_data	**stack_b)
{
	t_data	*temp;
	t_data	*second_last;

	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		temp = *stack_b;
		second_last = NULL;
		while (temp->next != NULL)
		{
			second_last = temp;
			temp = temp->next;
		}
		second_last->next = NULL;
		temp->next = *stack_b;
		*stack_b = temp;
		ft_printf("rrb\n");
	}
}
