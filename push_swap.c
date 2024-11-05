/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:29:44 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/05 01:03:30 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
        i++;
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
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

int	ft_already_exist_stack(t_stack *stack, int n)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		if (current->value == n)
			return (1);
		current = current->next;
	}
	return (0);
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
	min_value = current->value;
    min_index = 0;
    index = 0;
    while (current != NULL)
	{
        if (current->value < min_value) {
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

	if (stack->top && stack->top->next && stack->top->value > stack->top->next->value)
        sa(stack);
	while (stack->size > 0)
	{
		min_index = find_min_index(stack);
		if (min_index == -1)
			return ;
		current_index = 0;
        while (current_index != min_index)
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
}
