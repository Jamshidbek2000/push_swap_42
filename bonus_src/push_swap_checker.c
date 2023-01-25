/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:13:53 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/25 11:08:38 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap_checker.h"

int	exec_cmd(t_stack *stack_a, t_stack *stack_b, char *cmd)
{
	int	cmd_len;

	cmd_len = ft_strlen(cmd);
	if (ft_strncmp(cmd, "pa\n", 3) == 0 && cmd_len == 3)
		push_to_from(stack_a, stack_b);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0 && cmd_len == 3)
		push_to_from(stack_b, stack_a);
	else if (ft_strncmp(cmd, "sa\n", 3) == 0 && cmd_len == 3)
		swap_stack(stack_a);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0 && cmd_len == 3)
		swap_stack(stack_b);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0 && cmd_len == 3)
		swap_2_stacks(stack_a, stack_b);
	else if (ft_strncmp(cmd, "ra\n", 3) == 0 && cmd_len == 3)
		rotate_stack(stack_a);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0 && cmd_len == 3)
		rotate_stack(stack_b);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0 && cmd_len == 3)
		rotate_2_stacks(stack_a, stack_b);
	else if (ft_strncmp(cmd, "rra\n", 4) == 0 && cmd_len == 4)
		reverse_rotate_stack(stack_a);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0 && cmd_len == 4)
		reverse_rotate_stack(stack_b);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0 && cmd_len == 4)
		reverse_rotate_2_stacks(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	exec_cmds(t_stack *stack_a, t_stack *stack_b)
{
	char	*cmd;

	cmd = get_next_line(0);
	if (cmd == NULL)
		return ;
	while (cmd != NULL)
	{
		exec_cmd(stack_a, stack_b, cmd);
		free(cmd);
		cmd = NULL;
		cmd = get_next_line(0);
	}
	if (cmd != NULL)
		free(cmd);
}

int	main(int argc, char **argv)
{
	long	*array;
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	argc_check(argc);
	size = get_num_of_ints(argc, argv);
	array = get_long_arr_from_input(argc, argv);
	
	array_check(array, size);
	stack_a = get_stack_a(array, size);
	stack_b = get_empty_stack();
	
	exec_cmds(stack_a, stack_b);
	
	if (is_sorted(stack_a) && stack_b->size == 0)
	{
		ft_printf("OK\n");
	}
	else
	{
		ft_printf("KO\n");
	}
	
	free(array);
	free_stack(stack_a);
	free_stack(stack_b);
	// system("leaks checker");
	return (0);
}
