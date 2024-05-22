/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:49:51 by chon              #+#    #+#             */
/*   Updated: 2024/05/22 16:31:43 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int switch_var2 = 1;

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

void sort_alg_3(t_stack **a, t_stack **b, t_stack_num s, int inputs)
{
	int position;
	int rotate_switch;

	(void)s;
	rotate_switch = 1;
	position = 0;
	while (position < inputs - 2)
	{
		if (find_pos_of_final_pos(*a, position) > round((double)count_nodes(*a) / 2))
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

void empty_b2(t_stack **a, t_stack **b, t_stack_num s)
{
	int ra_to_pa_top;
	int rra_to_pa_top;
	t_stack *cur_a;

	if (find_fin_pos_in_node(*b, -1) == find_fin_pos_in_node(*a, -1) - 1)
	{
		rev_rotate(a, b, 3);
		push(b, a, 2);
	}
	while (*b)
	{
		cur_a = *a;
		ra_to_pa_top = 0;
		rra_to_pa_top = 1;
		while (cur_a->fwd && *b && (((*b)->num != s.max && (cur_a->fin_pos != (*b)->fin_pos + 1)) || ((*b)->num == s.max && cur_a->num != s.min)))
		{
			ra_to_pa_top++;
			cur_a = cur_a->fwd;
		}
		while (cur_a->fwd)
			cur_a = cur_a->fwd;
		while (cur_a->bwd && *b && (((*b)->num != s.max && (cur_a->fin_pos != (*b)->fin_pos + 1)) || ((*b)->num == s.max && cur_a->num != s.min)))
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
		while (*b && ((*b)->fin_pos == (*a)->fin_pos - 1 || ((*b)->num == s.max && (*a)->num == s.min)))
			push(b, a, 2);
	}
}

void empty_b(t_stack **a, t_stack **b, t_stack_num s)
{
	t_stack *cur_b;
	t_helper h;

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
		while (*b && ((*b)->fin_pos == (*a)->fin_pos - 1
			|| ((*b)->num == s.max && (*a)->num == s.min)))
			push(b, a, 2);
		cur_b = *b;
		h.rotate_switch = 0;
		h.node_b_to_move = 0;
		h.best_node_b_to_move = 0;
		h.shift_a_to_pa = 0;
		h.best_shift_a_to_pa = 0;
		h.shift_b_to_pa = 0;
		h.best_shift_b_to_pa = 0;
		h.combined_moves = 0;
		h.best_combined_moves = 2147483647;
		h.length_a = count_nodes(*a);
		while (cur_b)
		{
			if (cur_b->num == s.max)
				h.search_fin_pos = 0;
			else
				h.search_fin_pos = cur_b->fin_pos + 1;
			// printf("find_pos:%d\n", h.search_fin_pos);
			h.shift_a_to_pa = moves_to_top(*a, h.search_fin_pos, h.length_a);
			// printf("%ld, %d, %d\n", h.shift_a_to_pa, h.search_fin_pos, h.length_a);
			h.shift_b_to_pa = moves_to_top(*b,
			   find_fin_pos_in_node(*b, h.node_b_to_move), count_nodes(*b));
			// if (h.shift_a_to_pa == 2147483648)
			// 	h.initiate_tracker++;
			if (h.shift_a_to_pa < 2147483648)
			{
				if (h.shift_a_to_pa > 0 && h.shift_b_to_pa > 0)
				{
					h.combined_moves = max(h.shift_a_to_pa, h.shift_b_to_pa);
					h.rotate_switch = 1;
				}
				else if (h.shift_a_to_pa < 0 && h.shift_b_to_pa < 0)
				{
					h.combined_moves = min(h.shift_a_to_pa, h.shift_b_to_pa);
					h.rotate_switch = 2;
				}
				// else if (!h.shift_a_to_pa || !h.shift_b_to_pa)
				// 	h.combined_moves = h.shift_a_to_pa + h.shift_b_to_pa;
				else
				{
					h.combined_moves = ft_abs(h.shift_a_to_pa) + ft_abs(h.shift_b_to_pa);
					h.rotate_switch = 0;
				}
				if (ft_abs(h.combined_moves) > 0
					&& ft_abs(h.combined_moves) < ft_abs(h.best_combined_moves))
				{
					h.best_node_b_to_move = h.node_b_to_move;
					h.best_shift_a_to_pa = h.shift_a_to_pa;
					h.best_shift_b_to_pa = h.shift_b_to_pa;
					h.best_combined_moves = h.combined_moves;
					h.best_rotate_switch = h.rotate_switch;
				}
			}
			if (switch_var2 == 1)
			{
			printf("current | node_b:%d shift_a:%ld shift_b:%d combined:%d switch:%d\n", h.node_b_to_move, h.shift_a_to_pa, h.shift_b_to_pa, h.combined_moves, h.rotate_switch);
			printf("best | node_b:%d shift_a:%d shift_b:%d combined:%ld switch:%d\n", h.best_node_b_to_move, h.best_shift_a_to_pa, h.best_shift_b_to_pa, h.best_combined_moves, h.rotate_switch);
			}
			h.node_b_to_move++;
			cur_b = cur_b->fwd;
		}
		// printf("rotate_switch:%d\n", h.rotate_switch);
		if (h.best_rotate_switch == 0)
		{
			if (h.best_shift_a_to_pa > 0)
				while (--h.best_shift_a_to_pa > -1)
					rotate(a, NULL, 1);
			else
				while (++h.best_shift_a_to_pa < 1)
					rev_rotate(a, NULL, 1);
			if (h.best_shift_b_to_pa > 0)
				while (--h.best_shift_b_to_pa > -1)
					rotate(b, NULL, 2);
			else
				while (++h.best_shift_b_to_pa < 1)
					rev_rotate(b, NULL, 2);
		}
		else if (h.best_rotate_switch == 1)
		{
			h.simult_rotate = min(h.best_shift_a_to_pa, h.best_shift_b_to_pa);
			while (--h.simult_rotate > -1)
				rotate(a, b, 3);
			h.simult_rotate = ft_abs(h.best_shift_a_to_pa - h.best_shift_b_to_pa);
			while (--h.simult_rotate > -1)
			{
				if (h.best_shift_a_to_pa > h.best_shift_b_to_pa)
					rotate(a, NULL, 1);
				else
					rotate(b, NULL, 2);
			}
		}
		else
		{
			h.simult_rotate = max(h.best_shift_a_to_pa, h.best_shift_b_to_pa);
			while (++h.simult_rotate < 1)
				rev_rotate(a, b, 3);
			h.simult_rotate = ft_abs(h.best_shift_a_to_pa - h.best_shift_b_to_pa);
			while (++h.simult_rotate < 1)
			{
				if (h.best_shift_a_to_pa < h.best_shift_b_to_pa)
					rev_rotate(a, NULL, 1);
				else
					rev_rotate(b, NULL, 2);
			}
		}
	}
}

void sort_alg_2(t_stack **a, t_stack **b, t_stack_num s, int inputs)
{
	int rotate_steps;
	int rev_rotate_steps;
	t_stack *cur;

	(void)inputs;
	if ((*a)->fin_pos > (*a)->fwd->fin_pos + 1 && !is_max_min_order(a, *a, s))
		push(a, b, 1);
	while (!is_ordered(*a, -1))
	{
		rotate_steps = 1;
		rev_rotate_steps = 1;
		if (((*a)->fin_pos == (*a)->fwd->fin_pos + 1 || is_max_min_order(a, *a, s) == 2))
		{
			if (*b && (*b)->fwd && (*b)->num < (*b)->fwd->num)
				swap(a, b, 3);
			else
				swap(a, NULL, 1);
		}
		srtd_but_err(a, *a, inputs, s);
		if (is_sorted(a) && !*b)
			break;
		// if ((*a)->num > (*a)->fwd->num && !(is_max_min_order(a, *a, s)))
		// push(a, b, 1);
		cur = *a;
		while (cur->fwd)
		{
			if ((cur->fin_pos > cur->fwd->fin_pos && !(is_max_min_order(a, cur, s))) || (*b && cur->fin_pos == (*b)->fin_pos + 1))
				break;
			rotate_steps++;
			cur = cur->fwd;
		}
		while (cur->fwd)
			cur = cur->fwd;
		if (cur->fin_pos < (*a)->fin_pos || cur->num == s.max)
		{
			while (cur->bwd)
			{
				if ((cur->bwd->fin_pos > cur->fin_pos && !(cur->bwd->num == s.max && cur->num == s.min)) || (*b && cur->fin_pos == (*b)->fin_pos + 1))
					break;
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
		if ((*a)->fin_pos == (*a)->fwd->fin_pos + 1 || is_max_min_order(a, *a, s) == 2)
			swap(a, NULL, 1);
		else if ((*a)->fin_pos != (*a)->fwd->fin_pos - 1)
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
		while (*b && ((*a)->fin_pos == (*b)->fin_pos + 1 || ((*a)->num == s.min && (*b)->num == s.max)))
			push(b, a, 2);
		if (*b)
		{
			if (find_pos_of_final_pos(*a, (*b)->fin_pos + 1) < round((double)count_nodes(*a) / 2))
				rotate(a, NULL, 1);
			else
				rev_rotate(a, NULL, 1);
		}
	}
	srtd_but_err(a, *a, inputs, s);
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

	s.max = max_nbr(*a);
	if (inputs == 3)
	{
		sort_stack_ct_3(a);
		return;
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
		return;
	}
	if (inputs > 5)
		sort_alg_2(a, b, s, inputs);
	// sort_alg_3(a, b, s, inputs);
	srtd_but_err(a, *a, inputs, s);
}
