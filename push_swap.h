/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:02:37 by chon              #+#    #+#             */
/*   Updated: 2024/05/07 14:11:30 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	long long		num;
	struct s_stack	*bwd;
	struct s_stack	*fwd;
}	t_stack;

void	add(t_stack **head, t_stack *new_node, int position);
t_stack	*new_node(int nbr);
void	swap(t_stack **stack_1, t_stack **stack_2, int stack_id);
t_stack	*del_first_node(t_stack *top);
void	push(t_stack **from, t_stack **to, int stack_id);
void	rotate(t_stack **stack_1, t_stack **stack_2, int stack_id);
void	rev_rotate(t_stack **stack_1, t_stack **stack_2, int stack_id);
void	free_stack(t_stack **stack);
void	sort_stack(t_stack **stack_a, t_stack **stack_b, int inputs);
int		find_max(t_stack *cur);
int		node_num(t_stack *cur, int node_pos);
int		is_sorted(t_stack **stack);
int		find_min(t_stack *cur);
int		is_wrong_order(t_stack *head, t_stack *cur, int min_num, int max_num);
int		find_first_err(t_stack *head, t_stack *cur, int min_num, int max_num);

#endif
