/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:49:51 by chon              #+#    #+#             */
/*   Updated: 2024/05/09 12:01:08 by chon             ###   ########.fr       */
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

void	sort_alg_1(t_stack **a, t_stack **b, t_stack_num s, int ac)
{
	int trigger = 0;
	while (*b)
	{
		while (*b && ((*a)->final_position == (*b)->final_position + 1
			|| ((*a)->num == s.min && (*b)->num == s.max)))
			push(b, a, 2);
		if (*b)
		{
			if (pos_of_final_pos(*a, (*b)->final_position + 1) < round((double)ac / 2))
				rotate(a, NULL, 1);
			else
				rev_rotate(a, NULL, 1);
		}
		trigger++;
		if (trigger == 6)
			break ;
	}
}

int is_ordered(t_stack *node)
{
	if (!node->fwd)
		return (1);
	return (node->num < node->fwd->num);
}

void	sort_stack_ct_3(t_stack **a)
{
	int max_num;

	max_num = max_nbr(*a);
	if (num_in_node(*a, 0) == max_num)
		rotate(a, NULL, 1);
	else if (num_in_node(*a, 1) == max_num)
		rev_rotate(a, NULL, 1);
	if (is_sorted(a) == 0)
		swap(a, NULL, 1);
}

void sort_stack(t_stack **a, t_stack **b, int inputs)
{
	t_stack_num s;
	t_stack *cur_a;

	cur_a = *a;
	s.max = max_nbr(*a);
	s.min = min_nbr(*a);
	if ((*a)->final_position == (*a)->fwd->final_position + 1)
		swap(a, NULL, 1);
	if (srtd_but_err(a, *a, inputs, s))
		return ;
	if (inputs == 3)
		sort_stack_ct_3(a);
	else if (inputs < 6)
	{
		push(a, b, 1);
		if ((*a)->final_position == (*a)->fwd->final_position + 1)
			swap(a, NULL, 1);
		if (inputs == 5)
			push(a, b, 1);
		sort_stack_ct_3(a);
		if (is_ordered(*b))
			swap(b, NULL, 2);
		sort_alg_1(a, b, s, inputs);
		// int trigger = 0;
		// while (*stack_b)
		// {
		// 	while (*stack_b && ((*stack_a)->final_position == (*stack_b)->final_position + 1
		// 		|| ((*stack_a)->num == s.min && (*stack_b)->num == s.max)))
		// 		push(stack_b, stack_a, 2);
		// 	if (*stack_b)
		// 	{
		// 		if (pos_of_final_pos(*stack_a, (*stack_b)->final_position + 1)
		// 			< round((double)inputs / 2))
		// 			rotate(stack_a, NULL, 1);
		// 		else
		// 			rev_rotate(stack_a, NULL, 1);
		// 	}
		// 	trigger++;
		// 	if (trigger == 6)
		// 		break ;
		// }
		srtd_but_err(a, *a, inputs, s);
	}
}
