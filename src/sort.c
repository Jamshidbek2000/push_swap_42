/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 07:19:31 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/24 11:14:33 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap.h"

t_node	*get_min_node(t_stack *stack)
{
	t_node	*min;
	t_node	*current;

	if (stack == NULL || stack->size < 2)
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
	int		opr_count;

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
}
