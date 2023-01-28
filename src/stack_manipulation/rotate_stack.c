/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:35:15 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/27 08:35:05 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_push_swap.h"

void	rotate_stack(t_stack *stack, char *msg)
{
	t_node	*node;

	if (stack == NULL || stack->size < 1)
		return ;
	if (stack->size == 2)
	{
		swap_stack(stack, msg);
		return ;
	}
	node = pop_stack(stack);
	if (node == NULL)
		return ;
	push_tail(stack, node);
	ft_printf("r");
	ft_printf(msg);
}

void	reverse_rotate_stack(t_stack *stack, char *msg)
{
	t_node	*last_node;

	if (stack == NULL || stack->size == 0)
		return ;
	last_node = pop_last(stack);
	if (last_node == NULL)
		return ;
	push_head(stack, last_node);
	ft_printf("rr");
	ft_printf(msg);
}

void	rotate_2_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	rotate_stack(stack_a, "a\n");
	rotate_stack(stack_b, "b\n");
}

void	reverse_rotate_2_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	reverse_rotate_stack(stack_a, "a\n");
	reverse_rotate_stack(stack_b, "b\n");
}
