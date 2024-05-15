/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:49:51 by chon              #+#    #+#             */
/*   Updated: 2024/05/15 14:55:17 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_stack_ct_3(t_stack **a)
{
	int	max_num;

	max_num = max_nbr(*a);
	if (find_num_in_node(*a, 0) == max_num)
		rotate(a, NULL, 1);
	else if (find_num_in_node(*a, 1) == max_num)
		rev_rotate(a, NULL, 1);
	if (!is_ordered(*a, 2))
		swap(a, NULL, 1);
	return ;
}

void sort_alg_3(t_stack **a, t_stack **b, t_stack_num s, int inputs)
{
	int	position;
	int	rotate_switch;

	(void)s;
	rotate_switch = 1; 
	position = 0;
	while (position < inputs - 2)
	{
		if (find_pos_of_final_pos(*a, position)
			> round((double)count_nodes(*a) / 2))
			rotate_switch = 2;
		while ((*a)->fin_pos != position)
		{
			if (rotate_switch == 1)
				rotate(a, NULL, 1);
			else
				rev_rotate(a, NULL, 1);
		}
		push(a, b, 1);
		rotate_switch = 1;
		position++;
	}
	if ((*a)->fin_pos > (*a)->fwd->fin_pos)
		swap(a, NULL, 1);
	while (*b)
		push(b, a, 2);
}

void sort_alg_2(t_stack **a, t_stack **b, t_stack_num s, int inputs)
{
	int		rotate_steps;
	int		rev_rotate_steps;
	t_stack	*cur;

	rotate_steps = 0;
	rev_rotate_steps = 0;
	while (!is_ordered(*a, -1))
	{
		if (((*a)->fin_pos == (*a)->fwd->fin_pos + 1 && !((*a)->fin_pos == inputs - 1
			&& (*a)->fwd->fin_pos == 0)) || ((*a)->fin_pos == 0
			&& (*a)->fwd->fin_pos == inputs - 1))
			swap(a, NULL, 1);
		else
			push(a, b, 1);
		cur = *a;
		while (cur->fwd && cur->fin_pos < cur->fwd->fin_pos)
		{
			rotate_steps++;
			cur = cur->fwd;
		}
		while (cur->fwd)
			cur = cur->fwd;
		if (cur->fin_pos > (*a)->fin_pos)
			rev_rotate_steps = 1;
		else
			while (cur->bwd && cur->fin_pos > cur->bwd->fin_pos)
			{
				rev_rotate_steps++;
				cur = cur->bwd;
			}
		if (rotate_steps < rev_rotate_steps)
			while (--rotate_steps > -1)
				rotate(a, NULL, 1);
		else
			while (--rev_rotate_steps > -1)
				rev_rotate(a, NULL, 1);
	}
	
}

void sort_alg_1(t_stack **a, t_stack **b, t_stack_num s, int inputs)
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
			if (find_pos_of_final_pos(*a, (*b)->fin_pos + 1)
				< round((double)count_nodes(*a) / 2))
				rotate(a, NULL, 1);
			else
				rev_rotate(a, NULL, 1);
		}
	}
	srtd_but_err(a, *a, inputs, s);
}

int is_ordered(t_stack *node, int num_of_nodes)
{
	if (!node->fwd)
		return (1);
	if (num_of_nodes == -1)
		while (node->fwd)
		{
			if (node->num > node->fwd->num)
				return (0);
			node = node->fwd;
		}
	else
		while (node->fwd && num_of_nodes > 0)
		{
			if (node->num > node->fwd->num)
				return (0);
			node = node->fwd;
			num_of_nodes--;
		}
	return (1);
}

void sort_stack(t_stack **a, t_stack **b, int inputs)
{
	t_stack_num s;

	s.max = max_nbr(*a);
	if (inputs == 3)
		sort_stack_ct_3(a);
	s.min = min_nbr(*a);
	srtd_but_err(a, *a, inputs, s);
	if (inputs > 3 && inputs < 6)
	{
		if (((*a)->fin_pos > (*a)->fwd->fin_pos
			&& !((*a)->fin_pos == inputs - 1 && (*a)->fwd->fin_pos == 0))
			|| ((*a)->fin_pos == 0 && (*a)->fwd->fin_pos == inputs - 1))
			swap(a, NULL, 1);
		srtd_but_err(a, *a, inputs, s);
		sort_alg_1(a, b, s, inputs);
		return ;
	}
	if (inputs > 5)
		sort_alg_3(a, b, s, inputs);
}
