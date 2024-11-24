/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:04:43 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/25 00:08:17 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_unsigend(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	ft_min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

int	get_total_cost(int a, int b)
{
	int	x;
	int	y;

	x = ft_unsigend(a);
	y = ft_unsigend(b);
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
	{
		if (x > y)
			return (x);
		else
			return (y);
	}
	return (x + y);
}

int	moves_to_top(t_stack *stack, int index)
{
	int	pos;

	pos = get_position(stack, index);
	if (pos == -1)
		return (0);
	if (pos > (stack->size / 2))
		pos = (stack->size - pos) * -1;
	return (pos);
}
