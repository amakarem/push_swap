/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:20:02 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/19 00:52:26 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_unindexed_min(t_stack* stack)
{
    t_node* current;
    int min;

	current = stack->top;
	while (current->next != NULL)
	{
        if (current->index == -1)
            break;
        current = current->next;
    }
	min = current->value;
    while (current != NULL)
	{
        if (current->index == -1 && current->value < min)
            min = current->value;
        current = current->next;
    }
    return min;
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
				break;
			}
			current = current->next;
		}
		i++;
	}
}
