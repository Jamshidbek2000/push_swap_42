/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:03:08 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/25 10:05:04 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap_checker.h"

void	bubble_sort_array(long *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1) 
	{
		int j = 0;
		while (j < size - i - 1) 
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;	
			}
			j++;
		}
		i++;
	}
}

int	get_index(long *arr, int size, int num)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (arr[index] == num)
			return (index);
		index++;
	}
	return (-1);
}