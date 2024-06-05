/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:02:37 by chon              #+#    #+#             */
/*   Updated: 2024/06/05 14:28:00 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_idx
{
	int	i;
	int	j;
	int	k;
}	t_idx;

typedef struct s_stack_num
{
	int	min;
	int	max;
}	t_stack_num;

typedef struct s_stack
{
	long long		num;
	int				fin_pos;
	struct s_stack	*bwd;
	struct s_stack	*fwd;
}	t_stack;

typedef struct s_helper
{
	t_stack	*c_from;
	t_stack	*c_to;
	int		length_from;
	int		length_to;
	int		min;
	int		max;
	int		min_to;
	int		max_to;
	int		node_from;
	int		best_node_from;
	long	shift_to;
	int		best_shift_to;
	long	shift_from;
	int		best_shift_from;
	int		order_from;
	int		order_to;
	int		combined_moves;
	long	best_combined_moves;
	int		rotate;
	int		rotate_switch;
	int		best_rotate_switch;
	int		rotate_both;
}	t_helper;

int		*parse_inputs(int ac, char **av);
void	swap(t_stack **s1, t_stack **s2, int stack_id, int print);
void	push(t_stack **from, t_stack **to, int stack_id, int print);
void	rotate(t_stack **s1, t_stack **s2, int stack_id, int print);
void	rev_rotate(t_stack **s1, t_stack **s2, int stack_id, int print);
t_stack	*new_node(int nbr, int position);
void	free_stack(t_stack **stack);
void	sort_stack(t_stack **a, t_stack **b, int inputs);
int		max_nbr(t_stack *cur);
int		min_nbr(t_stack *cur);
int		find_num_in_node(t_stack *cur, int node_pos);
long	idx_of_num(t_stack *cur, int nbr);
long	idx_of_fin_pos(t_stack *cur, int fin_position);
int		is_perfect(t_stack **stack);
int		count_nodes(t_stack *cur);
void	fill_final_pos(int *fin_pos, int *inputs, int num_of_inputs);
void	print_action(int action, int stack_id);
void	ordered_but_err(t_stack **a, int ac, t_stack_num s);
int		is_ordered(t_stack *node, int num_of_nodes);
int		ft_round(double num);
int		ft_abs(int num);
long	min(long num1, long num2);
long	max(long num1, long num2);
void	free_char_array(char **array);
void	rotate_choose(t_stack **s1, t_stack **s2, int stack_id, int order);
void	sort_stack_ct_3(t_stack **a);
void	complex_sort_alg(t_stack **a, t_stack **b, t_stack_num s, int inputs);
int		ct_elements(char **av);
int		create_stack(t_stack **stack, int *inputs, int num_of_inputs);

#endif
