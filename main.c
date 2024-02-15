/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:54:33 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/15 02:29:19 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_data	*stack_a;

	if (argc >= 2)
	{
		stack_a = NULL;
		parsing_data(argv, argc, &stack_a);
		sa(stack_a);
	}
	else
		ft_printf("Error\n");
}
