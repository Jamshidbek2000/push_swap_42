/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:13:53 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/21 11:38:19 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap.h"

int	main(int argc, char **argv)
{
	long	*array;
	int		size;
	int		index;

	
	size = get_num_of_ints(argc, argv);
	index = 0;
	array = get_long_arr_from_input(argc, argv);
	
	while (index < size)
	{
		printf("%ld ", array[index]);
		index++;
	}
	range_check(array, size);
	duplicate_check(array, size);
	printf("\nTRUE INPUT\n");
	// long	result;

	// result = get_num_of_ints(argc, argv);
	// printf("RESULT: %d\n", result);

	// result = ft_atol("21474836470");
	// printf("RESULT: %ld\n", result);

	return (0);
}
