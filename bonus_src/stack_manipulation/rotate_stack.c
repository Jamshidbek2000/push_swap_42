/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:35:15 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/25 10:45:14 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_push_swap_checker.h"

void	rotate_stack(t_stack *stack)
{
	t_node	*node;

	if (stack == NULL || stack->size < 1)
		return ;
	if (stack->size == 2)
	{
		swap_stack(stack);
		return ;
	}
	node = pop_stack(stack); // size + 1
	if (node == NULL)
		return ;
	push_tail(stack, node);
}

void	reverse_rotate_stack(t_stack *stack)
{
	t_node	*last_node;

	if (stack == NULL || stack->size == 0)
		return ;
	last_node = pop_last(stack);
	if (last_node == NULL)
		return ;
	push_head(stack, last_node);
}

void	rotate_2_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	rotate_stack(stack_a);
	rotate_stack(stack_b);
}

void	reverse_rotate_2_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
}
