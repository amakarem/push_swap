/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:31:09 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/19 00:57:28 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_node {
	int				index;
	int				value;
	struct s_node	*next;
}	t_node;
typedef struct s_stack {
	t_node	*top;
	int		size;
}	t_stack;

int		ft_printf(const char *format, ...);
int		ft_isnum(char *s);
t_stack	*init_stack(void);
int		ft_already_exist_stack(t_stack *stack, int n);
int		push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	free_stack(t_stack *stack);
void	print_stack(t_stack *stack);
int		ft_isnum(char *s);
int		is_sorted_stack(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a, int noprint);
void	rb(t_stack *stack_b, int noprint);
void	rra(t_stack *stack_a, int noprint);
void	rrb(t_stack *stack_b, int noprint);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
// int		find_min_index(t_stack *stack);
void	set_index(t_stack *stack);
void	sort_stack(t_stack *stack, t_stack *stack_b);
void	sort_stack_100(t_stack *stack, t_stack *stack_b);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);
void	push_swap(t_stack *stack_a, t_stack *stack_b);
#endif
