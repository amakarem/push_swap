/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:30:55 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/25 01:13:05 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_alternative_move(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*head_a;
	int		ok;
	int		c_index;

	set_b_best(stack_a, stack_b);
	head_a = stack_a->top;
	ok = 0;
	while (head_a && ok == 0)
	{
		c_index = stack_a->top->index;
		if (head_a->next)
			c_index = head_a->next->index;
		if (head_a->index < stack_b->best && c_index > stack_b->best)
		{
			stack_a->best = c_index;
			ok = 1;
		}
		head_a = head_a->next;
	}
	if (ok == 0)
		stack_a->best = get_min_index(stack_a);
	return (1);
}

int	set_best(t_stack *stack_a, t_stack *stack_b, int b_index, int best_score)
{
	t_node	*head_a;
	int		cost_b;
	int		score;
	int		c_index;

	cost_b = moves_qty(stack_b, b_index);
	head_a = stack_a->top;
	while (head_a)
	{
		c_index = stack_a->top->index;
		if (head_a->next)
			c_index = head_a->next->index;
		if (head_a->index < b_index && b_index < c_index)
		{
			if (get_cost(moves_qty(stack_a, head_a->index), cost_b) < 3)
			{
				score = get_cost(moves_qty(stack_a, head_a->index), cost_b)
					+ ft_unsigend(head_a->index - c_index);
				if (score < best_score)
				{
					best_score = score;
					stack_a->best = c_index;
					stack_b->best = b_index;
				}
			}
		}
		head_a = head_a->next;
	}
	return (best_score);
}

int	find_best_move(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*head_b;
	int		cost_b;
	int		best_score;

	head_b = stack_b->top;
	best_score = 2147483647;
	while (head_b)
	{
		cost_b = moves_qty(stack_b, head_b->index);
		best_score = set_best(stack_a, stack_b, head_b->index, best_score);
		head_b = head_b->next;
	}
	if (best_score == 2147483647)
		return (find_alternative_move(stack_a, stack_b));
	return (1);
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
