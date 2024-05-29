/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:36:13 by chon              #+#    #+#             */
/*   Updated: 2024/05/29 14:54:06 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_fin_pos_in_node(t_stack *cur, int node_pos)
{
	if (node_pos < 0)
	{
		while (cur->fwd)
			cur = cur->fwd;
		while (cur->bwd && ++node_pos < 0)
			cur = cur->bwd;
	}
	else
	{
		while (node_pos > 0)
		{
			cur = cur->fwd;
			node_pos--;
		}
	}
	return (cur->fin_pos);
}

int	find_num_in_node(t_stack *cur, int node_pos)
{
	if (node_pos == -1)
		while (cur->fwd)
			cur = cur->fwd;
	else
	{
		while (node_pos > 0)
		{
			cur = cur->fwd;
			node_pos--;
		}
	}
	return (cur->num);
}

int	find_final_pos_of_num(t_stack *cur, int nbr)
{
	while (cur && cur->num != nbr)
		cur = cur->fwd;
	if (!cur)
		return (-1);
	return (cur->fin_pos);
}

long	idx_of_num(t_stack *cur, int nbr)
{
	long	position;

	position = 0;
	while (cur && cur->num != nbr)
	{
		position++;
		cur = cur->fwd;
	}
	if (!cur)
		position = 2147483648;
	return (position);
}

long	idx_of_fin_pos(t_stack *cur, int fin_position)
{
	long	position;

	position = 0;
	while (cur && cur->fin_pos != fin_position)
	{
		position++;
		cur = cur->fwd;
	}
	if (!cur)
		position = 2147483648;
	return (position);
}
