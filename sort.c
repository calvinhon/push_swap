/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:49:51 by chon              #+#    #+#             */
/*   Updated: 2024/05/03 12:57:05 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int inputs)
{
	int		max_num;

	if (*stack_a)
		(*stack_a)->num = (*stack_a)->num * 1;
	if (*stack_b)
		(*stack_b)->num = (*stack_b)->num * 1;
	if (inputs == 2)
	{
		swap(stack_a, stack_b, 1);
		return ;
	}
	max_num = find_max(*stack_a);
	if (inputs == 3)
	{
		if (node_num(*stack_a, 0) == max_num)
			rotate(stack_a, stack_b, 1);
		else if (node_num(*stack_a, 1) == max_num)
			rev_rotate(stack_a, stack_b, 1);
		if (is_sorted(stack_a) == 0)
			swap(stack_a, stack_b, 1);
	}
	// printf("sort\n");
}
