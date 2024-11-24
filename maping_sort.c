/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:30:55 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/25 00:41:55 by aelaaser         ###   ########.fr       */
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

	head_b = stack_b->top;
	best_score = 2147483647;
	while (head_b)
	{
		cost_b = moves_qty(stack_b, head_b->index);
		head_a = stack_a->top;
		while (head_a)
		{
			c_index = stack_a->top->index;
			if (head_a->next)
				c_index = head_a->next->index;
			if (head_a->index < head_b->index && head_b->index < c_index)
			{
				cost_a = moves_qty(stack_a, head_a->index);
				total_cost = get_cost(cost_a, cost_b);
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
