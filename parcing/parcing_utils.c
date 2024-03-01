/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:57:15 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/28 19:34:08 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_erro()
{
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

int check_dup(char **str)
{
	int	i;
	int	b;

	i = 0;
	b = 1;

	while(str[i])
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

int	check_int_max(char **str_split)
{
	int	i;

	i = 0;
	while (str_split[i] != NULL)
	{
		if ((ft_atoi(str_split[i]) == -1 && ft_strcmp(str_split[i],"-1") == 0) && (ft_atoi(str_split[i]) > INT_MAX ||ft_atoi(str_split[i]) < INT_MIN))
			return (1);
		i++;
	}
	return (0);
}

void	fill_data_with_space(char *str, t_data **head, int *num)
{
	char	**str_split;
	t_data	*new_node;
	int		i;

	i = 0;
	str_split = ft_split(str, ' ');
	if (check_dup(str_split) == 1 || check_int_max(str_split) == 1)
		exit_erro();
	while (str_split[i] != NULL)
		i++;
	*num = i;
	while (--i >= 0)
	{
		new_node = (t_data *)malloc(sizeof(t_data));
		new_node->num = ft_atoi(str_split[i]);
		new_node->next = NULL;
		if (!(*head))
			*head = new_node;
		else
		{
			new_node->next = *head;
			*head = new_node;
		}
	}
	
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
	// check_numbers(&cur);
	// cur = *my_data;
	index_data(&cur);
	cur = *my_data;
	set_position(&cur);
	cur = *my_data;
	stack_size_count(&cur);
	// while (cur != NULL)
	// {
	// 	printf("num = %d ==> index = %d\n",cur->num,cur->index);
	// 	cur = cur->next;
	// }
}
