/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:22:13 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/11 21:20:07 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size == 0)
		return ;
    if (push(stack_a, pop(stack_b)) == -1)
    {
        ft_printf("Error: push failed\n");
        return;
    }
    ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 0)
		return ;
    if (push(stack_b, pop(stack_a)) == -1)
    {
        ft_printf("Error: push failed\n");
        return;
    }
}
