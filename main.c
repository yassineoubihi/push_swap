/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:54:33 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/16 01:16:42 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_data	*stack_a;
	// t_data	*stack_b;
	int		num_of_args;

	if (argc >= 2)
	{
		num_of_args = 0;
		stack_a = NULL;
		parsing_data(argv, argc, &stack_a, &num_of_args);
		if (num_of_args == 3 || num_of_args == 4)
			sort_case_one(stack_a);
	}
	else
		ft_printf("Error\n");
}
