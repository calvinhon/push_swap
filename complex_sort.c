/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:01:09 by chon              #+#    #+#             */
/*   Updated: 2024/05/29 15:34:23 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int switch_var2 = 0;

void	rotate_two_stacks(t_stack **from, t_stack **to, t_helper h, int order)
{
	h.order_to = h.best_shift_to > 0;
	h.order_from = h.best_shift_from > 0;
	if (h.best_rotate_switch == 0)
	{
		h.best_shift_to = ft_abs(h.best_shift_to);
		h.best_shift_from = ft_abs(h.best_shift_from);
		while (--h.best_shift_to > -1)
			rotate_choose(to, NULL, 1 - min(0, order), h.order_to);
		while (--h.best_shift_from > -1)
			rotate_choose(from, NULL, 1 + max(0, order), h.order_from);
	}
	else
	{
		h.rotate_both = min(ft_abs(h.best_shift_to), ft_abs(h.best_shift_from));
		while (--h.rotate_both > -1)
			rotate_choose(from, to, 3, h.order_to);
		h.rotate = ft_abs(h.best_shift_to - h.best_shift_from);
		while (--h.rotate > -1)
		{
			if (ft_abs(h.best_shift_to) > ft_abs(h.best_shift_from))
				rotate_choose(to, NULL, 1 - min(0, order), h.order_to);
			else
				rotate_choose(from, NULL, 1 + max(0, order), h.order_to);
		}
	}
}

void	find_best_moves(t_helper *h)
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

void	shift_helper(t_stack *from, int order, t_helper *h)
{
	while (h->c_to)
	{
		if (order == -1)
		{
			h->shift_to++;
			if (h->c_to->fwd && ((from->num > h->max_to && h->c_to->num
						== h->min_to && h->c_to->fwd->num == h->max_to)
					|| ((from->num < h->c_to->num
							&& from->num > h->c_to->fwd->num))
					|| (from->num < h->min_to
						&& h->c_to->fwd->num == h->max_to)))
				break ;
		}
		else
		{
			if ((from->num > h->max_to && h->c_to->num == h->min_to)
				|| (h->c_to->bwd && ((from->num < h->min_to
							&& h->c_to->bwd->num == h->max_to)
						|| (from->num > h->c_to->bwd->num
							&& from->num < h->c_to->num))))
				break ;
			h->shift_to++;
		}
		h->c_to = h->c_to->fwd;
	}
}

// void	shift_helper2(t_stack *from, int order, t_helper *h)
// {
// 	if (find_final)
// }

void	empty_stack(t_stack **from, t_stack **to, int order, t_helper h)
{
	h.c_from = *from;
	h.node_from = 0;
	h.length_from = count_nodes(*from);
	h.length_to = count_nodes(*to);
	while (h.c_from)
	{
		h.shift_to = 0;
		h.c_to = *to;
		h.min_to = min_nbr(*to);
		h.max_to = max_nbr(*to);
		// shift_helper(h.c_from, order, &h);
		// if (h.c_from->num == h.min && idx_of_num(*to, h.max) != -1)
		// 	h.shift_to = idx_of_num(*to, h.max);
		// if (h.c_from->num == h.max && idx_of_num(*to, h.min) != -1)
		if (h.c_from->num == h.min)
			h.shift_to = min(idx_of_num(*to, h.max) + max(0, order), idx_of_fin_pos(*to, 1));
		else if (h.c_from->num == h.max)
			h.shift_to = min(idx_of_num(*to, h.min), idx_of_fin_pos(*to, h.c_from->fin_pos - 1) + max(0, order));
		else
			h.shift_to = min(idx_of_fin_pos(*to, h.c_from->fin_pos + 1) - min(0, order), idx_of_fin_pos(*to, h.c_from->fin_pos - 1) + max(0, order));
		// printf("shift_to:%ld\n", h.shift_to);
		if (h.shift_to < 2147483648)
		{
			if (h.shift_to > round(h.length_to / 2))
				h.shift_to = -h.length_to + h.shift_to;
			h.shift_from = h.node_from;
			if (h.node_from > round(h.length_from / 2))
				h.shift_from = -h.length_from + h.node_from;
			find_best_moves(&h);
		}
		if (h.best_combined_moves < 1)
			break ;
		h.node_from++;
		h.c_from = h.c_from->fwd;
	}
	(void)order;
	rotate_two_stacks(from, to, h, order);
	push(from, to, 1 + max(0, order));
	if (switch_var2 == 1)
	{
		t_stack *tmp_a = *from;
		printf("\n");
		while (tmp_a)
		{
			printf("%lld ", tmp_a->num);
			tmp_a = tmp_a->fwd;
		}
		printf("\n");
		printf("\n");
		t_stack *tmp_b = *to;
		while (tmp_b)
		{
			printf("%lld ", tmp_b->num);
			tmp_b = tmp_b->fwd;
		}
		printf("\n");
	}
}

void	complex_sort_alg(t_stack **a, t_stack **b, t_stack_num s, int inputs)
{
	t_helper	h;
	
	h.min = min_nbr(*a);
	h.max = max_nbr(*a);
	push(a, b, 1);
	push(a, b, 1);
	if ((*b)->num < (*b)->fwd->num || is_max_min_order(b, *b, s, 'f'))
	{
		if ((*a)->num > (*a)->fwd->num || is_max_min_order(a, *a, s, 'f') == 2)
			swap(a, b, 3);
		else
			swap(b, NULL, 2);
	}
	while (count_nodes(*a) > 3)
	{
		h.best_combined_moves = 2147483647;
		empty_stack(a, b, -1, h);
	}
	sort_stack_ct_3(a);
	while (*b)
	{
		h.best_combined_moves = 2147483647;
		empty_stack(b, a, 1, h);
	}
	srtd_but_err(a, *a, inputs, s);
}
