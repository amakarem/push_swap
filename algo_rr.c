/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:24:30 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/05 00:00:32 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a)
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
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_b)
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
	ft_printf("rrb\n");
}
