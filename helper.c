/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:20:02 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/19 02:46:47 by aelaaser         ###   ########.fr       */
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

static void	sort_asc(t_stack *stack, char adr)
{
	if (stack->size >= 2 && stack->top->index > stack->top->next->index)
	{
		if (adr == 'a' || adr == 'A')
			sa(stack);
		else
			sb(stack);
	}
}

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

static int	get_position(t_stack *stack, int maxindex)
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


void	selected_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*head;
	int		max;
	int		position;

	while (stack_a->size > 2)
	{
		head = stack_a->top;
		max = get_min_index(stack_a);
		position = get_position(stack_a, max);
		while (stack_a->top->index != max)
		{
			if (position >= stack_a->size / 2)
				rra(stack_a, 0);
			else
				ra(stack_a, 0);
		}
		pb(stack_a, stack_b);
	}
	sort_asc(stack_a, 'A');
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
	//set_index(stack_a);
}
