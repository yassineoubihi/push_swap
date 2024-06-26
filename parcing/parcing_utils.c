/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:57:15 by youbihi           #+#    #+#             */
/*   Updated: 2024/03/25 22:54:58 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_int_max(char **str_split)
{
	int	i;

	i = 0;
	while (str_split[i] != NULL)
	{
		if ((ft_atoi(str_split[i]) == -1 && \
			ft_strcmp(str_split[i], "-1") == 0) && \
			(ft_atoi(str_split[i]) > INT_MAX || \
			ft_atoi(str_split[i]) < INT_MIN))
			return (1);
		i++;
	}
	return (0);
}

t_data	*allocate_t_data(void)
{
	t_data	*temp_node;

	temp_node = (t_data *)malloc(sizeof(t_data));
	if (temp_node == NULL)
	{
		ft_printf("Memory allocation failed");
		exit(0);
	}
	return (temp_node);
}

void	fill_data_with_space(char *str, t_data **head, int *num)
{
	t_fill_stuct	my_data;

	my_data.i = 0;
	my_data.str_split = ft_split(str, ' ');
	if (check_dup(my_data.str_split) == 1 || \
		check_int_max(my_data.str_split) == 1)
		exit_error(my_data.str_split);
	while (my_data.str_split[my_data.i] != NULL)
		my_data.i++;
	*num = my_data.i;
	while (--my_data.i >= 0)
	{
		my_data.new_node = allocate_t_data();
		my_data.new_node->num = ft_atoi(my_data.str_split[my_data.i]);
		my_data.new_node->next = NULL;
		if (!(*head))
			*head = my_data.new_node;
		else
		{
			my_data.new_node->next = *head;
			*head = my_data.new_node;
		}
	}
	free_str(my_data.str_split);
	free(str);
}

void	stack_size_count(t_data **head)
{
	t_data	*temp;
	int		i;

	temp = *head;
	i = 0;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	temp = *head;
	while (temp != NULL)
	{
		temp->stack_size = i;
		temp = temp->next;
	}
}

void	fill_data(char *str, t_data **my_data, int *num)
{
	t_data	*cur;

	fill_data_with_space(str, my_data, num);
	cur = *my_data;
	index_data(&cur);
	cur = *my_data;
	set_position(&cur);
	cur = *my_data;
	stack_size_count(&cur);
}
