/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:29:44 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/11 22:39:30 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_pos_correct(t_stack *stack, int min_value, int min_index)
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
	int		min_value;
	int		min_index;
	int		index;

	current = stack->top;
	min_value = current->value;
	min_index = 0;
	index = 0;
	while (current != NULL)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	return (min_index);
}

int	get_value(t_stack *stack, int index)
{
	t_node	*current;
	int		value;
	int		v_index;

	current = stack->top;
	value = current->value;
	v_index = 0;
	while (current != NULL && v_index <= index)
	{
		if (v_index == index)
		{
			value = current->value;
			break;
		}
		current = current->next;
		v_index++;
	}
	return (value);
}


void	sort_one(t_stack *stack)
{
	if (stack->size >= 2 && stack->top->value > stack->top->next->value)
		sa(stack);
}

void	sort_stack(t_stack *stack, t_stack *stack_b)
{
	int	min_index;
	int	min_value;
	int	current_index;

	while (stack->size > 0 && !is_sorted_stack(stack)) //&& !is_sorted_stack(stack)
	{
		sort_one(stack);
		min_index = find_min_index(stack);
		min_value = get_value(stack, min_index);
		current_index = 0;
		while (current_index < min_index && stack->top->value != min_value)
		{
			if (min_index < stack->size / 2)
				ra(stack, 0);
			else
				rra(stack, 0);
			current_index++;
			if (stack->top->value == min_value)
				break;
		}
		if (!is_sorted_stack(stack))
			pb(stack, stack_b);
	}
	while (stack_b->size > 0)
		pa(stack, stack_b);
	if (!is_sorted_stack(stack))
	// 	sort_stack(stack, stack_b);
		print_stack(stack);
}

// void	sort_stackxx(t_stack *stack, t_stack *stack_b)
// {
// 	int	min_index;
// 	int	current_index;
// 	int	next_index;
// 	t_node	*current;

// 	while (stack->size > 0 && !is_sorted_stack(stack))
// 	{
// 		sort_one(stack);
// 		current = stack->top;
// 		next_index = 0;
// 		while (current->value < last_max(stack))
// 		{
// 			current = current->next;
// 			next_index++;
// 		}
// 		current_index = 0;
// 		while (current_index < next_index)
// 		{
// 			ft_printf("\n%d --- %d --- %d", current_index, next_index, last_max(stack));
// 			if (next_index < stack->size / 2)
// 				ra(stack, 0);
// 			else
// 				rra(stack, 0);
// 			current_index++;
// 		}
// 		pb(stack, stack_b);
// 		sort_one(stack_b);
// 	}
// 	print_stack(stack);
// 	ft_printf("\n%d --- %d --- %d\n", current_index, next_index, last_max(stack));
// 		print_stack(stack_b);
// 		return;
// 	while (stack_b->size > 0)
// 		pa(stack, stack_b);
// 	// if (!is_sorted_stack(stack))
// 	// 	sort_stack(stack, stack_b);
// }
