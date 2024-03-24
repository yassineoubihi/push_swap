/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_split_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:58:56 by youbihi           #+#    #+#             */
/*   Updated: 2024/03/24 16:54:44 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_case_one(t_vars_c vars)
{
	if ((vars.r[vars.i][0] == '\0' || \
	((vars.r[vars.i][0] < '0' && vars.r[vars.i][0] > 9) &&
		vars.r[vars.i][0] != '-' && vars.r[vars.i][0] != '+')) ||
		(ft_isdigit(vars.r[vars.i][0]) == 0 && vars.r[vars.i][1] == '\0'))
		return (0);
	return (1);
}

int	check_case_tow(t_vars_c vars)
{
	while (vars.r[vars.i][vars.b])
	{
		if (ft_isdigit(vars.r[vars.i][vars.b]) != 1)
			return (0);
		vars.b++;
	}
	return (1);
}
