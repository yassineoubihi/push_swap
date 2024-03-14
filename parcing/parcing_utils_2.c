/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:46:46 by youbihi           #+#    #+#             */
/*   Updated: 2024/03/13 22:43:25 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_str(char **str_split)
{
	int	i;

	i = 0;
	if (str_split == NULL)
		return ;
	while (str_split[i] != NULL)
	{
		free(str_split[i]);
		i++;
	}
	free (str_split);
}

void	exit_error(char **str_split)
{
	free_str(str_split);
	ft_printf("Error\n");
	exit(1);
}

void	set_position(t_data **head)
{
	int	i;

	i = 0;
	while (*head != NULL)
	{
		(*head)->position = i;
		i++;
		(*head) = (*head)->next;
	}
}

void	index_data(t_data **head)
{
	t_data	*temp_head;
	t_data	*curr_node;

	temp_head = *head;
	curr_node = *head;
	temp_head->index = 0;
	while (temp_head != NULL)
	{
		temp_head->index = 0;
		temp_head = temp_head->next;
	}
	temp_head = *head;
	while (curr_node != NULL)
	{
		while (temp_head != NULL)
		{
			if (curr_node->num > temp_head->num)
				curr_node->index++;
			temp_head = temp_head->next;
		}
		temp_head = *head;
		curr_node = curr_node->next;
	}
}

int	check_dup(char **str)
{
	int	i;
	int	b;

	i = 0;
	b = 1;
	while (str[i])
	{
		while (str[b])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[b]))
				return (1);
			b++;
		}
		i++;
		b = i + 1;
	}
	return (0);
}
