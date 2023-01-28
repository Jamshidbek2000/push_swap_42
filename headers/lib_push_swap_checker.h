/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap_checker.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:54:44 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/28 08:51:41 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_SWAP_CHECKER_H
# define LIB_PUSH_SWAP_CHECKER_H

# include <stdio.h>
# include <limits.h>

# include "../libft_42/libft.h"

# define SORTED 0
# define NON_NUMERIC 1
# define DUPLICATE 2
# define RANGE 3
# define CMD 4
# define MALLOC 5
# define ARGC 6

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

// check_array.c
int		nb_of_agrs_check(int argc);
void	array_check(long *array, int size);

// errors.c
void	exit_with_msg(int error_index);

// exec_cmd.c
int		exec_cmd(t_stack *stack_a, t_stack *stack_b, char *cmd);
int		exec_cmds(t_stack *stack_a, t_stack *stack_b);

// init_stack.c
t_stack	*get_empty_stack(void);
t_stack	*get_stack_a(long *array, int size);

// node
t_node	*get_new_node_with_num(int num);

// parse.c
int		get_num_of_ints(int argc, char **argv);
long	*get_long_arr_from_input(int argc, char **argv);

// sort_array.c
int		get_index(long *arr, int size, int num);
void	bubble_sort_array(long *array, int size);

// sort_utils.c
int		is_sorted(t_stack *stack);

// free_stack.c
void	free_stack(t_stack *stack);

// pop_stack.c
t_node	*pop_stack(t_stack *stack);
t_node	*pop_last(t_stack *stack);

// push_stack.c
void	push_to_from(t_stack *stack_1, t_stack *stack_2);
void	push_head(t_stack *stack, t_node *node);
void	push_tail(t_stack *stack, t_node *node);

// rotate_stack.c
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);
void	rotate_2_stacks(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_2_stacks(t_stack *stack_a, t_stack *stack_b);

// swap_stack.c
void	swap_stack(t_stack *stack);
void	swap_2_stacks(t_stack *stack_a, t_stack *stack_b);

#endif