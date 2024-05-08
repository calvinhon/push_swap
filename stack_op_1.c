/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:00:26 by chon              #+#    #+#             */
/*   Updated: 2024/05/08 15:31:32 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_in_node(t_stack *cur, int node_pos)
{
	while (node_pos > 0)
	{
		cur = cur->fwd;
		node_pos--;
	}
	return (cur->num);
}

void	swap(t_stack **stack_1, t_stack **stack_2, int stack_id)
{
	int	tmp_num;
	int	tmp_position;

	if (!*stack_1 || !(*stack_1)->fwd)
		return ;
	tmp_num = (*stack_1)->num;
	tmp_position = (*stack_1)->final_position;
	(*stack_1)->num = (*stack_1)->fwd->num;
	(*stack_1)->final_position = (*stack_1)->fwd->final_position;
	(*stack_1)->fwd->num = tmp_num;
	(*stack_1)->fwd->final_position = tmp_position;
	if (stack_id == 3)
	{
		if (!*stack_2 || !(*stack_2)->fwd)
			return ;
		tmp_num = (*stack_2)->num;
		tmp_position = (*stack_2)->final_position;
		(*stack_2)->num = (*stack_2)->fwd->num;
		(*stack_2)->final_position = (*stack_2)->fwd->final_position;
		(*stack_2)->fwd->num = tmp_num;
		(*stack_2)->fwd->final_position = tmp_position;
	}
	print_action(0, stack_id);
}

void	push(t_stack **from, t_stack **to, int stack_id)
{
	t_stack	*cur;

	if (!(*from))
		return ;
	else if (!(*to))
		*to = new_node((*from)->num, (*from)->final_position);
	else
		add(to, new_node((*from)->num, (*from)->final_position), 0);
	cur = (*from)->fwd;
	*from = del_first_node(*from);
	if (stack_id == 1)
		ft_printf("pa\n");
	if (stack_id == 2)
		ft_printf("pb\n");
}

void	rotate(t_stack **stack_1, t_stack **stack_2, int stack_id)
{
	int		tmp_num;
	int		tmp_position;
	t_stack	*cur;

	cur = *stack_1;
	tmp_num = cur->num;
	tmp_position = cur->final_position;
	while (cur->fwd)
	{
		cur->num = cur->fwd->num;
		cur->final_position = cur->fwd->final_position;
		cur = cur->fwd;
	}
	cur->num = tmp_num;
	cur->final_position = tmp_position;
	if (stack_id == 3)
		rotate(stack_2, NULL, 0);
	print_action(1, stack_id);
}

void	rev_rotate(t_stack **stack_1, t_stack **stack_2, int stack_id)
{
	int		tmp_num;
	int		tmp_position;
	t_stack	*cur;

	cur = *stack_1;
	while (cur->fwd)
		cur = cur->fwd;
	tmp_num = cur->num;
	tmp_position = cur->final_position;
	while (cur->bwd)
	{
		cur->num = cur->bwd->num;
		cur->final_position = cur->bwd->final_position;
		cur = cur->bwd;
	}
	cur->num = tmp_num;
	cur->final_position = tmp_position;
	if (stack_id == 3)
		rev_rotate(stack_2, NULL, 0);
	if (stack_id == 1)
		ft_printf("rra\n");
	else if (stack_id == 2)
		ft_printf("rrb\n");
	else if (stack_id == 3)
		ft_printf("rrr\n");
}
