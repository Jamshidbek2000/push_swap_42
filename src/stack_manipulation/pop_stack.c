/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:54:43 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/23 14:02:29 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_push_swap.h"

t_node	*pop_stack(t_stack *stack)
{
	t_node	*node;

	if (stack == NULL)
		return (NULL);
	if (stack->size == 0)
		return(NULL);
	node = stack->head;
	if (stack->size != 1) // not only element in stack [] []
	{
		stack->head = stack->head->next;
		stack->size--;
	}
	else if (stack->size == 1)
	{
		stack->head = NULL;
		stack->tail = NULL;
		stack->size = 0;
	}
	node->next = NULL;
	return (node);
}

t_node	*pop_last(t_stack *stack)
{
	t_node	*curr_node;
	t_node	*last_node;

	if (stack == NULL || stack->size == 0 || stack->head == NULL)
		return (NULL);
	if (stack->size == 1)
		return (pop_stack(stack));
	curr_node = stack->head;
	last_node = stack->tail;
	
	while (curr_node->next != last_node)
	{
		curr_node = curr_node->next;
	}
	curr_node->next = NULL;
	stack->size--;
	stack->tail = curr_node;
	return (last_node);
}
