/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 07:19:31 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/25 11:24:26 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap.h"

t_node	*get_min_node(t_stack *stack)
{
	t_node	*min;
	t_node	*current;

	if (stack == NULL || stack->size < 1) // was < 2. why?
		return (NULL);
	min = stack->head;
	current = stack->head;
	while (current != NULL)
	{
		if (current->num < min->num)
			min = current;
		current = current->next;
	}
	return (min);	
}

t_node	*get_max_node(t_stack *stack)
{
	t_node	*max;
	t_node	*current;

	if (stack == NULL || stack->size < 1)
		return (NULL);
	
	max = stack->head;
	current = stack->head;
	while (current != NULL)
	{
		if (current-> num > max->num)
			max = current;
		current = current->next;
	}
	return (max);
}

void	sort_for_2(t_stack *stack, char *msg)
{
	swap_stack(stack, msg);
}

void sort_for_3(t_stack *stack, char *msg)
{
	int	first;
	int	second;
	int	third;

	first = stack->head->num;
	second = stack->head->next->num;
	third = stack->tail->num;
	
	if (first > second && first < third && second < third)
		swap_stack(stack, msg);
	else if (first > second && first > third && second < third)
		rotate_stack(stack, msg);
	else if (first < second && first > third && second > third)
		reverse_rotate_stack(stack, msg);
	else if (first > second && first > third && second > third)
	{
		swap_stack(stack, msg);
		reverse_rotate_stack(stack, msg);
	}
	else if (first < second && first < third && second > third)
	{
		swap_stack(stack, msg);
		rotate_stack(stack, msg);
	}
}

void	sort_for_7(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*min_node;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	// repeate until stack_a->size == 3
	while (stack_a->size != 3)
	{
		min_node = get_min_node(stack_a);
		if (count_rotations_to_down(stack_a, min_node) + 1 < count_rotations_to_top(stack_a, min_node))
		{
			while (stack_a->head != min_node)
			{
				reverse_rotate_stack(stack_a, "a\n");
			}
		}
		else
		{
			while (stack_a->head != min_node)
			{
				rotate_stack(stack_a, "a\n");
			}
		}
	push_to_from(stack_b, stack_a, "b\n");
	}
	sort_for_3(stack_a, "a\n");
	while (stack_b->size != 0)
	{
		push_to_from(stack_a, stack_b, "a\n");
	}
	
}

void	k_sort1(t_stack *stack_a, t_stack *stack_b)
{
	int	index;
	int	range;

	index = 0;
	range = ft_sqrt(stack_a->size) * 14 / 10;
	while (stack_a->head)
	{
		if (stack_a->head->index_sorted <= index)
		{
			push_to_from(stack_b, stack_a, "b\n");
			rotate_stack(stack_b, "b\n");
			index++;
		}
		else if (stack_a->head->index_sorted <= index + range)
		{
			push_to_from(stack_b, stack_a, "b\n");
			index++;
		}
		else
			rotate_stack(stack_a, "a\n");
	}
}

void	k_sort2(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*max;

	while (stack_b->size != 0)
	{
		max = get_max_node(stack_b);
		if (count_rotations_to_down(stack_b, max) + 1 < count_rotations_to_top(stack_b, max))
		{
			while (stack_b->head != max)
			{
				reverse_rotate_stack(stack_b, "b\n");
			}			
		}
		else
		{
			while (stack_b->head != max)
			{
				rotate_stack(stack_b, "b\n");
			}			
		}
		push_to_from(stack_a, stack_b, "a\n");
	}
	
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_a->size < 2)
		return ;
	else if (stack_a->size == 2)
		sort_for_2(stack_a, "a\n");
	else if (stack_a->size == 3)
		sort_for_3(stack_a, "a\n");
	else if (stack_a->size <= 7)
		sort_for_7(stack_a, stack_b);
	else
	{
		k_sort1(stack_a, stack_b);
		k_sort2(stack_a, stack_b);
	}
}
