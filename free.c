/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:46:00 by chon              #+#    #+#             */
/*   Updated: 2024/06/04 13:46:00 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_char_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	free_stack(t_stack **lst)
{
	if (*lst)
	{
		while ((*lst)->fwd)
			*lst = (*lst)->fwd;
		while ((*lst)->bwd)
		{
			*lst = (*lst)->bwd;
			free((*lst)->fwd);
		}
		free(*lst);
	}
}
