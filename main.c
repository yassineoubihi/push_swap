/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:54:33 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/17 11:57:53 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_data	*stack_a;
	t_data	*stack_b;
	int		list_size;

	if (argc >= 2)
	{
		list_size = 0;
		stack_a = NULL;
		parsing_data(argv, argc, &stack_a, &list_size);
		if (list_size == 3 || list_size == 4)
			sort_case_one(&stack_a);
		else if (list_size == 5)
			sort_case_two(&stack_a, &stack_b, list_size);
		// while (stack_a != NULL)
		// {
		// 	printf("%d\n",stack_a->num);
		// 	stack_a = stack_a->next;
		// }
	}
	else
		ft_printf("Error\n");
}
