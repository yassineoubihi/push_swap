/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:10:35 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/17 11:58:06 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <libc.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_data
{
	int				num;
	struct s_data	*next;
} t_data;

typedef struct	s_data_index
{
	int				num;
	struct s_data	*next;
} t_data_index;

typedef struct	vars
{
	char	**r;
	int		i;
	int		b;
	int		flag;
} vars_c;

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
void	sort_case_one(t_data	**stack_a);
void	sort_case_two(t_data	**stack_a, t_data	**stack_b, int list_size);

#endif