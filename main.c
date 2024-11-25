/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:34:26 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/25 02:07:58 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 1)
		return ;
	set_index(stack_a);
	maping_sort(stack_a, stack_b);
}

int	parse_input(t_stack *a, int argc, char **argv, int end)
{
	int		i;

	i = argc - 1;
	while (i > end)
	{
		if (!ft_isnum(argv[i]) || ft_already_exist_stack(a, ft_atoi(argv[i])))
		{
			ft_printf("Error\n");
			ft_printf("\n%i", argc);
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
		return (0);
	a = init_stack();
	if (!a)
		return (ft_printf("Error\n"), -1);
	b = init_stack();
	if (!b)
		return (ft_printf("Error\n"), free_stack(a), -1);
	if (argc == 2 && !ft_isnum(argv[1]))
	{
		argv = ft_split(argv[1], ' ');
		argc = ft_array_len(argv);
		free(argv);
		if (parse_input(a, argc, argv, -1) == 1)
			push_swap(a, b);
	}
	else if (parse_input(a, argc, argv, 0) == 1)
		push_swap(a, b);
	return (free_stack(a), free_stack(b), 0);
}
