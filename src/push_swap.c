/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:13:53 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/22 08:13:01 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap.h"

void	print_array(long *array, int size);

int	main(int argc, char **argv)
{
	long	*array;
	int		size;

	size = get_num_of_ints(argc, argv);
	array = get_long_arr_from_input(argc, argv);
	
	array_check(array, size);
	
	free(array);
	system("leaks push_swap");

	return (0);
}



void	print_array(long *array, int size)
{
	int		index;

	index = 0;
	while (index < size)
	{
		printf("%ld ", array[index]);
		index++;
	}
}



	// long	result;

	// result = get_num_of_ints(argc, argv);
	// printf("RESULT: %d\n", result);

	// result = ft_atol("21474836470");
	// printf("RESULT: %ld\n", result);