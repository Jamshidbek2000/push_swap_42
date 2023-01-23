/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:24:41 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/23 08:03:44 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap.h"

t_stack	*array_to_stack(long *array, int size)
{
	t_stack	*stack_a;
	int		index;
	t_node	*tmp;

	stack_a = malloc(sizeof(*stack_a));
	if (stack_a == NULL)
		return (NULL);
	index = 0;
	stack_a->size = size;
	stack_a->head = get_new_node_with_num(array[index++]);
	tmp = stack_a->head;
	while (index < size)
	{
		tmp->next = get_new_node_with_num(array[index++]); // if error free
		tmp = tmp->next; // every node from head... 
	}
	stack_a->tail = tmp;
	return (stack_a);
}

void	set_stack_indeces(t_stack *stack_a, long *array)
{
	int		index;
	t_node	*tmp;

	index = 0;
	tmp = stack_a->head;
	while (index < stack_a->size) // OR WHILE TMP->NEXT != NULL
	{
		tmp->index_sorted = get_index(array, stack_a->size, tmp->num);
		tmp = tmp->next;
		index++;
	}
}

t_stack	*get_stack_a(long *array, int size)
{
	t_stack	*stack_a;

	stack_a = array_to_stack(array, size);
	bubble_sort_array(array, size);
	print_array(array, size);
	set_stack_indeces(stack_a, array);
	
	return (stack_a);
}
