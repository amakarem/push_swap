/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:29:44 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/07 17:54:21 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_pos_correct(t_stack *stack, int min_value, int min_index)
{
	t_node	*current;
	int		index;

	if (stack->size == 0)
        return (1);
	current = stack->top;
	index = 0;
    while (current != NULL && index <= min_index)
	{
        if (current->value >= min_value)
			return (0);
        current = current->next;
		index++;
    }
    return (1);
}

int	last_max(t_stack *stack)
{
	t_node	*current;
	int		index;

	if (stack->size == 0)
        return (0);
	current = stack->top;
	index = 0;
    while (current->next != NULL)
	{
        if (current->value > current->next->value)
			return (current->value);
        current = current->next;
		index++;
    }
	return (current->value);
}

int	find_min_index(t_stack *stack)
{
	t_node	*current;
    int	min_value;
    int	min_index;
    int	index;

	if (stack->size == 0)
        return -1;
	current = stack->top;
	min_value = last_max(stack);
    min_index = 0;
    index = 0;
    while (current != NULL)
	{
        if (current->value < min_value && !is_pos_correct(stack, current->value, index))
		{
            min_value = current->value;
            min_index = index;
        }
        current = current->next;
		index++;
    }
    return (min_index);
}

void	sort_stack(t_stack *stack, t_stack *stack_b)
{
	int min_index;
	int current_index;

	while (stack->size > 0 && !is_sorted_stack(stack))
	{
		if (stack->size >= 2 && stack->top->value > stack->top->next->value)
		{
        	sa(stack);
			continue;
		}
		min_index = find_min_index(stack);
		if (min_index == -1)
			return ;
		// if ((min_index + 1) == stack->size)
		// {
		// 	rra(stack);
		// 	continue;
		// }
		current_index = 0;
        while (current_index < min_index)
		{
			if (min_index < stack->size)
				ra(stack);
			else
				rra(stack);
            current_index++;
        }
		pb(stack, stack_b);
    }
	while (stack_b->size > 0)
        pa(stack, stack_b);
	if (!is_sorted_stack(stack))
		sort_stack(stack, stack_b);
}
