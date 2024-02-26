/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:54:33 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/26 15:54:32 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_sorted(t_data	**head)
{
	t_data	*temp_head;

	temp_head = *head;
	while (temp_head->next != NULL)
	{
		if (temp_head->num > temp_head->next->num)
			return ;
		temp_head = temp_head->next;
	}
	exit(1);
}

int	main(int argc, char **argv)
{
	t_data	*stack_a;
	t_data	*stack_b;
	int		list_size;

	if (argc >= 2)
	{
		list_size = 0;
		stack_a = NULL;
		stack_b = NULL;
		parsing_data(argv, argc, &stack_a, &list_size);
		check_if_sorted(&stack_a);
		if (list_size == 2)
			sort_2(&stack_a);
		else if (list_size == 3)
			sort_3(&stack_a);
		else if (list_size == 5 || list_size == 4)
			sort_four_and_five(&stack_a, &stack_b, list_size);
		else
			main_algo(&stack_a, &stack_b);
		
	}
	else
		ft_printf("Error\n");
}
