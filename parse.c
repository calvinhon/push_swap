/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:54:20 by chon              #+#    #+#             */
/*   Updated: 2024/06/05 14:24:42 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_stack(t_stack **stack, int *inputs, int num_of_inputs)
{
	int		i;
	int		*fin_pos;
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

int	are_ints(char **array)
{
	int			i;
	int			j;
	long long	num;

	i = -1;
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
			if ((array[i][j] == '-' || array[i][j] == '+') && j == 0)
				j++;
			if (array[i][j] && !ft_isdigit((array[i][j])))
				return (0);
		}
		j = -1;
	}
	return (1);
}

int	is_repeated(int *inputs, int elements)
{
	int	i;
	int	j;

	i = -1;
	while (++i < elements)
	{
		j = i + 1;
		while (j < elements)
		{
			if (inputs[i] == inputs[j++])
			{
				free(inputs);
				return (1);
			}
		}
	}
	return (0);
}

int	*pull_inputs(char **av, int elements)
{
	t_idx	idx;
	char	**split_av;
	int		orig_num_of_elements;
	int		*inputs;

	idx.i = 0;
	idx.j = 1;
	idx.k = -1;
	inputs = malloc(sizeof(int) * elements);
	if (!inputs)
		return (NULL);
	orig_num_of_elements = elements;
	while (av[idx.j] && --elements > -1)
	{
		split_av = ft_split(av[idx.j++], ' ');
		while (split_av[++idx.k])
			inputs[idx.i++] = ft_atoi(split_av[idx.k]);
		free_char_array(split_av);
		idx.k = -1;
	}
	if (is_repeated(inputs, orig_num_of_elements))
		inputs = NULL;
	return (inputs);
}

int	*parse_inputs(int ac, char **av)
{
	int		i;
	int		j;
	int		elements;
	char	**split_av;

	i = 0;
	j = 0;
	elements = 0;
	while (--ac > 0)
	{
		split_av = ft_split(av[++i], ' ');
		if (!are_ints(split_av) || !split_av[0])
		{
			free_char_array(split_av);
			return (NULL);
		}
		while (split_av[j])
			j++;
		elements += j;
		j = 0;
		free_char_array(split_av);
	}
	return (pull_inputs(av, elements));
}
