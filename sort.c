/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:49:51 by chon              #+#    #+#             */
/*   Updated: 2024/05/09 14:32:12 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_stack_ct_3(t_stack **a, int inputs)
{
	int max_num;

	max_num = max_nbr(*a);
	if (find_num_in_node(*a, 0) == max_num)
		rotate(a, NULL, 1);
	else if (find_num_in_node(*a, 1) == max_num)
		rev_rotate(a, NULL, 1);
	if (is_sorted(a) == 0)
		swap(a, NULL, 1);
	if (inputs == 3)
		exit(0);
}

void sort_alg_2(t_stack **a, t_stack **b, t_stack_num s, int ac)
{
	int trigger = 0;
	push(a, b, 1);
	if ((*a)->fin_pos == (*a)->fwd->fin_pos + 1)
		swap(a, NULL, 1);
	if (ac == 5 && (*a)->fin_pos != (*a)->fwd->fin_pos - 1)
	{
		push(a, b, 1);
		sort_stack_ct_3(a, ac);
		if (is_ordered(*b, 2))
			swap(b, NULL, 2);
	}
	while (*b)
	{
		while (*b && ((*a)->fin_pos == (*b)->fin_pos + 1 || ((*a)->num == s.min && (*b)->num == s.max)))
			push(b, a, 2);
		if (*b)
		{
			if ((*b)->num == s.max)
				push(b, a, 2);
			else if (find_pos_of_final_pos(*a, (*b)->fin_pos + 1) < round((double)ac / 2))
				rotate(a, NULL, 1);
			else
				rev_rotate(a, NULL, 1);
		}
		trigger++;
		if (trigger == 6)
			break;
	}
	srtd_but_err(a, *a, ac, s);
}

void sort_alg_1(t_stack **a, t_stack **b, t_stack_num s, int ac)
{
	// int	push_num;

	// push_num = find_num_in_node(*a, find_pos_of_final_pos(*a, ac));
	// if (ac == 5)
	// 	if (find_pos_of_final_pos(*a, ac) < find_pos_of_final_pos(*a, ac - 1))
	// 		push_num = find_num_in_node(*a, find_pos_of_final_pos(*a, ac - 1));
	while ((*a)->fin_pos != ac - 1)
	{
		if (find_pos_of_final_pos(*a, ac) < round((double)ac / 2))
			rotate(a, NULL, 1);
		else
			rev_rotate(a, NULL, 1);
	}
}

int is_ordered(t_stack *node, int num_of_nodes)
{
	if (!node->fwd)
		return (1);
	while (--num_of_nodes > 0)
	{
		if (node->num < node->fwd->num)
			return (0);
		node = node->fwd;
	}
	return (1);
}

void sort_stack(t_stack **a, t_stack **b, int inputs)
{
	t_stack_num s;

	if (inputs == 3)
		sort_stack_ct_3(a, inputs);
	s.max = max_nbr(*a);
	s.min = min_nbr(*a);
	if ((*a)->fin_pos > (*a)->fwd->fin_pos)
		swap(a, NULL, 1);
	if (srtd_but_err(a, *a, inputs, s))
		return;
	else if (inputs < 6)
	{
		// if (is_ordered(*a, 3))
		sort_alg_1(a, b, s, inputs);
		// else
		// 	sort_alg_2(a, b, s, inputs);
	}
}
