/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:00:26 by chon              #+#    #+#             */
/*   Updated: 2024/05/07 15:30:50 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack	*cur;

	cur = *stack;
	while (cur->fwd)
	{
		if (cur->num > cur->fwd->num)
			return (0);
		cur = cur->fwd;
	}
	return (1);
}

int	create_stack(t_stack **stack, int *int_array, int array_size)
{
	int	i;

	i = 0;
	while (array_size > 0)
	{
		if (i == 0)
			*stack = new_node(int_array[i++]);
		else
			add(stack, new_node(int_array[i++]), -1);
		array_size--;
	}
	return (1);
}

int	are_ints(char **array)
{
	int			i;
	int			j;
	long long	num;

	i = 0;
	j = -1;
	while (array[++i])
	{
		if (ft_strlen(array[i]) == 0)
			return (0);
		num = ft_atoi(array[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		while (array[i][++j])
		{
			if (j == 0 && array[i][j] == '-')
				j++;
			if (ft_isdigit((array[i][j])) == 0)
				return (0);
		}
		j = -1;
	}
	return (1);
}

int	*parse_input(int ac, char **av)
{
	int	*int_array;
	int	elements;
	int	i;
	int	j;

	elements = ac - 1;
	if (are_ints(av) == 0)
		return (NULL);
	int_array = malloc(sizeof(int) * elements);
	if (!int_array)
		return (NULL);
	i = 0;
	j = 1;
	while (--ac > 0)
		int_array[i++] = ft_atoi(av[j++]);
	i = -1;
	while (++i < elements)
	{
		j = i + 1;
		while (j < elements)
			if (int_array[i] == int_array[j++])
				return (NULL);
	}
	return (int_array);
}

int	main(int ac, char **av)
{
	t_stack	*a_top;
	t_stack	*b_top;
	int		*int_array;

	a_top = NULL;
	b_top = NULL;
	if (ac < 2)
		return (1);
	int_array = parse_input(ac, av);
	if (!int_array)
	{
		ft_printf("Error\n");
		return (1);
	}
	create_stack(&a_top, int_array, ac - 1);
	// push(&a_top, &b_top, 0);
	// push(&b_top, &a_top, 0);
	// rev_rotate(&a_top, &b_top, 3);
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
	if (is_sorted(&a_top) == 0)
		sort_stack(&a_top, &b_top, ac - 1);
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
	free(int_array);
	return (0);
}
