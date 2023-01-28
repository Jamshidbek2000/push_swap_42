/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 07:19:31 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/27 11:23:36 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap.h"

void	sort_for_2(t_stack *stack, char *msg)
{
	if (stack == NULL || stack->size < 2 || msg == NULL)
		return ;
	swap_stack(stack, msg);
}

void	sort_for_3(t_stack *stack, char *msg)
{
	int	first;
	int	second;
	int	third;

	if (stack == NULL || stack->size < 2 || msg == NULL)
		return ;
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
	int		top_rotation_count;
	int		down_rotation_count;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	while (stack_a->size != 3)
	{
		min_node = get_min_node(stack_a);
		down_rotation_count = count_rotations_to_down(stack_a, min_node) + 1;
		top_rotation_count = count_rotations_to_top(stack_a, min_node);
		if (down_rotation_count < top_rotation_count)
			while (stack_a->head != min_node)
				reverse_rotate_stack(stack_a, "a\n");
		else
			while (stack_a->head != min_node)
				rotate_stack(stack_a, "a\n");
		push_to_from(stack_b, stack_a, "b\n");
	}
	sort_for_3(stack_a, "a\n");
	while (stack_b->size != 0)
		push_to_from(stack_a, stack_b, "a\n");
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_a->size < 2 || stack_b == NULL)
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
