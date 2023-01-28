/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 07:52:59 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/27 08:06:05 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap.h"

int	get_min_index(t_stack *stack)
{
	t_node	*current;
	int		min_index;

	if (stack == NULL)
		return (-1);
	if (stack->head == NULL)
		return (-1);
	current = stack->head;
	min_index = current->index_sorted;
	while (current->next)
	{
		current = current->next;
		if (current->index_sorted < min_index)
			min_index = current->index_sorted;
	}
	return (min_index);
}

int	count_rotations_to_top(t_stack *stack, t_node *node)
{
	int		count;
	t_node	*current;

	if (stack == NULL || node == NULL)
		return (-1);
	current = stack->head;
	count = 0;
	while (current != node && current->next != NULL)
	{
		count++;
		current = current->next;
	}
	if (stack->size == count)
		return (-1);
	return (count);
}

int	count_rotations_to_down(t_stack *stack, t_node *node)
{
	int	to_top;

	if (stack == NULL || node == NULL)
		return (-1);
	to_top = count_rotations_to_top(stack, node);
	if (to_top == -1)
		return (-1);
	return (stack->size - to_top - 1);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL)
		return (-1);
	if (stack->head == NULL)
		return (-1);
	current = stack->head;
	while (current->next)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}
