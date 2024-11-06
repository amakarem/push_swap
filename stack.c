/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:40:21 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/06 16:36:50 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

int	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (-1);
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
	return (0);
}

int	pop(t_stack *stack)
{
	int		value;
	t_node	*top_node;

	if (stack->size == 0)
		return (-1);
	top_node = stack->top;
	value = top_node->value;
	stack->top = top_node->next;
	free(top_node);
	stack->size--;
	return (value);
}

void	free_stack(t_stack *stack)
{
	while (stack->size > 0)
		pop(stack);
	free(stack);
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
}
