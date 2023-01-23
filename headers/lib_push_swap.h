/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 08:03:28 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/23 08:04:14 by jergashe         ###   ########.fr       */
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

typedef struct s_node
{
	struct s_node	*next;
	int				index_sorted;
	int				num;
}t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}t_stack;


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

// node
t_node	*get_new_node(int num, int index_sorted);
t_node	*get_new_node_with_num(int num);
void	add_node_tail(t_node *head, t_node *node);
void	add_node_head(t_node *head, t_node *node);
t_node	*move_head_to_tail(t_node *head);
int		get_list_size(t_node *head);
void	free_stack(t_stack *stack);

// utils.c
void	print_nodes(t_node *head, int include_ind);
void	print_array(long *array, int size);

// init_stack.c
t_stack	*array_to_stack(long *array, int size);
void	set_stack_indeces(t_stack *stack_a, long *array);
t_stack	*get_stack_a(long *array, int size);

// sort_array.c
int		get_index(long *arr, int size, int num);
void	bubble_sort_array(long *array, int size);



#endif