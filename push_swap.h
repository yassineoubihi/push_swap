/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:10:35 by youbihi           #+#    #+#             */
/*   Updated: 2024/03/14 01:32:10 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_data
{
	int				num;
	int				index;
	int				position;
	int				stack_size;
	struct s_data	*next;
}	t_data;

typedef struct s_data_index
{
	int				num;
	struct s_data	*next;
}	t_data_index;

typedef struct vars
{
	char	**r;
	int		i;
	int		b;
	int		flag;
}	t_vars_c;

typedef struct fill_data
{
	char	**str_split;
	t_data	*new_node;
	int		i;
}	t_fill_stuct;

typedef struct algo
{
	int	lspv;
	int	pv1;
	int	pv2;
	int	flag;
}	t_algo_first;

void	free_str(char **str_split);
void	exit_error(char **str_split);
void	set_position(t_data **head);
void	index_data(t_data **head);
int		check_dup(char **str);
int		check_space(char *str);
void	ft_putchar_c(char c, int *b);
void	ft_putnbr(int nb, int *b);
void	ft_putstr(char *s, int *b);
int		ft_printf(const char	*str, ...);
void	ft_putunsigned(unsigned int n, int *b);
size_t	ft_strlen(const char *s);
void	ft_putaddres(void *str, int *b);
void	ft_puthex(unsigned int str, int *b);
void	ft_puthex_upp(unsigned int str, int *b);
void	parsing_data(char **argv, int argc, t_data	**main_head, int *num);
char	**ft_split(char const *s, char c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
void	ft_putchar_c(char c, int *b);
void	ft_putnbr(int nb, int *b);
void	ft_putstr(char *s, int *b);
int		ft_printf(const char	*str, ...);
void	ft_putunsigned(unsigned int n, int *b);
size_t	ft_strlen(const char *s);
void	ft_putaddres(void *str, int *b);
void	ft_puthex(unsigned int str, int *b);
void	ft_puthex_upp(unsigned int str, int *b);
int		ft_atoi(const char *s);
int		ft_strsearch(char *s, char c);
int		ft_strcmp(char *s1, char *s2);
void	fill_data(char *str, t_data **my_data, int *num);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *destination, const void *source, size_t num);
void	sa(t_data	**stack_a);
void	sb(t_data	**stack_b);
void	ss(t_data	**stack_a, t_data	**stack_b);
void	pa(t_data	**stack_a, t_data	**stack_b);
void	pb(t_data	**stack_a, t_data	**stack_b);
void	ra(t_data	**stack_a);
void	rb(t_data	**stack_b);
void	rr(t_data	**stack_a, t_data	**stack_b);
void	rra(t_data	**stack_a);
void	rrb(t_data	**stack_b);
void	rrr(t_data	**stack_a, t_data	**stack_b);
int		check_1(t_data **stack_a);
void	ra_case(t_data	**stack_a, t_data	**stack_b, int c);
void	rra_case(t_data	**stack_a, t_data	**stack_b, int c);
void	change_positions(t_data	**stack_a);
void	index_is_zero(t_data **stack_a, t_data **stack_b, t_data *head_a);
void	index_is_one(t_data	**stack_a, t_data	**stack_b, t_data	*head_a);
void	sort_rest(t_data	**stack_a, t_data	**stack_b);
void	sort_2(t_data	**stack_a);
void	sort_3(t_data	**stack_a);
void	sort_four_and_five(t_data	**stack_a, t_data	**stack_b, int c);
int		stack_size(t_data	**stack);
int		stack_size(t_data	**stack);
int		get_big_value(t_data	**stack);
int		get_button_value(t_data	**stack);
void	fix_stack(t_data	**stack_b);
void	update_values(int *lspv, int *pv1, int *pv2, t_data	**stack_a);
void	algo_step_1(t_data	**stack_a, t_data	**stack_b);
int		get_position(int index, t_data	**stack_b);
int		stack_sorted(t_data	**stack_a);
void	main_algo(t_data	**stack_a, t_data	**stack_b);

#endif
