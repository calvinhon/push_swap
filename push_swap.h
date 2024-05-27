/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:02:37 by chon              #+#    #+#             */
/*   Updated: 2024/05/27 16:05:04 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

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
	t_stack	*cur_from;
	t_stack	*cur_to;
	int		length_from;
	int		length_to;
	int		node_from;
	int		best_node_from;
	long	shift_to;
	int		best_shift_to;
	long	shift_from;
	int		best_shift_from;
	int		flip_from;
	int		flip_to;
	int		ffffffjifejfiejfaeiofpaepoifjaewpoejafe;
	int		length_a;
	int		length_b;
	int		initiate_tracker;
	int		search_fin_pos;
	int		rotate;
	int		rev_rotate_a;
	int		node_a_to_move;
	int		best_node_a_to_move;
	long	shift_a_to_pb;
	int		best_shift_a_to_pb;
	long	shift_b_to_pb;
	int		best_shift_b_to_pb;
	int		node_b_to_move;
	int		best_node_b_to_move;
	long	shift_a_to_pa;
	int		best_shift_a_to_pa;
	int		shift_b_to_pa;
	int		best_shift_b_to_pa;
	int		combined_moves;
	long	best_combined_moves;
	int		rotate_switch;
	int		best_rotate_switch;
	int		simult_rotate;
}	t_helper;

void	swap(t_stack **stack_1, t_stack **stack_2, int stack_id);
void	push(t_stack **from, t_stack **to, int stack_id);
void	rotate(t_stack **stack_1, t_stack **stack_2, int stack_id);
void	rev_rotate(t_stack **stack_1, t_stack **stack_2, int stack_id);
void	add(t_stack **head, t_stack *new_node, int position);
t_stack	*new_node(int nbr, int position);
t_stack	*del_first_node(t_stack *top);
void	free_stack(t_stack **stack);
void	sort_stack(t_stack **stack_a, t_stack **stack_b, int inputs);
int		max_nbr(t_stack *cur);
int		min_nbr(t_stack *cur);
int		find_num_in_node(t_stack *cur, int node_pos);
int		find_pos_of_num(t_stack *cur, int nbr);
int		find_final_pos_of_num(t_stack *cur, int nbr);
int		find_pos_of_final_pos(t_stack *cur, int fin_position);
int		is_sorted(t_stack **stack);
int		is_wrong_order(t_stack *head, t_stack *cur, int min_num, int max_num);
int		find_first_err(t_stack *head, t_stack *cur, int min_num, int max_num);
int		count_nodes(t_stack *cur);
void	fill_final_pos(int *fin_pos, int *inputs, int num_of_inputs);
void	print_action(int action, int stack_id);
void	srtd_but_err(t_stack **stack_a, t_stack *cur, int ac, t_stack_num s);
int		is_ordered(t_stack *node, int num_of_nodes);
int		*parse_inputs(int ac, char **av);
int		is_max_min_order(t_stack **stack, t_stack *cur, t_stack_num s, char c);
int 	find_fin_pos_in_node(t_stack *cur, int node_pos);
int		ft_abs(int num);
int		min(int num1, int num2);
int		max(int num1, int num2);
long	moves_to_top(t_stack *head, int fin_pos, int stack_length);
void	free_char_array(char **array);
int		call_swap(t_stack *head, t_stack_num s);
void	rotate_choose(t_stack **s1, t_stack **s2, int stack_id, int order);

#endif
