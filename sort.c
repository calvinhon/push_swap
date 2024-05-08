/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:49:51 by chon              #+#    #+#             */
/*   Updated: 2024/05/08 15:29:43 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	is_wrong_order(t_stack *head, t_stack *cur, int min_num, int max_num)
// {
// 	if (cur->fwd)
// 		return ((cur->num != max_num && cur->num > cur->fwd->num)
// 			|| (cur->num == max_num && cur->fwd->num != min_num));
// 	else
// 		return ((cur->num != max_num && cur->num < head->num)
// 			|| (cur->num == max_num && !(cur->bwd->num == min_num
// 			|| head->num == min_num)));
// }

// int	ct_wrong_order(t_stack *head, t_stack *cur, int min_num, int max_num)
// {
// 	int		count;

// 	count = 0;
// 	while (cur->fwd)
// 	{
// 		if (is_wrong_order(head, cur, min_num, max_num))
// 			count++;
// 		cur = cur->fwd;
// 	}
// 	return (count);
// }

int is_ordered(t_stack *node)
{
	if (!node->fwd)
		return (1);
	return (node->num < node->fwd->num);
}

void sort_stack_ct_3(t_stack **stack_a)
{
	// int	num_of_nodes;
	int	max_num;

	// num_of_nodes = count_nodes(*stack_a);
	// if (num_of_nodes == 2 && !is_ordered(*stack_a))
	// 	swap(stack_a, stack_b, 1);
	// else
	// {
		max_num = find_max(*stack_a);
		if (num_in_node(*stack_a, 0) == max_num)
			rotate(stack_a, NULL, 1);
		else if (num_in_node(*stack_a, 1) == max_num)
			rev_rotate(stack_a, NULL, 1);
		if (is_sorted(stack_a) == 0)
			swap(stack_a, NULL, 1);
	// }
}

// void	sort_stack_ct4(stack_a, stack_b)
// {

// }

void sort_stack(t_stack **stack_a, t_stack **stack_b, int inputs)
{
	int max_num;
	int min_num;
	t_stack *cur_a;
	int	rotate_switch;
	// int node_to_move;

	cur_a = *stack_a;
	if (inputs == 2)
	{
		swap(stack_a, stack_b, 1);
		return;
	}
	max_num = find_max(*stack_a);
	min_num = find_min(*stack_a);
	if (inputs == 3)
		sort_stack_ct_3(stack_a);
	else if (inputs < 6)
	{
		push(stack_a, stack_b, 1);
		if (inputs == 5)
			push(stack_a, stack_b, 1);
		// if (inputs == 4)
		// {
		// 	if (!is_ordered(*stack_a) && is_ordered(*stack_b))
		// 		swap(stack_a, stack_b, 3);
		// 	else if (is_ordered(*stack_a) && is_ordered(*stack_b))
		// 		swap(stack_b, NULL, 2);
		// 	else if (!is_ordered(*stack_a) && !is_ordered(*stack_b))
		// 		swap(stack_a, NULL, 1);
		// }
		// else
		// {
			sort_stack_ct_3(stack_a);
			if (is_ordered(*stack_b))
				swap(stack_b, NULL, 2);
		// }
		// int trigger = 0;
		while (*stack_b)
		{
			while (*stack_b && ((*stack_a)->num > (*stack_b)->num
				|| ((*stack_a)->num == min_num && (*stack_b)->num == max_num)))
				push(stack_b, stack_a, 2);
			if (*stack_b)
				rotate(stack_a, NULL, 1);
			// trigger++;
			// if (trigger == 6)
			// 	break ;
		}
		int trigger2 = 0;
		rotate_switch = 0;
		if (find_pos_of_num(*stack_a, min_num) < inputs / 2)
			rotate_switch = 1;
		while (!is_sorted(stack_a))
		{
			if (rotate_switch)
				rotate(stack_a, NULL, 1);
			else
				rev_rotate(stack_a, NULL, 1);
			trigger2++;
			if (trigger2 == 6)
				break ;
		}
	}
	// else
	// {
	// node_to_move = find_first_err(*stack_a, *stack_a, min_num, max_num);
	// if (ct_wrong_order(*stack_a, *stack_a, min_num, max_num) == 1)
	// {
	// 	while (is_sorted(stack_a) == 0)
	// 	{
	// 		while ((*stack_a)->num < (*stack_a)->fwd->num)
	// 		{
	// 			if (node_to_move < inputs / 2)
	// 				rotate(stack_a, stack_b, 1);
	// 			else
	// 				rev_rotate(stack_a, stack_b, 1);
	// 		}
	// 		swap(stack_a, stack_b, 1);
	// 		while (cur_a->num < cur_a->fwd->num)
	// 		{
	// 			cur_a = cur_a->fwd
	// 		}
	// while ((*stack_a)->num < (*stack_a)->fwd->num)
	// {
	// 	if (node_to_move < inputs / 2)
	// 		rev_rotate(stack_a, stack_b, 1);
	// 	else
	// 		rotate(stack_a, stack_b, 1);
	// }
	// 	}
	// }
	// printf("wrong:%d\n", ct_wrong_order(*stack_a, *stack_a, min_num, max_num));
	// printf("error located in node:%d\n", find_first_error(*stack_a, *stack_a, min_num, max_num));
	// }
}
