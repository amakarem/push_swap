/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:29:44 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/06 20:00:51 by aelaaser         ###   ########.fr       */
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

int	is_sorted_stack(t_stack *stack)
{
	t_node	*current;
	int		index;

	if (stack->size == 0)
        return (1);
	current = stack->top;
	index = 0;
    while (current->next)
	{
        if (current->value > current->next->value)
			return (0);
        current = current->next;
		index++;
    }
    return (1);
}

void	sort_stack(t_stack *stack, t_stack *stack_b)
{
	int min_index;
	int current_index;

	while (stack->size > 0 && !is_sorted_stack(stack))
	{
		print_stack(stack);
		ft_printf("\n-----------");
		if (stack->size >= 2 && stack->top->value > stack->top->next->value)
		{
        	sa(stack);
			continue;
		}
		min_index = find_min_index(stack);
		ft_printf("%i", min_index);
		if (min_index == -1)
			return ;
		if ((min_index + 1) == stack->size)
		{
			rra(stack);
			continue;
		}
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
