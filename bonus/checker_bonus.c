/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:28:01 by chon              #+#    #+#             */
/*   Updated: 2024/06/04 17:09:30 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_error()
{
	ft_printf("Error\n");
	exit (0);
}
int	read_instructions_2(char **instructions, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(*instructions, "rra", 3))
	{
		rev_rotate(a, NULL, 1, 0);
		return (1);
	}
	else if (!ft_strncmp(*instructions, "rrb", 2))
	{
		rev_rotate(b, NULL, 2, 0);
		return (1);
	}
	else if (!ft_strncmp(*instructions, "rrr", 2))
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
		if (!ft_strncmp(*instructions, "pb", 2))
			push(a, b, 1, 0);
		else if (!ft_strncmp(*instructions, "pa", 2))
			push(b, a, 2, 0);
		else if (!ft_strncmp(*instructions, "sa", 2))
			swap(a, NULL, 1, 0);
		else if (!ft_strncmp(*instructions, "sb", 2))
			swap(b, NULL, 2, 0);
		else if (!ft_strncmp(*instructions, "ss", 2))
			swap(a, b, 3, 0);
		else if (!ft_strncmp(*instructions, "ra", 2))
			rotate(a, NULL, 1, 0);
		else if (!ft_strncmp(*instructions, "rb", 2))
			rotate(b, NULL, 2, 0);
		else if (!ft_strncmp(*instructions, "rr", 2))
			rotate(a, b, 3, 0);
		else if (!read_instructions_2(instructions, a, b))
			return (0);
	}
	return (1);
}

int	compile_instructions(char *line, t_stack **a, t_stack **b)
{
	char	**instructions;
	char	*add;

	add = get_next_line(0);
	while (add)
	{
		line = ft_strjoin(line, add);
		free(add);
		add = get_next_line(0);
	}
	instructions = ft_split(line, '\n');
	free(line);
	if (!read_instructions(instructions, a, b))
	{
		free_char_array(instructions);
		return (0);
	}
	free_char_array(instructions);
	return (1);
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
		ft_error();
	elements = ct_elements(av);
	if (!create_stack(&a, inputs, elements))
		return (1);
	if (!compile_instructions(line, &a, &b))
		ft_error();
	if (is_perfect(&a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
