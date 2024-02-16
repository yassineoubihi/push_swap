/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:54:33 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/16 13:53:14 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_data	*stack_a;
	t_data	*stack_b;
	int		num_of_args;

	if (argc >= 2)
	{
		num_of_args = 0;
		stack_a = NULL;
		parsing_data(argv, argc, &stack_a, &num_of_args);
		if (num_of_args == 3 || num_of_args == 4)
			sort_case_one(&stack_a);
		else if (num_of_args == 5)
			sort_case_two(&stack_a, &stack_b);
		// while (stack_a != NULL)
		// {
		// 	printf("%d\n",stack_a->num);
		// 	stack_a = stack_a->next;
		// }
	}
	else
		ft_printf("Error\n");
}
