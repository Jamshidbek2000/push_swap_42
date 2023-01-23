/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:51:39 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/23 13:50:18 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_push_swap.h"

// Assign the second node to temp
// Assign first node to the second node's next pointer
// Assign temp to the first node's next pointer
// Assign temp to the head of the stack
void	swap_stack(t_stack *stack)
{
	t_node	*tmp;

	if (stack == NULL || stack->size < 2)
		return ;
	tmp = stack->head->next;
	stack->head->next = tmp->next;
	tmp->next = stack->head;
	stack->head = tmp;
	if (stack->size == 2)
		stack->tail = stack->head->next;
}
