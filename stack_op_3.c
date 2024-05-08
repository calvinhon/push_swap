/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:00:46 by chon              #+#    #+#             */
/*   Updated: 2024/05/08 16:01:28 by chon             ###   ########.fr       */
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

// int	count_nodes(t_stack *cur)
// {
// 	int	num_of_nodes;

// 	num_of_nodes = 0;
// 	while (cur)
// 	{
// 		num_of_nodes++;
// 		cur = cur->fwd;
// 	}
// 	return (num_of_nodes);
// }

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
}

void	find_final_pos(int *final_positions, int *inputs, int num_of_inputs)
{
	int	i;
	int	j;
	int	prior_position;
	int	greater_switch;

	i = -1;
	j = 0;
	greater_switch = 0;
	while (num_of_inputs > 1)
	{
		j++;
		while (++i < j)
		{s
			if (inputs[j] > inputs[i])
			{
				if (final_positions[i] > prior_position)
					prior_position = final_positions[i];
				greater_switch = 1;
			}
			else
				final_positions[i]++;
		}
		if (greater_switch)
			final_positions[j] = prior_position + 1;
		prior_position = 0;
		greater_switch = 0;
		i = -1;
		num_of_inputs--;
	}
}

int	find_final_pos_of_num(t_stack *cur, int nbr)
{
	while (cur && cur->num != nbr)
		cur = cur->fwd;
	return (cur->final_position);
}

int	find_pos_of_num(t_stack *cur, int nbr)
{
	int	position;

	position = 0;
	while (cur && cur->num != nbr)
	{
		position++;
		cur = cur->fwd;
	}
	return (position);
}

int	find_min(t_stack *cur)
{
	int		min_num;

	min_num = cur->num;
	while (cur)
	{
		if (cur->num < min_num)
			min_num = cur->num;
		cur = cur->fwd;
	}
	return (min_num);
}
