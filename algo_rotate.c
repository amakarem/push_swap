/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:23:03 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/09 15:51:55 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a, int noprint)
{
	t_node	*first;
	t_node	*last;

	if (stack_a->size < 2)
		return ;
	first = stack_a->top;
	stack_a->top = first->next;
	last = stack_a->top;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (noprint == 0)
		ft_printf("ra\n");
}

void	rb(t_stack *stack_b, int noprint)
{
	t_node	*first;
	t_node	*last;

	if (stack_b->size < 2)
		return ;
	first = stack_b->top;
	stack_b->top = first->next;
	last = stack_b->top;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (noprint == 0)
		ft_printf("rb\n");
}
