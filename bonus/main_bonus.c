/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:28:01 by chon              #+#    #+#             */
/*   Updated: 2024/06/05 14:20:11 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	read_instructions_2(char *instructions, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(instructions, "rra", 4))
	{
		rev_rotate(a, NULL, 1, 0);
		return (1);
	}
	else if (!ft_strncmp(instructions, "rrb", 4))
	{
		rev_rotate(b, NULL, 2, 0);
		return (1);
	}
	else if (!ft_strncmp(instructions, "rrr", 4))
	{
		rev_rotate(a, b, 3, 0);
		return (1);
	}
	else
		return (0);
}

int	read_instructions(char **instructions, t_stack **a, t_stack **b)
{
	int	i;

	i = -1;
	while (instructions[++i])
	{
		if (!ft_strncmp(instructions[i], "pb", 3))
			push(a, b, 1, 0);
		else if (!ft_strncmp(instructions[i], "pa", 3))
			push(b, a, 2, 0);
		else if (!ft_strncmp(instructions[i], "sa", 3))
			swap(a, NULL, 1, 0);
		else if (!ft_strncmp(instructions[i], "sb", 3))
			swap(b, NULL, 2, 0);
		else if (!ft_strncmp(instructions[i], "ss", 3))
			swap(a, b, 3, 0);
		else if (!ft_strncmp(instructions[i], "ra", 3))
			rotate(a, NULL, 1, 0);
		else if (!ft_strncmp(instructions[i], "rb", 3))
			rotate(b, NULL, 2, 0);
		else if (!ft_strncmp(instructions[i], "rr", 3))
			rotate(a, b, 3, 0);
		else if (!read_instructions_2(instructions[i], a, b))
			return (0);
	}
	return (1);
}

void	compile_instructions(char *line, t_stack **a, t_stack **b)
{
	char	**instructions;
	char	*add;

	add = get_next_line(0);
	if (add)
	{
		while (add)
		{
			line = ft_strjoin(line, add);
			free(add);
			add = get_next_line(0);
		}
		instructions = ft_split(line, '\n');
		free(line);
		if (!*instructions || !read_instructions(instructions, a, b))
			ft_printf("Error\n");
		else if (is_perfect(a) && !*b)
			ft_printf("OK\n");
		else if (!is_perfect(a) || *b)
			ft_printf("KO\n");
		free_char_array(instructions);
	}
	else
		if (is_perfect(a) && !*b)
			ft_printf("OK\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		*inputs;
	int		elements;
	char	*line;

	a = NULL;
	b = NULL;
	line = NULL;
	if (ac < 2)
		return (1);
	inputs = parse_inputs(ac, av);
	if (!inputs)
	{
		ft_printf("Error\n");
		return (1);
	}
	elements = ct_elements(av);
	if (!create_stack(&a, inputs, elements))
		return (1);
	compile_instructions(line, &a, &b);
	free_stack(&a);
	free_stack(&b);
	free(inputs);
	return (0);
}
