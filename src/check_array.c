/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:39:05 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/21 11:50:12 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap.h"

void	exit_with_msg(int error_index)
{
	ft_putstr_fd("Error\n", 1);	
	exit(error_index);
}

void	arg_check(int argc)
{
	if (argc < 2)
		exit(0);
}

void	array_is_ordered(long *array, int size)
{
	
}

void	range_check(long *array, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		// printf("INDEX EXIT: %d\n", index);
		if (array[index] < INT_MIN || array[index] > INT_MAX)
		{
			printf("EXIT(3)\n");
			exit_with_msg(RANGE);
		}
		index++;
	}	
}

void	duplicate_check(long *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
			{
				printf("EXIT(4)\n");
				exit_with_msg(DUPLICATE);
			}
			j++;
		}
		i++;
	}
}
