/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:47:53 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/25 16:05:59 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *stack, t_stack *stack_b)
{
	int	min_index;

	while (stack->size > 0 && !is_sorted_stack(stack))
	{
		sort_asc_by_index(stack, 'A');
		min_index = get_position(stack, get_min_index(stack));
		while (stack->top->index != get_min_index(stack))
		{
			if (min_index < stack->size / 2)
				ra(stack, 0);
			else
				rra(stack, 0);
			if (stack->top->index == get_min_index(stack))
				break ;
		}
		if (!is_sorted_stack(stack))
			pb(stack, stack_b);
	}
	while (stack_b->size > 0)
		pa(stack, stack_b);
	if (!is_sorted_stack(stack))
		sort_stack(stack, stack_b);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 1)
		return ;
	set_index(stack_a);
	if (is_sorted_stack(stack_a))
		return ;
	if (stack_a->size > 3)
		maping_sort(stack_a, stack_b);
	else
		sort_stack(stack_a, stack_b);
}
