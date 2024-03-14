/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_case_one_help2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:26:27 by youbihi           #+#    #+#             */
/*   Updated: 2024/03/14 01:27:03 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	index_is_one(t_data	**stack_a, t_data	**stack_b, t_data	*head_a)
{
	if (head_a->position <= 2)
		ra_case(stack_a, stack_b, head_a->position);
	else
		rra_case(stack_a, stack_b, head_a->position);
}

void	sort_rest(t_data	**stack_a, t_data	**stack_b)
{
	sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
