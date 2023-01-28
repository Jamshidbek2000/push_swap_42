/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 08:10:38 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/27 08:27:09 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap.h"

void	k_sort1(t_stack *stack_a, t_stack *stack_b)
{
	int	index;
	int	range;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	index = 0;
	range = ft_sqrt(stack_a->size) * 14 / 10;
	while (stack_a->head)
	{
		if (stack_a->head->index_sorted <= index)
		{
			push_to_from(stack_b, stack_a, "b\n");
			rotate_stack(stack_b, "b\n");
			index++;
		}
		else if (stack_a->head->index_sorted <= index + range)
		{
			push_to_from(stack_b, stack_a, "b\n");
			index++;
		}
		else
			rotate_stack(stack_a, "a\n");
	}
}

void	k_sort2(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*max;
	int		top_rotation_count;
	int		down_rotation_count;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	while (stack_b->size != 0)
	{
		max = get_max_node(stack_b);
		down_rotation_count = count_rotations_to_down(stack_b, max) + 1;
		top_rotation_count = count_rotations_to_top(stack_b, max);
		if (down_rotation_count < top_rotation_count)
			while (stack_b->head != max)
				reverse_rotate_stack(stack_b, "b\n");
		else
			while (stack_b->head != max)
				rotate_stack(stack_b, "b\n");
		push_to_from(stack_a, stack_b, "a\n");
	}
}
