/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:01:09 by chon              #+#    #+#             */
/*   Updated: 2024/05/27 13:33:53 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	moves_to_top(t_stack *head, int fin_pos, int stack_length)
{
	long	moves;

	if (count_nodes(head) == 1)
		return (0);
	moves = find_pos_of_final_pos(head, fin_pos);
	if (moves != -1)
	{
		if (moves > round(stack_length / 2))
			moves = -stack_length + moves;
	}
	else
		moves = 2147483648;
	return (moves);
}
