/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:00:26 by chon              #+#    #+#             */
/*   Updated: 2024/06/03 15:41:41 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **s1, t_stack **s2, int stack_id)
{
	int	tmp_num;
	int	tmp_position;

	if (!*s1 || !(*s1)->fwd)
		return ;
	tmp_num = (*s1)->num;
	tmp_position = (*s1)->fin_pos;
	(*s1)->num = (*s1)->fwd->num;
	(*s1)->fin_pos = (*s1)->fwd->fin_pos;
	(*s1)->fwd->num = tmp_num;
	(*s1)->fwd->fin_pos = tmp_position;
	if (stack_id == 3)
	{
		if (!*s2 || !(*s2)->fwd)
			return ;
		tmp_num = (*s2)->num;
		tmp_position = (*s2)->fin_pos;
		(*s2)->num = (*s2)->fwd->num;
		(*s2)->fin_pos = (*s2)->fwd->fin_pos;
		(*s2)->fwd->num = tmp_num;
		(*s2)->fwd->fin_pos = tmp_position;
	}
	print_action(0, stack_id);
}

void	push(t_stack **from, t_stack **to, int stack_id)
{
	t_stack	*tmp_to;
	t_stack	*tmp_from;

	if (!(*from))
		return ;
	tmp_to = *to;
	tmp_from = *from;
	*from = (*from)->fwd;
	if (*from)
		(*from)->bwd = NULL;
	if (!(*to))
	{
		*to = tmp_from;
		(*to)->fwd = NULL;
	}
	else
	{
		*to = tmp_from;
		(*to)->fwd = tmp_to;
		tmp_to->bwd = *to;
	}
	if (stack_id == 1)
		ft_printf("pb\n");
	if (stack_id == 2)
		ft_printf("pa\n");
}

void	rotate(t_stack **s1, t_stack **s2, int stack_id)
{
	int		tmp_num;
	int		tmp_position;
	t_stack	*cur;

	if (!*s1)
		return ;
	cur = *s1;
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
		rotate(s2, NULL, 0);
	print_action(1, stack_id);
}

void	rev_rotate(t_stack **s1, t_stack **s2, int stack_id)
{
	int		tmp_num;
	int		tmp_position;
	t_stack	*cur;

	if (!*s1)
		return ;
	cur = *s1;
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
		rev_rotate(s2, NULL, 0);
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
