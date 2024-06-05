/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:01:26 by chon              #+#    #+#             */
/*   Updated: 2024/06/05 14:21:44 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_round(double num)
{
	double	orig_num;
	double	remainder;

	orig_num = num;
	while (num > 1)
		num--;
	remainder = num;
	if (remainder != 1)
		return (orig_num - remainder);
	return (orig_num);
}

long	min(long num1, long num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

long	max(long num1, long num2)
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
