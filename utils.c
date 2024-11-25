/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:47:53 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/25 19:57:07 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *stack, t_stack *stack_b)
{
	int	min_index;

	sort_asc_by_index(stack, 'A');
	while (stack->size > 0 && !is_sorted_stack(stack))
	{
		sort_asc_by_index(stack, 'A');
		min_index = get_position(stack, get_min_index(stack));
		while (stack->top->index != get_min_index(stack))
		{
			if (min_index < stack->size / 2)
				ra(stack, 0);
			else
				rra(stack, 0);
			if (stack->top->index == get_min_index(stack))
				break ;
		}
		if (!is_sorted_stack(stack))
			ra(stack, 0);
		sort_asc_by_index(stack, 'A');
	}
	while (stack_b->size > 0)
		pa(stack, stack_b);
	if (!is_sorted_stack(stack))
		sort_stack(stack, stack_b);
}

char	**ft_free_ar(char	**arr)
{
	int	i;

	if (arr == NULL)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

void	sort_basic(t_stack *stack)
{
	sort_asc_by_index(stack, 'A');
	if (is_sorted_stack(stack))
		return ;
	if (stack->top->index > stack->top->next->index)
	{
		if (stack->top->index < stack->top->next->next->index)
			sa(stack);
		else if (stack->top->next->index > stack->top->next->next->index)
		{
			sa(stack);
			rra(stack, 0);
		}
		else
			ra(stack, 0);
	}
	else if (stack->top->index < stack->top->next->index)
	{
		if (stack->top->index > stack->top->next->next->index)
			rra(stack, 0);
		else if (stack->top->next->index > stack->top->next->next->index)
		{
			sa(stack);
			ra(stack, 0);
		}
	}
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 1)
		return ;
	set_index(stack_a);
	if (is_sorted_stack(stack_a))
		return ;
	if (stack_a->size > 3)
		maping_sort(stack_a, stack_b);
	else
		sort_basic(stack_a);
}
