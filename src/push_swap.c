/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:13:53 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/25 08:07:19 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap.h"

int	main(int argc, char **argv)
{
	long	*array;
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	argc_check(argc);
	size = get_num_of_ints(argc, argv);
	array = get_long_arr_from_input(argc, argv);
	
	array_check(array, size);
	stack_a = get_stack_a(array, size);
	stack_b = get_empty_stack();

	// print_stack(stack_a, 1);
	// print_stack(stack_b, 1);
	sort(stack_a, stack_b);
	// print_stack(stack_a, 1);
	// print_stack(stack_b, 1);
	

	free(array);
	free_stack(stack_a);
	free_stack(stack_b);
	// system("leaks push_swap");
	return (0);
}


	// { // check sort_for_7	
	// print_stack(stack_a, 1);
	// sort_for_7(stack_a, stack_b);
	// print_stack(stack_a, 1);
	// print_stack(stack_b, 1);
	// }


	// { // test count rotations to top/down
	// print_stack(stack_a, 1);
	// ft_printf("DOWN: %d\n", count_rotations_to_down(stack_a, get_min_node(stack_a)));
	// ft_printf("TOP: %d\n", count_rotations_to_top(stack_a, get_min_node(stack_a)));
	// }

	// { // check sort_3	
	// print_stack(stack_a, 1);
	// sort_for_3(stack_a, "a\n");
	// print_stack(stack_a, 1);
	// }

	// print_stack(stack_a, 1);
	// {// rotation count check
	// ft_printf("ROTATIONS TO TOP: %d\n", count_rotations_to_top(stack_a, stack_a->head->next->next));
	// ft_printf("ROTATIONS TO TOP: %d\n", count_rotations_to_down(stack_a, stack_a->head->next->next));
	// }

	
	// { // reverse_rotate check
	// 	print_stack(stack_a, 1);
	// 	reverse_rotate_stack(stack_a);
	// 	print_stack(stack_a, 1);
	// 	rotate_stack(stack_a);
	// 	print_stack(stack_a, 1);
	// }

	// {// check pop_last
	// 	t_node *last;
	// 	last = pop_last(stack_a);
	// 	print_nodes(last, 1);
	// 	print_stack(stack_a, 1);
	// }

	// { // check reverse stack
	// print_stack(stack_a, 1);
	// rotate_stack(stack_a);
	// print_stack(stack_a, 1);
	// }

	// { // check swap
	// print_nodes(stack_a->head, 1);
	// swap_stack(stack_a);
	// print_nodes(stack_a->head, 1);
	// }


	// { // check PUSH		
	// ft_printf("BEFORE\n");
	// ft_printf("STACK A:\n");
	// print_nodes(stack_a->head, 1);
	// ft_printf("STACK B:\n");
	// print_nodes(stack_b->head, 0);

	// push_to_from(stack_b, stack_a);

	// ft_printf("AFTER\n");
	// ft_printf("STACK A:\n");
	// print_nodes(stack_a->head, 1);
	// ft_printf("STACK B:\n");
	// print_nodes(stack_b->head, 0);
	// }