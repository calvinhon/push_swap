/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:00:46 by chon              #+#    #+#             */
/*   Updated: 2024/05/28 16:04:29 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	call_swap(t_stack *head, t_stack_num s)
{
	return (head->fin_pos == head->fin_pos + 1
		|| is_max_min_order(NULL, head, s, 'f') == 2);
}

int	is_max_min_order(t_stack **stack, t_stack *cur, t_stack_num s, char c)
{
	if (c == 'f' && cur->fwd)
	{
		if (cur->num == s.max && cur->fwd->num == s.min)
			return (1);
		if (cur->num == s.min && cur->fwd->num == s.max)
			return (2);
	}
	else if (c == 'b' && cur->bwd)
	{
		if (cur->num == s.min && cur->bwd->num == s.max)
			return (1);
		if (cur->num == s.max && cur->bwd->num == s.min)
			return (2);
	}
	else if (c == 'e')
	{
		if (cur->num == s.max && (*stack)->num == s.min)
			return (1);
		if (cur->num == s.min && (*stack)->num == s.max)
			return (2);
	}
	return (0);
}

int	count_nodes(t_stack *cur)
{
	int	num_of_nodes;

	num_of_nodes = 0;
	while (cur)
	{
		num_of_nodes++;
		cur = cur->fwd;
	}
	return (num_of_nodes);
}

void	print_action(int action, int stack_id)
{
	if (action == 0)
	{
		if (stack_id == 1)
			ft_printf("sa\n");
		else if (stack_id == 2)
			ft_printf("sb\n");
		else if (stack_id == 3)
			ft_printf("ss\n");
	}
	if (action == 1)
	{
		if (stack_id == 1)
			ft_printf("ra\n");
		else if (stack_id == 2)
			ft_printf("rb\n");
		else if (stack_id == 3)
			ft_printf("rr\n");
	}
	if (action == 2)
	{
		if (stack_id == 2)
			ft_printf("rrb\n");
		else if (stack_id == 3)
			ft_printf("rrr\n");
	}
}

void	srtd_but_err(t_stack **a, t_stack *cur, int inputs, t_stack_num s)
{
	int	rotate_switch;

	rotate_switch = 1;
	if (cur->fin_pos < round((double)inputs / 2))
		rotate_switch = 2;
	while (cur->fwd)
	{
		if (cur->num == s.max)
		{
			if (cur->fwd->num != s.min)
				return ;
		}
		else if (cur->fin_pos != cur->fwd->fin_pos - 1)
			return ;
		cur = cur->fwd;
	}
	if (rotate_switch == 1)
		while (!is_sorted(a))
			rotate(a, NULL, 1);
	if (rotate_switch == 2)
		while (!is_sorted(a))
			rev_rotate(a, NULL, 1);
	return ;
}
