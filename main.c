/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:00:26 by chon              #+#    #+#             */
/*   Updated: 2024/06/04 16:50:44 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	switch_var = 0;

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
