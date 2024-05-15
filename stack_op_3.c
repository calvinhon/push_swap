/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:00:46 by chon              #+#    #+#             */
/*   Updated: 2024/05/15 14:09:07 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	find_first_err(t_stack *head, t_stack *cur, int min_num, int max_num)
// {
// 	int	node;

// 	node = 0;
// 	while (cur->fwd && is_wrong_order(head, cur, min_num, max_num) == 0)
// 	{
// 		node++;
// 		cur = cur->fwd;
// 	}
// 	return (node);
// }

int is_sorted(t_stack **stack)
{
	t_stack *cur;

	cur = *stack;
	while (cur->fwd)
	{
		if (cur->fin_pos != cur->fwd->fin_pos - 1)
			return (0);
		cur = cur->fwd;
	}
	return (1);
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

void print_action(int action, int stack_id)
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
}

void fill_final_pos(int *fin_pos, int *inputs, int num_of_inputs)
{
	int i;
	int j;
	int prior_position;
	int greater_switch;

	i = -1;
	j = 0;
	greater_switch = 0;
	while (num_of_inputs > 1)
	{
		j++;
		while (++i < j)
		{
			if (inputs[j] > inputs[i])
			{
				if (fin_pos[i] > prior_position)
					prior_position = fin_pos[i];
				greater_switch = 1;
			}
			else
				fin_pos[i]++;
		}
		if (greater_switch)
			fin_pos[j] = prior_position + 1;
		prior_position = 0;
		greater_switch = 0;
		i = -1;
		num_of_inputs--;
	}
}

void srtd_but_err(t_stack **a, t_stack *cur, int inputs, t_stack_num s)
{
	int reverse_switch;

	reverse_switch = 1;
	if (cur->fin_pos < round((double)inputs / 2))
		reverse_switch = 2;
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
	// int trigger = 0;
	if (reverse_switch == 1)
		while (!is_sorted(a))
		{
			rotate(a, NULL, 1);
			// trigger++;
			// if (trigger == 6)
			// 	break;
		}
	if (reverse_switch == 2)
		while (!is_sorted(a))
		{
			rev_rotate(a, NULL, 1);
			// trigger++;
			// if (trigger == 6)
			// 	break;
		}
	t_stack *cur_a = *a;
	printf("\n");
	while (cur_a)
	{
		printf("%lld ", cur_a->num);
		cur_a = cur_a->fwd;
	}
	printf("\n");
	return ;
}
