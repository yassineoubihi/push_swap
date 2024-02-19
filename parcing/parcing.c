/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:15:13 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/17 17:33:06 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_space(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	check_split(char *str)
{
	vars_c vars;
	
	vars.flag = check_space(str);
	if (vars.flag == 0)
		return (0);
	vars.i = 0;
	vars.b = 1;
	vars.r = ft_split(str, ' ');
	while (vars.r[vars.i] != NULL)
	{
		if (vars.r[vars.i][0] == '\0' || ((vars.r[vars.i][0] < '0' &&
			vars.r[vars.i][0] > 9) && vars.r[vars.i][0] != '-' && vars.r[vars.i][0] != '+'))
			return (0);
		if (ft_isdigit(vars.r[vars.i][0]) == 0 && vars.r[vars.i][1] == '\0')
			return (0);
		while (vars.r[vars.i][vars.b])
		{
			if (ft_isdigit(vars.r[vars.i][vars.b]) != 1)
				return (0);
			vars.b++;
		}
		vars.b = 1;
		vars.i++;
	}
	return (1);
}

int	check_no_slpit(char *str)
{
	int	i;

	i = 1;
	if (ft_isdigit(str[0]) == 0 && str[1] == '\0')
		return (0);
	if (str[0] == '\0' || (ft_isdigit(str[0]) == 0 && (str[0] != '-' &&  str[0] != '+')))
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_arg(char *str)
{
	int	i;

	i = 0;
	if (ft_strsearch(str, ' ') == 1)
		return(check_split(str));
	else
		return(check_no_slpit(str));
	return (1);
}

void	handel_data(char *str)
{
	int	result;

	result = check_arg(str);
	if (result == 0)
	{
		ft_printf("Error\n");
		exit (1);
	}
}

void	parsing_data(char **argv, int argc, t_data	**main_head, int *num)
{
		
	int		i;
	char	*str;

	i = 1;
	while (i <= argc - 1)
	{
		handel_data(argv[i]);
		i++;
	}
	i = 1;
	str = ft_strjoin(argv[i], " ");
	i++;
	while (i <= argc - 1)
	{
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	fill_data(str, main_head, num);
}
