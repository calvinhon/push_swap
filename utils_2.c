/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:00:46 by chon              #+#    #+#             */
/*   Updated: 2024/06/05 14:27:44 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_final_pos(int *fin_pos, int *inputs, int num_of_inputs)
{
	int	i;
	int	j;
	int	prior_max_position;

	i = -1;
	j = 0;
	while (--num_of_inputs > 0)
	{
		prior_max_position = 0;
		j++;
		while (++i < j)
		{
			if (inputs[j] > inputs[i])
			{
				if (fin_pos[i] > prior_max_position)
					prior_max_position = fin_pos[i];
				fin_pos[j] = prior_max_position + 1;
			}
			else
				fin_pos[i]++;
		}
		i = -1;
	}
}

int	ct_elements(char **av)
{
	int		i;
	int		j;
	int		elements;

	i = 0;
	j = 0;
	elements = 0;
	while (av[++i])
	{
		while (av[i][j])
		{
			while (av[i][j] && av[i][j] == ' ')
				j++;
			if (av[i][j] && av[i][j] != ' ')
				elements++;
			while (av[i][j] && av[i][j] != ' ')
				j++;
		}
		j = 0;
	}
	return (elements);
}

int	count_nodes(t_stack *cur)
{
	int	num_of_nodes;

	num_of_nodes = 0;
	while (cur)
	{
		num_of_nodes++;
		cur = cur->fwd;
	}
	return (num_of_nodes);
}

void	print_action(int action, int stack_id)
{
	if (action == 0)
	{
		if (stack_id == 1)
			ft_printf("sa\n");
		else if (stack_id == 2)
			ft_printf("sb\n");
		else if (stack_id == 3)
			ft_printf("ss\n");
	}
	if (action == 1)
	{
		if (stack_id == 1)
			ft_printf("ra\n");
		else if (stack_id == 2)
			ft_printf("rb\n");
		else if (stack_id == 3)
			ft_printf("rr\n");
	}
	if (action == 2)
	{
		if (stack_id == 2)
			ft_printf("rrb\n");
		else if (stack_id == 3)
			ft_printf("rrr\n");
	}
}

void	ordered_but_err(t_stack **a, int inputs, t_stack_num s)
{
	int	rotate_switch;

	rotate_switch = 1;
	if (idx_of_num(*a, s.min) > ft_round((double)inputs / 2))
		rotate_switch = -1;
	if (is_ordered(*a, -1))
		while ((*a)->fin_pos != 0)
			rotate_choose(a, NULL, 1, rotate_switch);
	return ;
}
