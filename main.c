/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:34:26 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/07 17:59:48 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->size <= 1)
        return;
	// if (stack->size >= 1000)
    // 	quick_sort_stack(stack_a, stack_b, 0, ft_stacksize(stack_a) - 1);
	// // else if (stack->size >= 1000)
	// // 	radix_sort(stack_a, stack_b);
	// else
		sort_stack(stack_a, stack_b);
}


int	main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = init_stack();
	if (!a)
		return (ft_printf("Error\n"), -1);
	b = init_stack();
	if (!b)
		return (ft_printf("Error\n"), free_stack(a), -1);
	i = argc - 1;
	while (i > 0)
	{
		if (!ft_isnum(argv[i]) || ft_already_exist_stack(a, ft_atoi(argv[i])))
		{
			ft_printf("Error\n");
			return (free_stack(a), -1);
		}
		push(a, ft_atoi(argv[i]));
		i--;
	}
	push_swap(a, b);
	// print_stack(a);
	return (free_stack(a), free_stack(b), 0);
}
