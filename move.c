/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:12:08 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/25 00:34:33 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_move_solo(t_stack *stack, char identity)
{
	int	cost;

	cost = moves_qty(stack, stack->best);
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

	cost_a = moves_qty(stack_a, stack_a->best);
	cost_b = moves_qty(stack_b, stack_b->best);
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

int	find_alternative_cost(t_stack *stack_a, t_stack *stack_b, int b_best)
{
	t_node	*head_a;
	int		a_best;
	int		c_index;

	head_a = stack_a->top;
	a_best = -1;
	while (head_a && a_best == -1)
	{
		c_index = stack_a->top->index;
		if (head_a->next)
			c_index = head_a->next->index;
		if (head_a->index < b_best && c_index > b_best)
			a_best = c_index;
		head_a = head_a->next;
	}
	if (a_best == -1)
		a_best = get_min_index(stack_a);
	return (get_cost(moves_qty(stack_b, b_best), moves_qty(stack_a, a_best)));
}

void	set_b_best(t_stack	*stack_a, t_stack *stack_b)
{
	t_node	*head_b;
	int		cost;
	int		best_cost;

	stack_b->best = stack_b->top->index;
	best_cost = find_alternative_cost(stack_a, stack_b, stack_b->best);
	head_b = stack_b->top;
	while (head_b)
	{
		cost = find_alternative_cost(stack_a, stack_b, head_b->index);
		if (cost < best_cost)
		{
			best_cost = cost;
			stack_b->best = head_b->index;
		}
		head_b = head_b->next;
	}
}
