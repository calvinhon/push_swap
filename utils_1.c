/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:30:30 by chon              #+#    #+#             */
/*   Updated: 2024/06/03 15:21:46 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_nbr(t_stack *cur)
{
	int	min_num;

	min_num = cur->num;
	while (cur)
	{
		if (cur->num < min_num)
			min_num = cur->num;
		cur = cur->fwd;
	}
	return (min_num);
}

int	max_nbr(t_stack *cur)
{
	int	max_num;

	max_num = cur->num;
	while (cur)
	{
		if (cur->num > max_num)
			max_num = cur->num;
		cur = cur->fwd;
	}
	return (max_num);
}

t_stack	*new_node(int nbr, int position)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->num = nbr;
	node->fin_pos = position;
	node->bwd = NULL;
	node->fwd = NULL;
	return (node);
}
