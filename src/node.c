/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 08:18:27 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/22 15:09:07 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap.h"

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

t_node	*get_new_node(int num, int index_sorted)
{
	t_node	*node;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->num = num;
	node->index_sorted = index_sorted;
	node->next = NULL;
	return (node);
}

t_node	*get_new_node_with_num(int num)
{
	t_node	*node;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->num = num;
	node->next = NULL;
	return (node);
}

void	add_node_tail(t_node *head, t_node *node)
{
	t_node	*tmp;

	if (head == NULL || node == NULL)
		return ;
	tmp = head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = node;
}

void	add_node_head(t_node *head, t_node *node)
{
	if (head == NULL || node == NULL)
		return ;
	node->next = head;
}

t_node	*move_head_to_tail(t_node *head)
{
	t_node	*current;
	t_node	*new_head;

	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return (head);
	new_head = head->next;
	current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = head;
	head->next = NULL;
	return (new_head);
}

int	get_list_size(t_node *head)
{
	int		size;
	t_node	*curr;

	if (head == NULL)
		return (0);
	size = 1;
	curr = head;
	while (curr->next != NULL)
	{
		curr = curr->next;
		size++;
	}
	return (size);
}
