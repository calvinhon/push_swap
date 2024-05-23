/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:01:09 by chon              #+#    #+#             */
/*   Updated: 2024/05/22 15:44:55 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	moves_to_top(t_stack *head, int fin_pos, int stack_length)
{
	long	moves;

	if (count_nodes(head) == 1)
		return (0);
	moves = find_pos_of_final_pos(head, fin_pos);
	if (moves != -1)
	{
		if (moves > round(stack_length / 2))
			moves = -stack_length + moves;
	}
	else
		moves = 2147483648;
	return (moves);
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
