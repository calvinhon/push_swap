/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:00:46 by chon              #+#    #+#             */
/*   Updated: 2024/05/06 16:38:38 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_first_err(t_stack *head, t_stack *cur, int min_num, int max_num)
{
	int	node_num;
	
	node_num = 0;
	while (cur->fwd && is_wrong_order(head, cur, min_num, max_num) == 0)
	{
		node_num++;
		cur = cur->fwd;
	}
	return (node_num);
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
