/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:44:09 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/25 09:17:46 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_push_swap_checker.h"

void	free_stack(t_stack *stack)
{
	t_node *current;
	t_node *next;

	current = stack->head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
