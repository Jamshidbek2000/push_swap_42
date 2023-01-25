/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:39:05 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/25 16:01:53 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap_checker.h"

void	argc_check(int argc)
{
	if (argc < 2)
		exit(0);
}

int	array_is_sorted(long *array, int size) // if sorted you can end here
{
	int	index;
	int	previous;

	index = 0;
	previous = array[index++];
	while (index < size)
	{
		if (previous > array[index])
		{
			return (0);
		}
		previous = array[index];
		index++;
	}
	return (1);
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
				exit_with_msg(DUPLICATE);
			}
			j++;
		}
		i++;
	}
}

void	array_check(long *array, int size)
{
	duplicate_check(array, size);
	range_check(array, size);
	array_is_sorted(array, size);
}