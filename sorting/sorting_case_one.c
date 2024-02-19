/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_case_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbihi <youbihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 00:41:22 by youbihi           #+#    #+#             */
/*   Updated: 2024/02/19 14:25:06 by youbihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_data	**stack_a)
{
	if (((*stack_a)->num > (*stack_a)->next->num) && ((*stack_a)->num > (*stack_a)->next->next->num) && ((*stack_a)->next->num) < (*stack_a)->next->next->num)
		ra(stack_a);
	else if ((*stack_a)->num < ((*stack_a)->next)->num && ((*stack_a)->next)->num < (((*stack_a)->next)->next)->num)
		return ;
	else if (((*stack_a)->num > ((*stack_a)->next)->num) &&
		(((*stack_a)->next)->num < (((*stack_a)->next)->next)->num) &&
		((*stack_a)->num < (((*stack_a)->next)->next)->num))
		sa(stack_a);
	else if ((*stack_a)->num > ((*stack_a)->next)->num &&
		(*stack_a)->num > (((*stack_a)->next)->next)->num)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (((*stack_a)->num < ((*stack_a)->next)->num) &&
		(((*stack_a)->next)->num > (((*stack_a)->next)->next)->num) &&
		((*stack_a)->num > (((*stack_a)->next)->next)->num))
		rra(stack_a);
	else if ((*stack_a)->num < ((*stack_a)->next)->num &&
		((*stack_a)->next)->num > (((*stack_a)->next)->next)->num)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	ra_case(t_data	**stack_a, t_data	**stack_b, int c)
{
	while (c > 0)
	{
		ra(stack_a);
		c--;
	}
	printf("c = %d",c);
	pb(stack_a, stack_b);
}

void	rra_case(t_data	**stack_a, t_data	**stack_b, int c)
{
	printf("c = %d\n",c);
	while (c < (*stack_a)->stack_size)
	{
		rra(stack_a);
		c++;
	}
	pb(stack_a, stack_b);
}

void	change_positions(t_data	**stack_a)
{
	t_data	*head_stack_a;
	int		i;

	i = 0;
	head_stack_a = *stack_a;
	while (head_stack_a != NULL)
	{
		head_stack_a->position = i;
		i++;
		head_stack_a = head_stack_a->next;
	}
}

void	sort_5(t_data	**stack_a, t_data	**stack_b)
{
	t_data	*head_stack_a;

	head_stack_a = *stack_a;
	while (head_stack_a != NULL)
	{
		if (head_stack_a->index == 0)
		{
			if (head_stack_a->position <= 2)
				ra_case(stack_a, stack_b, head_stack_a->position);
			else
				rra_case(stack_a, stack_b, head_stack_a->position);
			break ;
		}
		head_stack_a = head_stack_a->next;
	}
	change_positions(stack_a);
	stack_size(stack_a);
	head_stack_a = *stack_a;
	while (head_stack_a != NULL)
	{
		printf("position = %d || num = %d || index  = %d\n", head_stack_a->position, head_stack_a->num,head_stack_a->index);
		head_stack_a = head_stack_a->next;
	}
	head_stack_a = *stack_a;
	while (head_stack_a != NULL)
	{
		printf("index =  %d\n",head_stack_a->index);
		if (head_stack_a->index == 1)
		{
			puts("here 2");
			if (head_stack_a->position <= 2)
				ra_case(stack_a, stack_b, head_stack_a->position);
			else
				rra_case(stack_a, stack_b,head_stack_a->position);
			break ;
		}
		head_stack_a = head_stack_a->next;
	}
	sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	head_stack_a = *stack_a;
	printf("\n======== AFTER SORTING =============\n");
	while (head_stack_a != NULL)
	{
		printf("%d ", head_stack_a->num);
		head_stack_a = head_stack_a->next;
	}
}


























































// int	get_index(t_data	*head)
// {
// 	int b;
// 	int	index;
// 	int	min;

// 	index = 1;
// 	min = 0;
// 	b = head->num;
// 	head = head->next;
// 	while (head != NULL)
// 	{
// 		if (b > head->num)
// 		{
// 			b = head->num;
// 			min = index;
// 		}
// 		head = head->next;
// 		index++;
// 	}
// 	return (min);
// }

// void	loop_case_1(t_data	**stack_a, t_data	**stack_b, int i, int list_size)
// {
// 	while (i > list_size)
// 	{
// 		ra(stack_a);
// 		i--;
// 	}
// 	pb(stack_a, stack_b);
// }

// void	loop_case_2(t_data	**stack_a, t_data	**stack_b, int i, int list_size)
// {
// 	// printf("\ni = %d\n",i);
// 	while (i < list_size)
// 	{
// 		rra(stack_a);
// 		i++;
// 	}
// 	pb(stack_a, stack_b);
// }

// void	sort_5_utils(t_data	**stack_a, t_data	**stack_b)
// {
// 	int		i;
// 	t_data	*head;

// 	i = 0;
// 	head = *stack_a;
// 	while (head != NULL)
// 	{
// 		if (head->index == 0)
// 		{
// 			printf("\n\nnumber  = %d\n\n",head->num);
// 			if (5 / 2 >= head->position)
// 				loop_case_1(stack_a, stack_b, head->position, 5);
// 			else if (5 / 2 < head->position)
// 				loop_case_2(stack_a, stack_b, head->position, 5);
// 			break ;
// 		}
// 		head = head->next;
// 		i++;
// 	}
// 	i = 0;
// 	// printf("\n\n position = %d\n\n",head->index);
// 	head = *stack_a;
// 	while (head != NULL)
// 	{
// 		printf("\n\n num = %d\n\n",head->num);
// 		// if ((head->num < head->next->num) && (head->next->num < head->next->next->num) &&
// 		// 	(head->next->next->num < head->next->next->next->num))
// 		// 	break ;
// 		if (head->index == 1)
// 		{
// 			printf("\ni = %d\n",i);
// 			if (5 / 2 >= i)
// 				loop_case_1(stack_a, stack_b, i, 4);
// 			if (5 / 2 < i)
// 				loop_case_2(stack_a, stack_b, i, 4);
// 			break;
// 		}
// 		head = head->next;
// 		i++;
// 	}
// 	// printf("\n\n position = %d\n\n",head->index);
// }

// void	sort_5(t_data	**stack_a, t_data	**stack_b)
// {
// 	int		i;
// 	t_data	*head;
	
// 	i = 0;
// 	head = *stack_a;
// 	sort_5_utils(stack_a, stack_b);
// 	sort_3(stack_a);
// 	pa(stack_a, stack_b);
// 	pa(stack_a, stack_b);
// 	head = *stack_a;
// 	// printf("\n\n---------------------------------------------------------------------\n\n");
// 	// while (head != NULL)
// 	// {
// 	// 	printf("index = %d || num = %d || adress = %p\n",head->index,head->num,head->next);
// 	// 	head = head->next;
// 	// }
// 	// printf("\n\n---------------------------------------------------------------------\n\n");
// }
