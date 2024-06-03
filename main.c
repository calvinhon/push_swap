/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:00:26 by chon              #+#    #+#             */
/*   Updated: 2024/06/03 16:37:59 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	switch_var = 0;

int is_perfect(t_stack **stack)
{
	t_stack *cur;

	cur = *stack;
	while (cur->fwd)
	{
		if (cur->fin_pos != cur->fwd->fin_pos - 1)
			return (0);
		cur = cur->fwd;
	}
	return (1);
}

void fill_final_pos(int *fin_pos, int *inputs, int num_of_inputs)
{
	int i;
	int j;
	int prior_max_position;
	int greater_switch;

	i = -1;
	j = 0;
	while (--num_of_inputs > 0)
	{
		prior_max_position = 0;
		greater_switch = 0;
		j++;
		while (++i < j)
		{
			if (inputs[j] > inputs[i])
			{
				if (fin_pos[i] > prior_max_position)
					prior_max_position = fin_pos[i];
				greater_switch = 1;
			}
			else
				fin_pos[i]++;
		}
		if (greater_switch)
			fin_pos[j] = prior_max_position + 1;
		i = -1;
	}
}

int create_stack(t_stack **stack, int *inputs, int num_of_inputs)
{
	int 	i;
	int 	*fin_pos;
	t_stack	*cur;
	t_stack	*tmp;

	i = 0;
	fin_pos = calloc(sizeof(int), num_of_inputs);
	if (!fin_pos)
		return (0);
	fill_final_pos(fin_pos, inputs, num_of_inputs);
	*stack = new_node(inputs[i], fin_pos[i]);
	cur = *stack;
	while (--num_of_inputs > 0)
	{
		i++;
		tmp = cur;
		cur->fwd = new_node(inputs[i], fin_pos[i]);
		cur = cur->fwd;
		cur->bwd = tmp;
	}
	free(fin_pos);
	return (1);
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

int main(int ac, char **av)
{
	t_stack	*a_top;
	t_stack	*b_top;
	int		*inputs;
	int		elements;

	a_top = NULL;
	b_top = NULL;
	if (ac < 2)
		return (1);
	inputs = parse_inputs(ac, av);
	if (!inputs)
	{
		ft_printf("Error\n");
		return (1);
	}
	elements = ct_elements(av);
	if (!create_stack(&a_top, inputs, elements))
		return (1);
				if (switch_var == 1)
				{
				t_stack *cur_a = a_top;
				t_stack *cur_b = b_top;
				while (cur_a)
				{
					printf("%lld ", cur_a->num);
					cur_a = cur_a->fwd;
				}
				printf("\n");
				while (cur_b)
				{
					printf("%lld ", cur_b->num);
					cur_b = cur_b->fwd;
				}
				printf("\n");
				}
	if (!is_perfect(&a_top))
		sort_stack(&a_top, &b_top, elements);
				if (switch_var == 1)
				{
				t_stack *cur_a = a_top;
				t_stack *cur_b = b_top;
				printf("\n");
				cur_a = a_top;
				cur_b = b_top;
				while (cur_a)
				{
					printf("%lld ", cur_a->num);
					cur_a = cur_a->fwd;
				}
				printf("\n");
				while (cur_b)
				{
					printf("%lld ", cur_b->num);
					cur_b = cur_b->fwd;
				}
				printf("\n");
				}
	free_stack(&a_top);
	free(inputs);
	return (0);
}
