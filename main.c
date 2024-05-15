/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:00:26 by chon              #+#    #+#             */
/*   Updated: 2024/05/15 14:09:05 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int create_stack(t_stack **stack, int *inputs, int num_of_inputs)
{
	int i;
	int *fin_pos;

	i = 0;
	fin_pos = calloc(sizeof(int), num_of_inputs);
	if (!fin_pos)
		return (0);
	fill_final_pos(fin_pos, inputs, num_of_inputs);
	while (num_of_inputs > 0)
	{
		if (i == 0)
			*stack = new_node(inputs[i],fin_pos[i]);
		else
			add(stack, new_node(inputs[i],fin_pos[i]), -1);
		i++;
		num_of_inputs--;
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
	if (!is_sorted(&a_top))
		sort_stack(&a_top, &b_top, elements);
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
	free_stack(&a_top);
	free_stack(&b_top);
	free(inputs);
	return (0);
}
