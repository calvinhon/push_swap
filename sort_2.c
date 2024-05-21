/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:01:09 by chon              #+#    #+#             */
/*   Updated: 2024/05/21 17:20:04 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	moves_to_top(t_stack *head, int fin_pos, int stack_length)
{
	int	moves;

	moves = find_pos_of_final_pos(head, fin_pos);
	if (moves != -1)
	{
		if (moves > round(stack_length / 2))
			moves = -(stack_length - moves + 1);
	}
	else
		moves = 2147483648;
	return (moves);
}
