/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 07:52:59 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/25 16:18:52 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap_checker.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (stack->size < 1)
		return (0);
	current = stack->head;
	while (current->next)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}
