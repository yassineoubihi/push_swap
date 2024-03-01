/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_part_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:24:45 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/26 16:41:05 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*sa :Swap the first 2 elements at the top of stack a*/
void	sa(t_data	**stack_a)
{
	t_data *first;
	t_data *second;

    if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		first = *stack_a;
		second = (*stack_a)->next;
		first->next = second->next;
		second->next = first;
		*stack_a = second;
		ft_printf("sa\n");
    }
}

/*sb : Swap the first 2 elements at the top of stack b.*/
void	sb(t_data	**stack_b)
{
	t_data *first;
	t_data *second;

	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		first = *stack_b;
		second = (*stack_b)->next;
		first->next = second->next;
		second->next = first;
		*stack_b = second;
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

	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	ft_printf("pb\n");
}
