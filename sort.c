/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:49:51 by chon              #+#    #+#             */
/*   Updated: 2024/05/21 16:35:23 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	switch_var2 = 1;

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

void	empty_b(t_stack **a, t_stack **b, t_stack_num s)
{
	int	ra_to_pa_top;
	int	rra_to_pa_top;
	t_stack	*cur_a;
	
	while (*b)
	{
					if (switch_var2 == 1)
					{
					t_stack *tmp_a = *a;
					printf("\n");
					while (tmp_a)
					{
						printf("%lld ", tmp_a->num);
						tmp_a = tmp_a->fwd;
					}
					printf("\n");
					t_stack *tmp_b = *b;
					while (tmp_b)
					{
						printf("%lld ", tmp_b->num);
						tmp_b = tmp_b->fwd;
					}
					printf("\n");
					}
		if (find_fin_pos_in_node(*b, -1) == find_fin_pos_in_node(*a, -1) - 1)
		{
			rev_rotate(a, b, 3);
			push(b, a, 2);
		}
		
		t_stack	*cur_b;
		int	length_a;
		int	node_b_to_move;
		int	best_node_b_to_move;
		int	shift_a_to_pa;
		int	best_shift_a_to_pa;
		cur_b = *b;
		length_a = count_nodes(a);
		node_b_to_move = 0;
		while (cur_b->fwd)
		{
			shift_a_to_pa = find_pos_of_final_pos(*a, cur_b->fin_pos + 1);
			if (shift_a_to_pa != -1)
			{
				shift_a_to_pa = length_a / 2 - shift_a_to_pa;
				if (shift_a_to_pa < best_shift_a_to_pa)
				{
					best_shift_a_to_pa = shift_a_to_pa;
					best_node_b_to_move = node_b_to_move;
				}
			}
			node_b_to_move++;
			cur_b = cur_b->fwd;
		}
		
		cur_a = *a;
		ra_to_pa_top = 0;
		rra_to_pa_top = 1;
		while (cur_a->fwd && *b
			&& (((*b)->num != s.max && (cur_a->fin_pos != (*b)->fin_pos + 1))
			|| ((*b)->num == s.max && cur_a->num != s.min)))
		{
			ra_to_pa_top++;
			cur_a = cur_a->fwd;
		}
		while (cur_a->fwd)
			cur_a = cur_a->fwd;
		while (cur_a->bwd && *b
			&& (((*b)->num != s.max && (cur_a->fin_pos != (*b)->fin_pos + 1))
			|| ((*b)->num == s.max && cur_a->num != s.min)))
		{
			rra_to_pa_top++;
			cur_a = cur_a->bwd;
		}
				if (switch_var2 == 1)
					printf("%d,%d\n", ra_to_pa_top, rra_to_pa_top);
		if (rra_to_pa_top > ra_to_pa_top)
			while (ra_to_pa_top > 0)
			{
				if (count_nodes(*b) == 2 && (*b)->fin_pos < (*b)->fwd->fin_pos)
					rotate(a, b, 3);
				else
					rotate(a, NULL, 1);
				ra_to_pa_top--;
			}
		else
			while (rra_to_pa_top > 0)
			{
				if (count_nodes(*b) == 2 && (*b)->fin_pos < (*b)->fwd->fin_pos)
					rev_rotate(a, b, 3);
				else
					rev_rotate(a, NULL, 1);
				rra_to_pa_top--;
			}
		while (*b && ((*b)->fin_pos == (*a)->fin_pos - 1
				|| ((*b)->num == s.max && (*a)->num == s.min)))
				push(b, a, 2);
	}
}

void	sort_alg_2(t_stack **a, t_stack **b, t_stack_num s, int inputs)
{
	int		rotate_steps;
	int		rev_rotate_steps;
	t_stack	*cur;

	(void)inputs;
	if ((*a)->fin_pos > (*a)->fwd->fin_pos + 1 && !is_max_min_order(a, *a, s))
		push(a, b, 1);
	while (!is_ordered(*a, -1))
	{
		rotate_steps = 1;
		rev_rotate_steps = 1;
		if (((*a)->fin_pos == (*a)->fwd->fin_pos + 1
			|| is_max_min_order(a, *a, s) == 2))
			{
				if (*b && (*b)->fwd && (*b)->num < (*b)->fwd->num)
					swap(a, b, 3);
				else
					swap(a, NULL, 1);
			}
		srtd_but_err(a, *a, inputs, s);
		if (is_sorted(a) && !*b)
			break ;
		// if ((*a)->num > (*a)->fwd->num && !(is_max_min_order(a, *a, s)))
			// push(a, b, 1);
		cur = *a;
		while (cur->fwd)
		{
			if ((cur->fin_pos > cur->fwd->fin_pos && !(is_max_min_order(a, cur, s)))
				|| (*b && cur->fin_pos == (*b)->fin_pos + 1))
				break ;
			rotate_steps++;
			cur = cur->fwd;
		}
		while (cur->fwd)
			cur = cur->fwd;
		if (cur->fin_pos < (*a)->fin_pos || cur->num == s.max)
		{
			while (cur->bwd)
			{
				if ((cur->bwd->fin_pos > cur->fin_pos
					&& !(cur->bwd->num == s.max && cur->num == s.min))
					|| (*b && cur->fin_pos == (*b)->fin_pos + 1))
					break ;
				rev_rotate_steps++;
				cur = cur->bwd;
			}
		}
					if (switch_var2 == 1)
					{
					t_stack *tmp_a = *a;
					printf("\n");
					while (tmp_a)
					{
						printf("%lld ", tmp_a->num);
						tmp_a = tmp_a->fwd;
					}
					printf("\n");
					t_stack *tmp_b = *b;
					while (tmp_b)
					{
						printf("%lld ", tmp_b->num);
						tmp_b = tmp_b->fwd;
					}
					printf("\n");
					printf("%d,%d\n", rotate_steps, rev_rotate_steps);
					}
		if (rotate_steps < rev_rotate_steps)
			while (--rotate_steps > -1)
			{
				if (count_nodes(*b) == 2 && (*b)->num < (*b)->fwd->num)
					rotate(a, b, 3);
				else
					rotate(a, NULL, 1);
			}
		else
			while (--rev_rotate_steps > -1)
			{
				if (count_nodes(*b) == 2 && (*b)->num < (*b)->fwd->num)
					rev_rotate(a, b, 3);
				else
					rev_rotate(a, NULL, 1);
			}
		if ((*a)->fin_pos == (*a)->fwd->fin_pos + 1
			|| is_max_min_order(a, *a, s) == 2)
			swap(a, NULL, 1);
		else
			push(a, b, 1);
		if (*b && (*a)->fin_pos == (*b)->fin_pos + 1)
			push(b, a, 2);
	}
	// empty_b(a, b, s);
	// srtd_but_err(a, *a, inputs, s);
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
	t_stack	*head;
	int		max_num;
	int		min_num;

	head = node;
	max_num = max_nbr(node);
	min_num = min_nbr(node);
	if (!node->fwd)
		return (1);
	if (num_of_nodes == -1)
		num_of_nodes = count_nodes(node);
	// if (num_of_nodes == -1)
	// {
	// 	while (node->fwd)
	// 	{
	// 		if (node->num > node->fwd->num && !(node->num == max_num
	// 			&& node->fwd->num == min_num))
	// 			return (0);
	// 		node = node->fwd;
	// 	}
	// 	if (node->num > head->num && !(node->num == max_num
	// 			&& head->num == min_num))
	// 		return (0);
	// }
	// else
	while (node->fwd && --num_of_nodes > -1)
	{
		if (node->num > node->fwd->num && !(node->num == max_num
			&& node->fwd->num == min_num))
			return (0);
		node = node->fwd;
	}
	if (!node->fwd && node->num > head->num && !(node->num == max_num
		&& head->num == min_num))
		return (0);
	return (1);
}

void sort_stack(t_stack **a, t_stack **b, int inputs)
{
	t_stack_num s;

	s.max = max_nbr(*a);
	if (inputs == 3)
	{
		sort_stack_ct_3(a);
		return ;
	}
	s.min = min_nbr(*a);
	srtd_but_err(a, *a, inputs, s);
	if (inputs > 3 && inputs < 6)
	{
		if (((*a)->fin_pos > (*a)->fwd->fin_pos
			&& !((*a)->num == s.max && (*a)->fwd->num == s.min))
			|| ((*a)->num == s.min && (*a)->fwd->num == s.max))
			swap(a, NULL, 1);
		srtd_but_err(a, *a, inputs, s);
		sort_alg_1(a, b, s, inputs);
		return ;
	}
	if (inputs > 5)
		sort_alg_2(a, b, s, inputs);
		// sort_alg_3(a, b, s, inputs);
}
