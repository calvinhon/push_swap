/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:00:26 by chon              #+#    #+#             */
/*   Updated: 2024/05/28 16:04:25 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack_1, t_stack **stack_2, int stack_id)
{
	int	tmp_num;
	int	tmp_position;

	if (!*stack_1 || !(*stack_1)->fwd)
		return ;
	tmp_num = (*stack_1)->num;
	tmp_position = (*stack_1)->fin_pos;
	(*stack_1)->num = (*stack_1)->fwd->num;
	(*stack_1)->fin_pos = (*stack_1)->fwd->fin_pos;
	(*stack_1)->fwd->num = tmp_num;
	(*stack_1)->fwd->fin_pos = tmp_position;
	if (stack_id == 3)
	{
		if (!*stack_2 || !(*stack_2)->fwd)
			return ;
		tmp_num = (*stack_2)->num;
		tmp_position = (*stack_2)->fin_pos;
		(*stack_2)->num = (*stack_2)->fwd->num;
		(*stack_2)->fin_pos = (*stack_2)->fwd->fin_pos;
		(*stack_2)->fwd->num = tmp_num;
		(*stack_2)->fwd->fin_pos = tmp_position;
	}
	print_action(0, stack_id);
}

void	push(t_stack **from, t_stack **to, int stack_id)
{
	if (!(*from))
		return ;
	else if (!(*to))
		*to = new_node((*from)->num, (*from)->fin_pos);
	else
		add(to, new_node((*from)->num, (*from)->fin_pos), 0);
	*from = del_first_node(*from);
	if (stack_id == 1)
		ft_printf("pb\n");
	if (stack_id == 2)
		ft_printf("pa\n");
}

void	rotate(t_stack **stack_1, t_stack **stack_2, int stack_id)
{
	int		tmp_num;
	int		tmp_position;
	t_stack	*cur;

	if (!*stack_1)
		return ;
	cur = *stack_1;
	tmp_num = cur->num;
	tmp_position = cur->fin_pos;
	while (cur->fwd)
	{
		cur->num = cur->fwd->num;
		cur->fin_pos = cur->fwd->fin_pos;
		cur = cur->fwd;
	}
	cur->num = tmp_num;
	cur->fin_pos = tmp_position;
	if (stack_id == 3)
		rotate(stack_2, NULL, 0);
	print_action(1, stack_id);
}

void	rev_rotate(t_stack **stack_1, t_stack **stack_2, int stack_id)
{
	int		tmp_num;
	int		tmp_position;
	t_stack	*cur;

	if (!*stack_1)
		return ;
	cur = *stack_1;
	while (cur->fwd)
		cur = cur->fwd;
	tmp_num = cur->num;
	tmp_position = cur->fin_pos;
	while (cur->bwd)
	{
		cur->num = cur->bwd->num;
		cur->fin_pos = cur->bwd->fin_pos;
		cur = cur->bwd;
	}
	cur->num = tmp_num;
	cur->fin_pos = tmp_position;
	if (stack_id == 3)
		rev_rotate(stack_2, NULL, 0);
	if (stack_id == 1)
		ft_printf("rra\n");
	else
		print_action(2, stack_id);
}

void	rotate_choose(t_stack **s1, t_stack **s2, int stack_id, int order)
{
	if (order == 1)
		rotate(s1, s2, stack_id);
	else
		rev_rotate(s1, s2, stack_id);
}
