/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 07:40:18 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/27 08:33:15 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap.h"

void	print_array(long *array, int size)
{
	int		index;

	index = 0;
	while (index < size)
	{
		ft_printf("%d ", array[index]);
		index++;
	}
}

void	print_node_num(t_node *node)
{
	if (node == NULL)
		return ;
	ft_printf(" %d", node->num);
}

void	print_node_index(t_node *node)
{
	if (node == NULL)
		return ;
	ft_printf("-[%d]", node->index_sorted);
}

void	print_node(t_node *node)
{
	if (node == NULL)
		return ;
	ft_printf(" %d-[%d]", node->num, node->index_sorted);
}

// if incl_ind == 0 it will print only number
// if incl_ind == 1 it will print also indeces
void	print_nodes(t_node *head, int include_ind)
{
	t_node	*curr;

	if (head == NULL)
		return ;
	curr = head;
	while (curr != NULL)
	{
		print_node_num(curr);
		if (include_ind != 0)
			print_node_index(curr);
		curr = curr->next;
	}
	ft_printf(" END STACK\n");
}
