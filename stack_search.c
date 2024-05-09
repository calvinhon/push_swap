/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:36:13 by chon              #+#    #+#             */
/*   Updated: 2024/05/09 14:19:21 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_num_in_node(t_stack *cur, int node_pos)
{
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
	return (position);
}
