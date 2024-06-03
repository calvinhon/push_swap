/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:49:51 by chon              #+#    #+#             */
/*   Updated: 2024/06/03 16:09:17 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_stack_ct_3(t_stack **a)
{
	int max_num;

	max_num = max_nbr(*a);
	if (find_num_in_node(*a, 0) == max_num)
		rotate(a, NULL, 1);
	else if (find_num_in_node(*a, 1) == max_num)
		rev_rotate(a, NULL, 1);
	if (!is_ordered(*a, 2))
		swap(a, NULL, 1);
	return;
}

void simple_sort_alg(t_stack **a, t_stack **b, t_stack_num s, int inputs)
{
	push(a, b, 1);
	if (inputs == 5)
		push(a, b, 1);
	sort_stack_ct_3(a);
	while (*b)
	{
		while (*b && ((*a)->fin_pos == (*b)->fin_pos + 1
			|| ((*a)->num == s.min && (*b)->num == s.max)))
			push(b, a, 2);
		if (*b)
		{
			if (idx_of_fin_pos(*a, (*b)->fin_pos + 1)
				< ft_round((double)count_nodes(*a) / 2))
				rotate(a, NULL, 1);
			else
				rev_rotate(a, NULL, 1);
		}
	}
	ordered_but_err(a, inputs, s);
}

int is_ordered(t_stack *node, int num_of_nodes)
{
	t_stack *head;
	int max_num;
	int min_num;

	head = node;
	max_num = max_nbr(node);
	min_num = min_nbr(node);
	if (!node->fwd)
		return (1);
	if (num_of_nodes == -1)
		num_of_nodes = count_nodes(node);
	while (node->fwd && --num_of_nodes > -1)
	{
		if (node->num > node->fwd->num && !(node->num == max_num && node->fwd->num == min_num))
			return (0);
		node = node->fwd;
	}
	if (!node->fwd && node->num > head->num && !(node->num == max_num && head->num == min_num))
		return (0);
	return (1);
}

void sort_stack(t_stack **a, t_stack **b, int inputs)
{
	t_stack_num s;

	if (inputs == 3)
	{
		sort_stack_ct_3(a);
		return;
	}
	s.max = max_nbr(*a);
	s.min = min_nbr(*a);
	ordered_but_err(a, inputs, s);
	if (inputs > 3 && inputs < 6)
	{
		if (((*a)->num > (*a)->fwd->num && is_max_min_order(a, *a, s, 'f') != 1)
			|| (is_max_min_order(a, *a, s, 'f') == 2))
			swap(a, NULL, 1);
		ordered_but_err(a, inputs, s);
		if (is_perfect(a))
			return ;
		simple_sort_alg(a, b, s, inputs);
		return ;
	}
	if (inputs > 5)
		complex_sort_alg(a, b, s, inputs);
}
