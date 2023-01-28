/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 08:08:54 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/27 08:12:16 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap.h"

t_node	*get_min_node(t_stack *stack)
{
	t_node	*min;
	t_node	*current;

	if (stack == NULL || stack->size < 1)
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
