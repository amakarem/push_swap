/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:34:26 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/25 16:22:59 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exit_app(int sts)
{
	if (sts != 0)
		return (ft_putendl_fd("Error", 2), -1);
	return (0);
}

int	parse_input(t_stack *a, int argc, char **argv, int end)
{
	int		i;

	i = argc - 1;
	while (i > end)
	{
		if (!ft_isnum(argv[i]) || ft_already_exist_stack(a, ft_atoi(argv[i])))
			return (-1);
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
	if ((argc == 2 && argv[1][0] == '\0'))
		return (exit_app(-1));
	a = init_stack();
	if (!a)
		return (exit_app(-1));
	b = init_stack();
	if (!b)
		return (free_stack(a), exit_app(-1));
	if (argc == 2 && !ft_isnum(argv[1]))
	{
		argv = ft_split(argv[1], ' ');
		argc = ft_array_len(argv);
		if (parse_input(a, argc, argv, -1) != 1)
			return (free(argv), free_stack(a), free_stack(b), exit_app(-1));
	}
	else if (parse_input(a, argc, argv, 0) != 1)
		return (free_stack(a), free_stack(b), exit_app(-1));
	push_swap(a, b);
	return (free_stack(a), free_stack(b), 0);
}
