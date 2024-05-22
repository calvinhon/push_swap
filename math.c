/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:01:26 by chon              #+#    #+#             */
/*   Updated: 2024/05/22 15:27:06 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_abs(int num1, int num2)
{
	if (abs(num1) < abs(num2))
		return (num1);
	return (num2);
}

int	min(int num1, int num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

int	max(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
