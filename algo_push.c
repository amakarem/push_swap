/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:22:13 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/24 20:20:05 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*top_node;
	int index;

	if (stack_b->size == 0)
		return ;
	top_node = stack_b->top;
	index = top_node->index;
	if (push(stack_a, pop(stack_b), index) == -1)
	{
		ft_printf("Error: push failed\n");
		return ;
	}
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*top_node;
	int index;

	if (stack_a->size == 0)
		return ;
	top_node = stack_a->top;
	index = top_node->index;
	if (push(stack_b, pop(stack_a), index) == -1)
	{
		ft_printf("Error: push failed\n");
		return ;
	}
	ft_printf("pb\n");
}
