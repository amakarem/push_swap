/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:24:30 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/25 04:23:12 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a, int noprint)
{
	t_node	*current;
	t_node	*prev;

	if (stack_a->size < 2)
		return ;
	current = stack_a->top;
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = stack_a->top;
	stack_a->top = current;
	if (noprint == 0)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *stack_b, int noprint)
{
	t_node	*current;
	t_node	*prev;

	if (stack_b->size < 2)
		return ;
	current = stack_b->top;
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = stack_b->top;
	stack_b->top = current;
	if (noprint == 0)
		ft_putendl_fd("rrb", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	ft_putendl_fd("rr", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	ft_putendl_fd("rrr", 1);
}
