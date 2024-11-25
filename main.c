/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:34:26 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/25 04:46:31 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *stack, t_stack *stack_b)
{
	int	min_index;

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
			pb(stack, stack_b);
	}
	while (stack_b->size > 0)
		pa(stack, stack_b);
	if (!is_sorted_stack(stack))
		sort_stack(stack, stack_b);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 1)
		return ;
	set_index(stack_a);
	if (stack_a->size > 3)
		maping_sort(stack_a, stack_b);
	else
		sort_stack(stack_a, stack_b);
}

int	parse_input(t_stack *a, int argc, char **argv, int end)
{
	int		i;

	i = argc - 1;
	while (i > end)
	{
		if (!ft_isnum(argv[i]) || ft_already_exist_stack(a, ft_atoi(argv[i])))
		{
			ft_putendl_fd("Error", 2);
			return (-1);
		}
		push(a, ft_atoi(argv[i]), -1);
		i--;
	}
	return (1);
}

static int	ft_array_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (ft_putendl_fd("Error", 2), -1);
	a = init_stack();
	if (!a)
		return (ft_putendl_fd("Error", 2), -1);
	b = init_stack();
	if (!b)
		return (ft_putendl_fd("Error", 2), free_stack(a), -1);
	if (argc == 2 && !ft_isnum(argv[1]))
	{
		argv = ft_split(argv[1], ' ');
		argc = ft_array_len(argv);
		if (parse_input(a, argc, argv, -1) == 1)
			push_swap(a, b);
		free(argv);
	}
	else if (parse_input(a, argc, argv, 0) == 1)
		push_swap(a, b);
	return (free_stack(a), free_stack(b), 0);
}
