/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:30:30 by chon              #+#    #+#             */
/*   Updated: 2024/05/09 14:09:38 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int min_nbr(t_stack *cur)
{
	int min_num;

	min_num = cur->num;
	while (cur)
	{
		if (cur->num < min_num)
			min_num = cur->num;
		cur = cur->fwd;
	}
	return (min_num);
}

int max_nbr(t_stack *cur)
{
	int max_num;

	max_num = cur->num;
	while (cur)
	{
		if (cur->num > max_num)
			max_num = cur->num;
		cur = cur->fwd;
	}
	return (max_num);
}

t_stack *del_first_node(t_stack *top)
{
	t_stack *new_top;

	if (!top || !(top->fwd))
	{
		free(top);
		return (NULL);
	}
	new_top = top->fwd;
	new_top->bwd = NULL;
	free(top);
	return (new_top);
}

void add(t_stack **head, t_stack *new_node, int position)
{
	t_stack *cur;

	cur = *head;
	if (position == -1)
	{
		while (cur->fwd)
			cur = cur->fwd;
		cur->fwd = new_node;
		new_node->bwd = cur;
	}
	else if (position == 0)
	{
		*head = new_node;
		(*head)->fwd = cur;
		cur->bwd = *head;
	}
}

t_stack *new_node(int nbr, int position)
{
	t_stack *node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->num = nbr;
	node->fin_pos = position;
	node->bwd = NULL;
	node->fwd = NULL;
	return (node);
}
