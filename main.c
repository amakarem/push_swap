/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:34:26 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/05 01:38:43 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	sort_stack(a, b);
	//print_stack(a);
	return (free_stack(a), free_stack(b), 0);
}
