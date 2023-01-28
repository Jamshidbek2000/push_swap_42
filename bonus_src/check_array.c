/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:39:05 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/27 08:53:50 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap_checker.h"

int	nb_of_agrs_check(int argc)
{
	if (argc < 2)
		exit(ARGC);
	return (1);
}

int	array_is_sorted(long *array, int size)
{
	int	index;
	int	previous;

	index = 0;
	previous = array[index++];
	while (index < size)
	{
		if (previous > array[index])
			return (0);
		previous = array[index];
		index++;
	}
	free(array);
	exit(SORTED);
}

void	correct_range_check(long *array, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (array[index] < INT_MIN || array[index] > INT_MAX)
		{
			free(array);
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
				free(array);
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
	correct_range_check(array, size);
	array_is_sorted(array, size);
}
