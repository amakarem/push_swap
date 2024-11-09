/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:39:26 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/09 16:05:59 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	t_node	*head;
	int		max;
	int		max_bits;

	head = stack->top;
	max = head->value;
	max_bits = 0;
	while (head)
	{
		if (head->value > max)
			max = head->value;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = stack_a->top;
	size = stack_a->size;
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = stack_a->top;
			if (((head_a->value >> i) & 1) == 1)
				ra(stack_a, 0);
			else
				pb(stack_a, stack_b);
		}
		while (stack_b->size != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
