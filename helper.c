/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:20:02 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/25 00:02:21 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_asc_by_index(t_stack *stack, char adr)
{
	if (stack->size >= 2 && stack->top->index > stack->top->next->index)
	{
		if (adr == 'a' || adr == 'A')
			sa(stack);
		else
			sb(stack);
	}
}

void	sort_desc(t_stack *stack, char adr)
{
	if (stack->size >= 2 && stack->top->value < stack->top->next->value)
	{
		if (adr == 'a' || adr == 'A')
			sa(stack);
		else
			sb(stack);
	}
}

int	get_min_index(t_stack *stack)
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

int	get_position(t_stack *stack, int maxindex)
{
	t_node	*head;
	int		position;

	head = stack->top;
	position = 0;
	while (head)
	{
		if (head->index == maxindex)
			return (position);
		head = head->next;
		position++;
	}
	return (-1);
}
