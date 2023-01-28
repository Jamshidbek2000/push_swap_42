/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:12:54 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/27 08:32:28 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_push_swap.h"

void	print_stack(t_stack *stack, int incl_index)
{
	if (stack == NULL)
		return ;
	ft_printf("STACK %d: ", stack->size);
	if (stack->size == 0)
		return ;
	print_nodes(stack->head, incl_index);
}
