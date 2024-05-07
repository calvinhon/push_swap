/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:30:30 by chon              #+#    #+#             */
/*   Updated: 2024/05/07 14:12:44 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *cur)
{
	int		max_num;

	max_num = cur->num;
	while (cur)
	{
		if (cur->num > max_num)
			max_num = cur->num;
		cur = cur->fwd;
	}
	return (max_num);
}

void	free_stack(t_stack **lst)
{
	if (*lst)
	{
		while ((*lst)->fwd)
			*lst = (*lst)->fwd;
		while ((*lst)->bwd)
		{
			*lst = (*lst)->bwd;
			free((*lst)->fwd);
		}
		free(*lst);
	}
}

t_stack	*del_first_node(t_stack *top)
{
	t_stack	*new_top;

	if (!top || !top->fwd)
		return (NULL);
	new_top = top->fwd;
	new_top->bwd = NULL;
	free(top);
	return (new_top);
}

void	add(t_stack **head, t_stack *new_node, int position)
{
	t_stack	*cur;

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

t_stack	*new_node(int nbr)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->num = nbr;
	node->bwd = NULL;
	node->fwd = NULL;
	return (node);
}
