/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:13:53 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/28 08:42:21 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap_checker.h"

int	main(int argc, char **argv)
{
	long	*array;
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	nb_of_agrs_check(argc);
	size = get_num_of_ints(argc, argv);
	array = get_long_arr_from_input(argc, argv);
	array_check(array, size);
	stack_a = get_stack_a(array, size);
	free(array);
	stack_b = get_empty_stack();
	if (exec_cmds(stack_a, stack_b) == -1)
		ft_putstr_fd("Error\n", 2);
	else
	{
		if (is_sorted(stack_a) && stack_b->size == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
