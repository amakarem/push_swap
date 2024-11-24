/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:30:55 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/25 00:06:53 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_alternative_cost(t_stack *stack_a, t_stack *stack_b, int b_best)
{
	t_node	*head_a;
	int		a_best;

	head_a = stack_a->top;
	a_best = -1;
	while (head_a && a_best == -1)
	{
		if (head_a->next && head_a->index < b_best && head_a->next->index > b_best)
		{
			a_best = head_a->next->index;
		}
		else if (!head_a->next && head_a->index < b_best && stack_a->top->index > b_best)
		{
			a_best = stack_a->top->index;
		}
		head_a = head_a->next;
	}
	if (a_best == -1)
		a_best = get_min_index(stack_a);
	return (get_total_cost(moves_to_top(stack_b, b_best), moves_to_top(stack_a, a_best)));
}

int	find_alternative_move(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*head_a;
	t_node	*head_b;
	int		cost;
	int		best_cost;
	int		ok;

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
	head_a = stack_a->top;
	ok = 0;
	while (head_a && ok == 0)
	{
		if (head_a->next && head_a->index < stack_b->best && head_a->next->index > stack_b->best)
		{
			stack_a->best = head_a->next->index;
			ok = 1;
		}
		else if (!head_a->next && head_a->index < stack_b->best && stack_a->top->index > stack_b->best)
		{
			stack_a->best = stack_a->top->index;
			ok = 1;
		}
		head_a = head_a->next;
	}
	if (ok == 0)
		stack_a->best = get_min_index(stack_a);
	return (1);
}

int	find_best_move(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*head_a;
	t_node	*head_b;
	int		cost_a;
	int		cost_b;
	int		total_cost;
	int		score;
	int		best_score;
	int		c_index;

	if (stack_b->size == 0)
		return (0);
	head_b = stack_b->top;
	best_score = 2147483647;
	while (head_b)
	{
		cost_b = moves_to_top(stack_b, head_b->index);
		head_a = stack_a->top;
		while (head_a)
		{
			c_index = stack_a->top->index;
			if (head_a->next)
				c_index = head_a->next->index;
			if (head_a->index < head_b->index && head_b->index < c_index)
			{
				cost_a = moves_to_top(stack_a, head_a->index);
				total_cost = get_total_cost(cost_a, cost_b);
				if (total_cost < 3)
				{
					score = total_cost + ft_unsigend(head_a->index - c_index);
					if (score < best_score)
					{
						best_score = score;
						stack_a->best = c_index;
						stack_b->best = head_b->index;
					}
				}
			}
			head_a = head_a->next;
		}
		head_b = head_b->next;
	}
	if (best_score == 2147483647)
		return (find_alternative_move(stack_a, stack_b));
	return (1);
}

void	do_move_solo(t_stack *stack, char identity)
{
	int	cost;

	if (stack->top->index == stack->best)
		return ;
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

void	maping_sort(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 2)
		pb(stack_a, stack_b);
	sort_asc_by_index(stack_a, 'A');
	while (stack_b->size > 0)
	{
		if (find_best_move(stack_a, stack_b) == 1)
			do_move_common(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	stack_a->best = get_min_index(stack_a);
	do_move_solo(stack_a, 'a');
}
