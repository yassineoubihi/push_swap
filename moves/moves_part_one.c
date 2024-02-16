/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_part_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:24:45 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/16 10:22:59 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*sa :Swap the first 2 elements at the top of stack a*/
void	sa(t_data	**stack_a)
{
	int	temp;

	if ((*stack_a)->next != NULL)
	{
		temp = (*stack_a)->num;
		(*stack_a)->num = ((*stack_a)->next)->num;
		((*stack_a)->next)->num = temp;
		ft_printf("sa\n");
	}
}

/*sb : Swap the first 2 elements at the top of stack b.*/
void	sb(t_data	**stack_b)
{
	int	temp;

	if ((*stack_b)->next != NULL)
	{
		temp = (*stack_b)->num;
		(*stack_b)->num = ((*stack_b)->next)->num;
		((*stack_b)->next)->num = temp;
		ft_printf("sb\n");
	}
}

/*ss : sa and sb at the same time.*/
void	ss(t_data	**stack_a, t_data	**stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}

/*pa : Take the first element at the top of b and put it at the top of a. Do nothing if b is empty*/
void	pa(t_data	**stack_a, t_data	**stack_b)
{
	t_data	*temp;

	if (*stack_b != NULL)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = *stack_a;
		*stack_a = temp;
		ft_printf("pa\n");
	}
}

/*pb : Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.*/
void	pb(t_data	**stack_a, t_data	**stack_b)
{
	t_data	*temp;

	if (*stack_b != NULL)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = *stack_b;
		*stack_b = temp;
		ft_printf("pb\n");
	}
}
