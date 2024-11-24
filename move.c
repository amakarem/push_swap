/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:12:08 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/25 00:16:14 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_move_solo(t_stack *stack, char identity)
{
	int	cost;

	cost = moves_to_top(stack, stack->best);
	if (cost > 0)
	{
		while (stack->top->index != stack->best)
		{
			if (identity == 'a' || identity == 'A')
				ra(stack, 0);
			else
				rb(stack, 0);
			cost--;
		}
	}
	else if (cost < 0)
	{
		while (stack->top->index != stack->best)
		{
			if (identity == 'a' || identity == 'A')
				rra(stack, 0);
			else
				rrb(stack, 0);
			cost++;
		}
	}
}

void	do_move_common(t_stack *stack_a, t_stack *stack_b)
{
	int	cost_a;
	int	cost_b;
	int	i;

	cost_a = moves_to_top(stack_a, stack_a->best);
	cost_b = moves_to_top(stack_b, stack_b->best);
	if (cost_a > 0 && cost_b > 0)
	{
		i = ft_min(cost_a, cost_b);
		while (i-- > 0)
			rr(stack_a, stack_b);
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		i = ft_min(ft_unsigend(cost_a), ft_unsigend(cost_b));
		while (i-- > 0)
			rrr(stack_a, stack_b);
	}
	do_move_solo(stack_a, 'a');
	do_move_solo(stack_b, 'b');
}
