/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:54:20 by chon              #+#    #+#             */
/*   Updated: 2024/05/15 12:01:01 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int are_ints(char **array)
{
	int i;
	int j;
	long long num;

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

int	is_repeated(int *inputs, int elements)
{
	int	i;
	int	j;

	i = -1;
	while (++i < elements)
	{
		j = i + 1;
		while (j < elements)
			if (inputs[i] == inputs[j++])
			{
				free(inputs);
				return (1);
			}
	}
	return (0);
}

int	*pull_inputs(char **av, int elements)
{
	int		i;
	int		j;
	int		k;
	char	**split_av;
	int		orig_num_of_elements;
	int 	*inputs;

	i = 0;
	j = 1;
	k = -1;
	inputs = malloc(sizeof(int) * elements);
	if (!inputs)
		return (NULL);
	orig_num_of_elements = elements;
	while (av[j] && --elements > -1)
	{
		split_av = ft_split(av[j++], ' ');
		while (split_av[++k])
			inputs[i++] = ft_atoi(split_av[k]);
		free_char_array(split_av);
		k = -1;
	}
	if (is_repeated(inputs, orig_num_of_elements))
		inputs = NULL;
	return (inputs);
}

int *parse_inputs(int ac, char **av)
{
	int 	i;
	int 	j;
	int 	elements;
	char	**split_av;

	i = 1;
	j = 0;
	elements = 0;
	while (--ac > 0)
	{
		split_av = ft_split(av[i++], ' ');
		if (are_ints(split_av) == 0)
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
