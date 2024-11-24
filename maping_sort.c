/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:30:55 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/24 23:54:17 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_unsigend(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	ft_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
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

// static int	get_max_index(t_stack *stack)
// {
// 	t_node	*head;
// 	int		max;

// 	head = stack->top;
// 	max = head->index;
// 	while (head)
// 	{
// 		if (head->index > max)
// 			max = head->index;
// 		head = head->next;
// 	}
// 	return (max);
// }

static int	get_min_index(t_stack *stack)
{
	t_node	*head;
	int		min;

	head = stack->top;
	min = head->index;
	while (head)
	{
		if (head->index < min)
			min = head->index;
		head = head->next;
	}
	return (min);
}

// int	find_best_moveXXXX(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_node	*head_a;
// 	t_node	*head_b;
// 	int		cost_a;
// 	int		cost_b;
// 	int		total_cost;
// 	int		score;
// 	int 	best_score;

// 	if (stack_a->size < 2 || stack_b->size < 2)
// 		return (0);
// 	head_a = stack_a->top;
// 	best_score = stack_a->size;
// 	while (head_a)
// 	{
// 		cost_a = moves_to_top(stack_a, head_a->index);
// 		head_b = stack_b->top;
// 		while (head_b)
// 		{
// 			if (head_b->index < head_a->index)
// 			{
// 				cost_b = moves_to_top(stack_b, head_b->index);
// 				total_cost = get_total_cost(cost_a, cost_b);
// 				if (total_cost < 3)
// 				{
// 					score = total_cost + (head_a->index - head_b->index);
// 					if (score < best_score)
// 					{
// 						best_score = score;
// 						stack_a->best = head_a->index;
// 						stack_b->best = head_b->index;
// 					}
// 				}
// 			}
// 			head_b = head_b->next;
// 		}
// 		head_a = head_a->next;
// 	}
// 	ft_printf("\nTarget A:%i Top A:%i Cost:%i  ---  Target B:%i Top B:%i Cost:%i", stack_a->best, stack_a->top->index, cost_a, stack_b->best, stack_b->top->index, cost_b);
// 	return (1);
// }

// int find_alternative2_move(t_stack *stack_a, t_stack *stack_b)
// {
// 	ft_printf("\n Alternave LVL 2");
// 	if (stack_b->best > get_max_index(stack_a))
// 		stack_a->best = get_min_index(stack_a);
// 	// else
// 	if (stack_a->top < stack_a->best)
// 		stack_a->best = get_min_index(stack_a);
// 	return (1);
// }

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

// int find_alternative_move(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_node	*head_a;
// 	int		ok;

// 	stack_b->best = stack_b->top->index;
// 	head_a = stack_a->top;
// 	ok = 0;
// 	while (head_a && ok == 0)
// 	{
// 		if (head_a->next && head_a->index < stack_b->best && head_a->next->index > stack_b->best)
// 		{
// 			//ft_printf("\n----Between %i and %i adding %i", head_a->index, head_a->next->index, stack_b->best);
// 			stack_a->best = head_a->next->index;
// 			ok = 1;
// 		}
// 		else if (!head_a->next && head_a->index < stack_b->best && stack_a->top->index > stack_b->best)
// 		{
// 			//ft_printf("\n----Between %i and %i adding %i", head_a->index, stack_a->top->index, stack_b->best);
// 			stack_a->best = stack_a->top->index;
// 			ok = 1;
// 		}
// 		head_a = head_a->next;
// 	}
// 	if (ok == 0)
// 	{
// 		stack_a->best = get_min_index(stack_a);
// 	}
// 	ft_printf("\n Alternative Move:%i over %i  COST:%i\n", stack_b->best, stack_a->best, find_alternative_cost(stack_a, stack_b, stack_b->best));
// 	//print_stack(stack_b);
// 	//ft_printf("\n**************************************\n");
// 	//print_stack(stack_a);
// 	//ft_printf("\n Cost:%i\n", moves_to_top(stack_a, stack_a->best));
// 	return (1);
// }

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
