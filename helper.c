/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:20:02 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/19 01:50:07 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_unindexed_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	current = stack->top;
	while (current->next != NULL)
	{
		if (current->index == -1)
			break ;
		current = current->next;
	}
	min = current->value;
	while (current != NULL)
	{
		if (current->index == -1 && current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

void	set_index(t_stack *stack)
{
	t_node	*current;
	int		i;
	int		min;

	i = 0;
	while (i < stack->size)
	{
		current = stack->top;
		min = find_unindexed_min(stack);
		while (current)
		{
			if (current->index == -1 && current->value == min)
			{
				current->index = i;
				break ;
			}
			current = current->next;
		}
		i++;
	}
}

static int	get_max_bits(t_stack *stack)
{
	t_node	*head;
	int		max;
	int		max_bits;

	head = stack->top;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = stack_a->top;
	size = stack_a->size;
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = stack_a->top;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a, 0);
			else
				pb(stack_a, stack_b);
		}
		while (stack_b->size != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
