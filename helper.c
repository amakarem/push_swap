/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:20:02 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/19 00:06:24 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	swapped;
	int	temp;

	i = 0;
	while (i < n - 1)
	{
		swapped = 0;
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}

int find_unindexed_min(t_stack* stack)
{
    t_node* current;
    int min;

	current = stack->top;
	min = current->value;
    while (current != NULL)
	{
        if (current->index == -1 && current->value < min)
            min = current->value;
        current = current->next;
    }
    return min;
}

int	set_index(t_stack *stack)
{
	t_node	*current;
	int		i;
	int		min;

	i = 0;
	while (i < stack->size)
	{
		current = stack->top;
		min = find_unindexed_min(stack);
		while (current->value != min)
			current = current->next;
		current->index = i++;
	}
	return (0);
}


int	set_index_OLD(t_stack *stack)
{
	t_node	*current;
	int		i;
	int		*arr;

	current = stack->top;
	arr = malloc(sizeof(int) * stack->size);
	if (!arr)
		return (-1);
	i = 0;
	while (current != NULL)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	bubble_sort(arr, stack->size);
	i = 0;
	while (i < stack->size)
	{
		current = stack->top;
		while (current->value != arr[i])
			current = current->next;
		current->index = i++;
	}
	free(arr);
	return (0);
}
