/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:29:44 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/23 19:14:41 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_pos_correct(t_stack *stack, int min_value, int min_index)
{
	t_node	*current;
	int		index;

	if (stack->size == 0)
		return (1);
	current = stack->top;
	index = 0;
	while (current != NULL && index <= min_index)
	{
		if (current->value >= min_value)
			return (0);
		current = current->next;
		index++;
	}
	return (1);
}

int	last_max(t_stack *stack)
{
	t_node	*current;
	int		index;

	if (stack->size == 0)
		return (0);
	current = stack->top;
	index = 0;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (current->value);
		current = current->next;
		index++;
	}
	return (current->value);
}

int	find_min_index(t_stack *stack)
{
	t_node	*current;
	int		min_value;
	int		min_index;
	int		index;

	current = stack->top;
	min_value = current->value;
	min_index = 0;
	index = 0;
	while (current != NULL)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	return (min_index);
}

int	find_max_index(t_stack *stack, int last_max)
{
	t_node	*current;
	int		max_value;
	int		max_index;
	int		index;

	current = stack->top;
	max_value = current->value;
	max_index = 0;
	index = 0;
	while (current != NULL)
	{
		if (current->value > max_value && current->value < last_max)
		{
			max_value = current->value;
			max_index = index;
		}
		current = current->next;
		index++;
	}
	return (max_index);
}

int	get_value(t_stack *stack, int index)
{
	t_node	*current;
	int		value;
	int		v_index;

	current = stack->top;
	value = current->value;
	v_index = 0;
	while (current != NULL && v_index <= index)
	{
		if (v_index == index)
		{
			value = current->value;
			break;
		}
		current = current->next;
		v_index++;
	}
	return (value);
}

void	sort_asc(t_stack *stack, char adr)
{
	if (stack->size >= 2 && stack->top->index > stack->top->next->index)
	{
		if (adr == 'a' || adr == 'A')
			sa(stack);
		else
			sb(stack);
	}
}

static void	sort_desc(t_stack *stack, char adr)
{
	if (stack->size >= 2 && stack->top->index < stack->top->next->index)
	{
		if (adr == 'a' || adr == 'A')
			sa(stack);
		else
			sb(stack);
	}
}

void	sort_stack(t_stack *stack, t_stack *stack_b)
{
	int	min_index;
	int	min_value;
	int	current_index;

	while (stack->size > 0 && !is_sorted_stack(stack))
	{
		sort_asc(stack, 'a');
		min_index = find_min_index(stack);
		min_value = get_value(stack, min_index);
		current_index = 0;
		while (current_index < min_index && stack->top->value != min_value)
		{
			if (min_index < stack->size / 2)
				ra(stack, 0);
			else
				rra(stack, 0);
			current_index++;
			if (stack->top->value == min_value)
				break;
		}
		if (!is_sorted_stack(stack))
			pb(stack, stack_b);
	}
	while (stack_b->size > 0)
		pa(stack, stack_b);
	if (!is_sorted_stack(stack))
		sort_stack(stack, stack_b);
		// print_stack(stack);
}

int findMax(t_stack* stack, int last_max)
{
    t_node* current;
    int max;

	current = stack->top;
	max = current->value;
    while (current != NULL)
	{
        if (current->value > max && current->value < last_max) {
            max = current->value;
        }
        current = current->next;
    }
    return max;
}

int findValIndex(t_stack* stack, int val) {
    t_node* current;
    int valindex;

	current = stack->top;
	valindex = 0;
    while (current != NULL)
	{
        if (current->value == val) {
            return (valindex);
        }
        current = current->next;
		valindex++;
    }
    return (valindex);
}

int findMin(t_stack* stack, int last_min)
{
    t_node* current;
    int min;

	current = stack->top;
	min = current->value;
    while (current != NULL)
	{
        if (current->value < min && current->value > last_min) {
            min = current->value;
        }
        current = current->next;
    }
    return min;
}


#include <stdio.h>

int get_chepest_move(t_stack* stack, int rev)
{
    int max;
	int maxindex;
	int moves;

	max = 2147483647;
	if (rev == 1)
		max = -2147483648;
	moves = stack->size;
	while (moves > 1)
	{
		if (rev == 1)
			max = findMin(stack, max);
		else
			max = findMax(stack, max);
		maxindex = findValIndex(stack, max);
		if (maxindex >= (stack->size / 2))
			moves = stack->size - maxindex;
		else
			moves = maxindex;
	}
	return (max);
}

void sortStackDesc(t_stack* stack, t_stack *stack_a) {
	int max;
	int maxindex;
	
	max = 2147483647;
    while (stack->size > 0) {
        max = findMax(stack, max);
		maxindex = findValIndex(stack, max);
		if (maxindex >= stack->size / 2)
		{
			while (stack->top->value != max) {
				rrb(stack, 0);
			}
		}
		else
		{
	        while (stack->top->value != max) {
	           	rb(stack, 0);
        	}
		}
		pa(stack_a, stack);
    }
}

void	sort_single(t_stack *stack)
{
	int	max_index;
	int	max_value;
	int	current_index;
	print_stack(stack);
	max_value = stack->top->value;
	while (!is_sorted_stack(stack))
	{
		sort_desc(stack, 'b');
		max_index = find_max_index(stack, max_value);
		max_value = get_value(stack, max_index);
		current_index = 0;
		while (current_index < max_index && stack->top->value != max_value)
		{
			if (max_index > stack->size / 2)
				rb(stack, 0);
			else
				rrb(stack, 0);
			current_index++;
			if (stack->top->value == max_value)
				break;
		}
		print_stack(stack);
		break;
	}
}

void	get_stack_ready(t_stack *stack, int newval)
{
	int maxindex;
	int val;
	int	current_index;

	if (stack->size <= 1)
		return ;
	val = findMax(stack, newval);
	maxindex = findValIndex(stack, val);
	current_index = 0;
	while (current_index < maxindex && stack->top->value != val)
	{
		if (maxindex >= stack->size / 2)
			rrb(stack, 0);
		else
			rb(stack, 0);
		current_index++;
		if (stack->top->value == val)
			break;
	}
}

void	get_asc_stack_ready(t_stack *stack, int newval)
{
	int maxindex;
	int val;
	int	current_index;

	if (stack->size <= 1)
		return ;
	val = findMin(stack, newval);
	maxindex = findValIndex(stack, val);
	current_index = 0;
	while (current_index < maxindex && stack->top->value != val)
	{
		if (maxindex >= stack->size / 2)
			rra(stack, 0);
		else
			ra(stack, 0);
		current_index++;
		if (stack->top->value == val)
			break;
	}
}

void	move_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int max;
	int maxindex;
	int	current_index;

	while (stack_a->size > 0)
	{
		if (stack_b->size >= 2)
		{
			max = get_chepest_move(stack_a, 0);
			maxindex = findValIndex(stack_a, max);
			current_index = 0;
			while (current_index < maxindex && stack_a->top->value != max)
			{
				if (maxindex >= stack_a->size / 2)
					rra(stack_a, 0);
				else
					ra(stack_a, 0);
				current_index++;
				if (stack_a->top->value == max)
					break;
			}
		}
		get_stack_ready(stack_b, max);
		pb(stack_a, stack_b);
	}
}

void	move_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int min;
	int minindex;
	int	current_index;

	while (stack_b->size > 0)
	{
		if (stack_a->size >= 2)
		{
			min = get_chepest_move(stack_b, 1);
			minindex = findValIndex(stack_b, min);
			current_index = 0;
			while (current_index < minindex && stack_b->top->value != min)
			{
				if (minindex >= stack_b->size / 2)
					rra(stack_b, 0);
				else
					ra(stack_b, 0);
				current_index++;
				if (stack_b->top->value == min)
					break;
			}
		}
		get_asc_stack_ready(stack_a, min);
		pa(stack_a, stack_b);
	}
}

void	sort_stack_100(t_stack *stack_a, t_stack *stack_b)
{
	//int max;
	//int maxindex;
	//int	current_index;
set_index(stack_a);
	print_stack(stack_a);
return ;

	if (stack_a->size > 3 && !is_sorted_stack(stack_a))
	{
		move_to_b(stack_a, stack_b);
			print_stack(stack_b);
			ft_printf("\n-----------");
		move_to_a(stack_a, stack_b);
	}
	// sort_asc(stack_a, 'A');
	// while (stack_b->size > 0)
	// {
	// 	pa(stack_a, stack_b);
	// 	sort_asc(stack_a, 'A');
	// }
	if (!is_sorted_stack(stack_a))
		sort_stack_100(stack_a, stack_b);
	print_stack(stack_a);
}


void	sort_stack_100XXXX(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	while (stack_a->size > 2)
	{
		if (stack_b->size >= 2)
		{
			i = 0;
			while (i < stack_a->size)
			{
				if (stack_a->top->value > stack_b->top->value && stack_a->top->value > stack_b->top->next->value)
					break;
				ra(stack_a, 0);
				i++;
			}
		}
		pb(stack_a, stack_b);
		sort_desc(stack_b, 'b');
	}
	print_stack(stack_b);
}

void	sort_stack_100_chink(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int total_size;
	int i;
	int j;

	total_size = stack_a->size;
	chunk_size = stack_a->size / 2;
	j = 0;
	while (j <= total_size && !is_sorted_stack(stack_a))
	{
		i = 0;
		while (total_size > 0 && i <= chunk_size && !is_sorted_stack(stack_a))
		{
			pb(stack_a, stack_b);
			sort_desc(stack_b, 'b');
			i++;
			j++;
		}
			//print_stack(stack_b);
		sortStackDesc(stack_b, stack_a);
		print_stack(stack_b);
		break;
		if ((!is_sorted_stack(stack_a)))
		{
			while (i-- > 0)
				ra(stack_a, 0);
		}
	}
	// if (!is_sorted_stack(stack_a))
	// 	sort_stack_100(stack_a, stack_b);
	print_stack(stack_a);
	// while (stack_b->size > 0)
	// {
	// 	pa(stack_a, stack_b);
	// 	sort_asc(stack_a, 'a');
	// }
	// while (stack_b->size > 0)
	// {
	// 	pa(stack_a, stack_b);
	// 	sort_asc(stack_a, 'a');
	// }
	// if (!is_sorted_stack(stack_a))
	// 	sort_stack(stack_a, stack_b);
	//print_stack(stack_b);
	// //sort_stack(stack_a, stack_b);

}

// void	sort_stackxx(t_stack *stack, t_stack *stack_b)
// {
// 	int	min_index;
// 	int	current_index;
// 	int	next_index;
// 	t_node	*current;

// 	while (stack->size > 0 && !is_sorted_stack(stack))
// 	{
// 		sort_one(stack);
// 		current = stack->top;
// 		next_index = 0;
// 		while (current->value < last_max(stack))
// 		{
// 			current = current->next;
// 			next_index++;
// 		}
// 		current_index = 0;
// 		while (current_index < next_index)
// 		{
// 			ft_printf("\n%d --- %d --- %d", current_index, next_index, last_max(stack));
// 			if (next_index < stack->size / 2)
// 				ra(stack, 0);
// 			else
// 				rra(stack, 0);
// 			current_index++;
// 		}
// 		pb(stack, stack_b);
// 		sort_one(stack_b);
// 	}
// 	print_stack(stack);
// 	ft_printf("\n%d --- %d --- %d\n", current_index, next_index, last_max(stack));
// 		print_stack(stack_b);
// 		return;
// 	while (stack_b->size > 0)
// 		pa(stack, stack_b);
// 	// if (!is_sorted_stack(stack))
// 	// 	sort_stack(stack, stack_b);
// }
