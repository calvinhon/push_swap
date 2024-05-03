/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:00:26 by chon              #+#    #+#             */
/*   Updated: 2024/05/03 13:16:39 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_num(t_stack *cur, int node_pos)
{
	while (node_pos > 0)
	{
		cur = cur->fwd;
		node_pos--;
	}
	return (cur->num);
}

void	swap(t_stack **lst_1, t_stack **lst_2, int stack_id)
{
	int	tmp;

	if (!(*lst_1) || !((*lst_1)->fwd))
		return ;
	tmp = (*lst_1)->num;
	(*lst_1)->num = (*lst_1)->fwd->num;
	(*lst_1)->fwd->num = tmp;
	if (stack_id == 3)
	{	
		if (!(*lst_2) || !((*lst_2)->fwd))
			return ;
		tmp = (*lst_2)->num;
		(*lst_2)->num = (*lst_2)->fwd->num;
		(*lst_2)->fwd->num = tmp;
	}
	if (stack_id == 1)
		ft_printf("sa\n");
	else if (stack_id == 2)
		ft_printf("sb\n");
	else if (stack_id == 3)
		ft_printf("ss\n");
}

void	push(t_stack **from, t_stack **to, int stack_id)
{
	if (!(*from))
		return ;
	else if (!(*to))
		*to = new_node((*from)->num);
	else
		add(to, new_node((*from)->num), 0);
	*from = del_first_node(*from);
	if (stack_id == 1)
		ft_printf("pa\n");
	if (stack_id == 2)
		ft_printf("pb\n");
}

void	rotate(t_stack **lst_1, t_stack **lst_2, int stack_id)
{
	int		tmp;
	t_stack	*cur;

	cur = *lst_1;
	tmp = cur->num;
	while (cur->fwd)
	{
		cur->num = cur->fwd->num;
		cur = cur->fwd;
	}
	cur->num = tmp;
	if (stack_id == 3)
		rotate(lst_2, NULL, 0);
	// if (stack_id == 3)
	// {
	// 	cur = *lst_2;
	// 	tmp = cur->num;
	// 	while (cur->fwd)
	// 	{
	// 		cur->num = cur->fwd->num;
	// 		cur = cur->fwd;
	// 	}
	// 	cur->num = tmp;
	// }
	if (stack_id == 1)
		ft_printf("ra\n");
	else if (stack_id == 2)
		ft_printf("rb\n");
	else if (stack_id == 3)
		ft_printf("rr\n");
}

void	rev_rotate(t_stack **lst_1, t_stack **lst_2, int stack_id)
{
	int		tmp;
	t_stack	*cur;

	cur = *lst_1;
	while (cur->fwd)
		cur = cur->fwd;
	tmp = cur->num;
	while (cur->bwd)
	{
		cur->num = cur->bwd->num;
		cur = cur->bwd;
	}
	cur->num = tmp;
	if (stack_id == 3)
	{
		cur = *lst_2;
		while (cur->fwd)
			cur = cur->fwd;
		tmp = cur->num;
		while (cur->bwd)
		{
			cur->num = cur->bwd->num;
			cur = cur->bwd;
		}
		cur->num = tmp;
	}
	if (stack_id == 1)
		ft_printf("rra\n");
	else if (stack_id == 2)
		ft_printf("rrb\n");
	else if (stack_id == 3)
		ft_printf("rrr\n");
}
