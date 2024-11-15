/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:06:51 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/11 22:10:26 by aelaaser         ###   ########.fr       */
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

int	is_sorted_stack(t_stack *stack)
{
	t_node	*current;
	int		index;

	if (stack->size == 0)
		return (1);
	current = stack->top;
	index = 0;
	while (current->next != NULL && index < stack->size)
	{
		if (current->value > current->next->value)
		{
			ft_printf("\nNOT SORTED HERE %d > %d \n", current->value, current->next->value);
			return (0);
		}
		current = current->next;
		index++;
	}
	return (1);
}
