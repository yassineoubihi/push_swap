/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:57:15 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/16 01:10:56 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int check_dup(char **str)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (str[i])
	{
		while (str[b])
		{
			if (str[i + 1] == NULL)
				break ;
			if (ft_atoi(str[i]) == ft_atoi(str[i + 1]))
				return (1);
			b++;
		}
		b = 0;
		i++;
	}
	return (0);
}

int	check_int_max(char **str_split)
{
	int	i;

	i = 0;
	while (str_split[i] != NULL)
	{
		if ((ft_atoi(str_split[i]) == -1 && ft_strcmp(str_split[i],"-1") == 0) || ((ft_atoi(str_split[i]) == 0) && (ft_strcmp(str_split[i],"0") == 1)))
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
	{
		ft_printf("Error\n");
		exit(1);
	}
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

void	fill_data(char *str, t_data **my_data, int *num)
{
	t_data	*cur;

	fill_data_with_space(str, my_data, num);
	cur = *my_data;
}
