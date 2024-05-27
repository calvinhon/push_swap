/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:49:51 by chon              #+#    #+#             */
/*   Updated: 2024/05/27 16:07:47 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int switch_var2 = 0;

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
		while (*b && ((*b)->fin_pos == (*a)->fin_pos - 1 || ((*b)->num == s.max && (*a)->num == s.min)))
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
			h.shift_a_to_pa = moves_to_top(*a, h.search_fin_pos, h.length_a);
			h.shift_b_to_pa = moves_to_top(*b,
										   find_fin_pos_in_node(*b, h.node_b_to_move), count_nodes(*b));
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
				if (ft_abs(h.combined_moves) > 0 && ft_abs(h.combined_moves) < ft_abs(h.best_combined_moves))
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

int shift_helper(t_stack *cur_from, t_stack **to, int order)
{
	t_helper h;

	h.cur_to = *to;
	h.shift_to = 0;
	if (!order)
		while (h.cur_to)
		{
			if (cur_from->num < min_nbr(*to) && h.cur_to->num == max_nbr(*to))
				break;
			h.shift_to++;
			if (cur_from->num > max_nbr(*to) && h.cur_to->num == min_nbr(*to) && h.cur_to->fwd && h.cur_to->fwd->num == max_nbr(*to))
				break;
			else if (h.cur_to->fwd && cur_from->num < h.cur_to->num && cur_from->num > h.cur_to->fwd->num)
				break;
			h.cur_to = h.cur_to->fwd;
		}
	return (h.shift_to);
}

void find_best_moves(t_helper *h)
{
	if (h->shift_to > 0 && h->shift_from > 0)
	{
		h->combined_moves = max(h->shift_to, h->shift_from);
		h->rotate_switch = 1;
	}
	else if (h->shift_to < 0 && h->shift_from < 0)
	{
		h->combined_moves = min(h->shift_to, h->shift_from);
		h->rotate_switch = -1;
	}
	else
	{
		h->combined_moves = ft_abs(h->shift_to) + ft_abs(h->shift_from);
		h->rotate_switch = 0;
	}
	if (ft_abs(h->combined_moves) < ft_abs(h->best_combined_moves))
	{
		h->best_rotate_switch = h->rotate_switch;
		h->best_combined_moves = h->combined_moves;
		h->best_shift_to = h->shift_to;
		h->best_shift_from = h->shift_from;
		h->best_node_from = h->node_from;
	}
	if (switch_var2 == 1)
	{
		printf("current | node_a:%d shift_a:%ld shift_b:%ld combined:%d switch:%d\n", h->node_from, h->shift_from, h->shift_to, h->combined_moves, h->rotate_switch);
		printf("best | node_a:%d shift_a:%d shift_b:%d combined:%ld switch:%d\n", h->best_node_from, h->best_shift_from, h->best_shift_to, h->best_combined_moves, h->rotate_switch);
	}
}

void rotate_two_stacks(t_stack **from, t_stack **to, t_helper h)
{
	h.flip_from = -1;
	h.flip_to = -1;
	if (h.best_shift_from > 0)
		h.flip_from = 1;
	if (h.best_shift_to > 0)
		h.flip_to = 1;	
	if (h.best_rotate_switch == 0)
	{
		h.best_shift_to = ft_abs(h.best_shift_to);
		h.best_shift_from = ft_abs(h.best_shift_from);
			while (--h.best_shift_to > -1)
				rotate_choose(to, NULL, 2, );
		else
			while (++h.best_shift_to < 1)
				rev_rotate(to, NULL, 2);
		if (h.best_shift_from > 0)
			while (--h.best_shift_from > -1)
				rotate(from, NULL, 1);
		else
			while (++h.best_shift_from < 1)
				rev_rotate(from, NULL, 1);
		// if (h.best_shift_to > 0)
		// 	while (--h.best_shift_to > -1)
		// 		rotate(to, NULL, 2);
		// else
		// 	while (++h.best_shift_to < 1)
		// 		rev_rotate(to, NULL, 2);
		// if (h.best_shift_from > 0)
		// 	while (--h.best_shift_from > -1)
		// 		rotate(from, NULL, 1);
		// else
		// 	while (++h.best_shift_from < 1)
		// 		rev_rotate(from, NULL, 1);
	}
	else
	{
		if (h.best_rotate_switch == 1)
		{
			h.simult_rotate = min(ft_abs(h.best_shift_to), ft_abs(h.best_shift_from));
			while (--h.simult_rotate > -1)
				rotate_choose(from, to, 3, h.best_rotate_switch);
			h.rotate = ft_abs(h.best_shift_to - h.best_shift_from);
			while (--h.rotate > -1)
			{
				if ((h.best_rotate_switch && h.best_shift_to > h.best_shift_from)
					|| (h.best_rotate_switch == -1 && h.best_shift_to < h.best_shift_from))
					rotate_choose(to, NULL, 2, h.best_rotate_switch);
				else
					rotate_choose(from, NULL, 1, h.best_rotate_switch);
			}
		}
		else
		{
			h.simult_rotate = max(h.best_shift_to, h.best_shift_from);
			while (++h.simult_rotate < 1)
				rev_rotate(from, to, 3);
			h.rotate = -ft_abs(h.best_shift_to - h.best_shift_from);
			while (++h.rotate < 1)
			{
				if (h.best_shift_to < h.best_shift_from)
					rev_rotate(to, NULL, 2);
				else
					rev_rotate(from, NULL, 1);
			}
		}
	}
}

void empty_stack(t_stack **from, t_stack **to, int order)
{
	t_helper h;

	h.cur_from = *from;
	h.node_from = 0;
	h.best_combined_moves = 2147483647;
	while (h.cur_from)
	{
		h.length_from = count_nodes(*from);
		h.length_to = count_nodes(*to);
		h.shift_to = shift_helper(h.cur_from, to, order);
		if (h.shift_to > round(h.length_to / 2))
			h.shift_to = -h.length_to + h.shift_to;
		if (h.node_from > round(h.length_from / 2))
			h.shift_from = -h.length_from + h.node_from;
		else
			h.shift_from = h.node_from;
		find_best_moves(&h);
		h.node_from++;
		h.cur_to = *to;
		h.cur_from = h.cur_from->fwd;
	}
	rotate_two_stacks(from, to, h);
	push(from, to, 1);
}

void complex_sort_alg(t_stack **a, t_stack **b, t_stack_num s, int inputs)
{
	push(a, b, 1);
	push(a, b, 1);
	while (count_nodes(*a) > 3)
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
		empty_stack(a, b, 0);
	}
	sort_stack_ct_3(a);
	empty_b(a, b, s);
	srtd_but_err(a, *a, inputs, s);
}

void simple_sort_alg(t_stack **a, t_stack **b, t_stack_num s, int inputs)
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
		if (((*a)->fin_pos > (*a)->fwd->fin_pos && !((*a)->num == s.max && (*a)->fwd->num == s.min)) || ((*a)->num == s.min && (*a)->fwd->num == s.max))
			swap(a, NULL, 1);
		srtd_but_err(a, *a, inputs, s);
		simple_sort_alg(a, b, s, inputs);
		return;
	}
	if (inputs > 5)
		complex_sort_alg(a, b, s, inputs);
}
