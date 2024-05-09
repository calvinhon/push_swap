/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:36:13 by chon              #+#    #+#             */
/*   Updated: 2024/05/09 11:49:10 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_of_final_pos(t_stack *cur, int fin_position)
{
	int	position;

	position = 0;
	while (cur && cur->final_position != fin_position)
	{
		position++;
		cur = cur->fwd;
	}
	return (position);
}

int	srtd_but_err(t_stack **a, t_stack *cur, int ac, t_stack_num s)
{
	int	reverse_switch;
	
	reverse_switch = 1;
	if (cur->final_position < round((double) ac / 2))
		reverse_switch = 2;
	while (cur->fwd)
	{
		if (cur->num == s.max)
		{
			if (cur->fwd->num != s.min)
				return (0);
		}
		else if (cur->num > cur->fwd->num)
			return (0);
		cur = cur->fwd;
	}
	int trigger = 0;
	if (reverse_switch == 1)
			while (!is_sorted(a))
			{
				rotate(a, NULL, 1);
							trigger++;
			if (trigger == 6)
				break ;
			}
	if (reverse_switch == 2)
			while (!is_sorted(a))
			{
				rev_rotate(a, NULL, 1);
							trigger++;
			if (trigger == 6)
				break ;
			}
	return (1);
}
