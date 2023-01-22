/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 08:03:28 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/22 08:12:16 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_SWAP_H
# define LIB_PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>

# include "../libft_42/libft.h"

# define SORTED 0
# define NON_NUMERIC 1
# define DUPLICATE 2
# define RANGE 3

struct s_node
{
	struct s_node	*next;
	int				index_sorted;
	int				num;
}t_node;


// push_swap.c

// parse.c
int		ft_is_all_digits(char *str);
int		get_nb_of_ints_in_1_argv(char *input);
int		get_num_of_ints(int argc, char **argv);
long	*get_long_arr_from_input(int argc, char **argv);

// check_array.c
void	argc_check(int argc);
void	array_check(long *array, int size);
int		array_is_sorted(long *array, int size);
void	range_check(long *array, int size);
void	duplicate_check(long *array, int size);

// errors.c
void	exit_with_msg(int error_index);

#endif