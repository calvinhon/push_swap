/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:36:13 by chon              #+#    #+#             */
/*   Updated: 2024/05/21 16:15:39 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_fin_pos_in_node(t_stack *cur, int node_pos)
{
	if (node_pos < 0)
	{
		while (cur->fwd)
			cur = cur->fwd;
		while (cur->bwd && ++node_pos < 0)
			cur = cur->bwd;
	}
	else
		while (node_pos > 0)
		{
			cur = cur->fwd;
			node_pos--;
		}
	return (cur->fin_pos);
}


int find_num_in_node(t_stack *cur, int node_pos)
{
	if (node_pos == -1)
		while (cur->fwd)
			cur = cur->fwd;
	else
		while (node_pos > 0)
		{
			cur = cur->fwd;
			node_pos--;
		}
	return (cur->num);
}

int find_final_pos_of_num(t_stack *cur, int nbr)
{
	while (cur && cur->num != nbr)
		cur = cur->fwd;
	return (cur->fin_pos);
}

int find_pos_of_num(t_stack *cur, int nbr)
{
	int position;

	position = 0;
	while (cur && cur->num != nbr)
	{
		position++;
		cur = cur->fwd;
	}
	return (position);
}

int find_pos_of_final_pos(t_stack *cur, int fin_position)
{
	int position;

	position = 0;
	while (cur && cur->fin_pos != fin_position)
	{
		position++;
		cur = cur->fwd;
	}
	if (cur->fin_pos != fin_position)
		position = -1;
	return (position);
}
