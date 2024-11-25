/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:31:09 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/25 17:49:21 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_node {
	int				index;
	int				value;
	struct s_node	*next;
}	t_node;
typedef struct s_stack {
	t_node	*top;
	int		size;
	int		best;
}	t_stack;

int		ft_printf(const char *format, ...);
int		ft_isnum(char *s);
t_stack	*init_stack(void);
int		ft_already_exist_stack(t_stack *stack, int n);
int		push(t_stack *stack, int value, int index);
int		pop(t_stack *stack);
void	free_stack(t_stack *stack);
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
int		get_position(t_stack *stack, int maxindex);
void	sort_desc(t_stack *stack, char adr);
void	sort_asc_by_index(t_stack *stack, char adr);
int		get_min_index(t_stack *stack);
void	set_index(t_stack *stack);
int		ft_unsigend(int n);
int		ft_min(int x, int y);
int		get_cost(int a, int b);
int		moves_qty(t_stack *stack, int index);
void	do_move_solo(t_stack *stack, char identity);
void	do_move_common(t_stack *stack_a, t_stack *stack_b);
void	set_b_best(t_stack	*stack_a, t_stack *stack_b);
void	maping_sort(t_stack *stack_a, t_stack *stack_b);
void	sort_stack(t_stack *stack, t_stack *stack_b);
void	push_swap(t_stack *stack_a, t_stack *stack_b);
#endif
