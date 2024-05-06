/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:49:51 by chon              #+#    #+#             */
/*   Updated: 2024/05/06 16:41:02 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_wrong_order(t_stack *head, t_stack *cur, int min_num, int max_num)
{
	if (cur->fwd)
		return ((cur->num != max_num && cur->num > cur->fwd->num)
			|| (cur->num == max_num && cur->fwd->num != min_num));
	else
		return ((cur->num != max_num && cur->num < head->num)
			|| (cur->num == max_num && !(cur->bwd->num == min_num
			|| head->num == min_num)));
}

int	ct_wrong_order(t_stack *head, t_stack *cur, int min_num, int max_num)
{
	int		count;

	count = 0;
	while (cur->fwd)
	{
		if (is_wrong_order(head, cur, min_num, max_num))
			count++;
		cur = cur->fwd;
	}
	return (count);
}

void	sort_stack_ct3(t_stack **stack_a, t_stack **stack_b, int max_num)
{
	if (node_num(*stack_a, 0) == max_num)
		rotate(stack_a, stack_b, 1);
	else if (node_num(*stack_a, 1) == max_num)
		rev_rotate(stack_a, stack_b, 1);
	if (is_sorted(stack_a) == 0)
		swap(stack_a, stack_b, 1);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int inputs)
{
	int		max_num;
	int		min_num;
	t_stack	*cur_a;
	int		misplaced_node;

	cur_a = *stack_a;
	if (inputs == 2)
	{
		swap(stack_a, stack_b, 1);
		return ;
	}
	max_num = find_max(*stack_a);
	min_num = find_min(*stack_a);
	if (inputs == 3)
		sort_stack_ct3(stack_a, stack_b, max_num);
	else
	{
		misplaced_node = find_first_err(*stack_a, *stack_a, min_num, max_num);
		if (ct_wrong_order(*stack_a, *stack_a, min_num, max_num) == 1)
			while (is_sorted(stack_a) == 0)
			{
				while ((*stack_a)->num < (*stack_a)->fwd->num)
				{
					if (misplaced_node < inputs / 2)
						rotate(stack_a, stack_b, 1);
					else
						rev_rotate(stack_a, stack_b, 1);
				}
				swap(stack_a, stack_b, 1);
			}
		// printf("wrong:%d\n", ct_wrong_order(*stack_a, *stack_a, min_num, max_num));
		// printf("error located in node:%d\n", find_first_error(*stack_a, *stack_a, min_num, max_num));
	}
}
