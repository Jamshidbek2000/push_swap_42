/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:35:15 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/25 08:22:17 by jergashe         ###   ########.fr       */
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
	node = pop_stack(stack); // size + 1
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
