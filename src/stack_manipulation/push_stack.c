/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:38:00 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/27 08:34:43 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_push_swap.h"

void	push_head(t_stack *stack, t_node *node)
{
	if (stack == NULL || node == NULL)
		return ;
	if (stack->size == 0)
	{
		stack->head = node;
		stack->tail = node;
		stack->size++;
	}
	else
	{
		node->next = stack->head;
		stack->head = node;
		stack->size++;
	}
}

void	push_tail(t_stack *stack, t_node *node)
{
	if (stack == NULL || node == NULL)
		return ;
	if (stack->size == 0)
	{
		stack->head = node;
		stack->tail = node;
		stack->size++;
	}
	else
	{
		stack->tail->next = node;
		stack->tail = node;
		stack->size++;
	}
}

void	push_to_from(t_stack *stack_1, t_stack *stack_2, char *msg)
{
	t_node	*node;

	if (stack_1 == NULL || stack_2 == NULL)
		return ;
	if (stack_2->head == NULL)
		return ;
	node = pop_stack(stack_2);
	if (node == NULL)
		return ;
	push_head(stack_1, node);
	ft_printf("p");
	ft_printf(msg);
}
