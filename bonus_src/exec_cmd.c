/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 08:54:21 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/28 08:51:12 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap_checker.h"

int	exec_cmd(t_stack *stack_a, t_stack *stack_b, char *cmd)
{
	if (ft_strncmp(cmd, "pa", 2) == 0 && ft_strlen(cmd) == 2)
		push_to_from(stack_a, stack_b);
	else if (ft_strncmp(cmd, "pb", 2) == 0 && ft_strlen(cmd) == 2)
		push_to_from(stack_b, stack_a);
	else if (ft_strncmp(cmd, "sa", 2) == 0 && ft_strlen(cmd) == 2)
		swap_stack(stack_a);
	else if (ft_strncmp(cmd, "sb", 2) == 0 && ft_strlen(cmd) == 2)
		swap_stack(stack_b);
	else if (ft_strncmp(cmd, "ss", 2) == 0 && ft_strlen(cmd) == 2)
		swap_2_stacks(stack_a, stack_b);
	else if (ft_strncmp(cmd, "ra", 2) == 0 && ft_strlen(cmd) == 2)
		rotate_stack(stack_a);
	else if (ft_strncmp(cmd, "rb", 2) == 0 && ft_strlen(cmd) == 2)
		rotate_stack(stack_b);
	else if (ft_strncmp(cmd, "rr", 2) == 0 && ft_strlen(cmd) == 2)
		rotate_2_stacks(stack_a, stack_b);
	else if (ft_strncmp(cmd, "rra", 3) == 0 && ft_strlen(cmd) == 3)
		reverse_rotate_stack(stack_a);
	else if (ft_strncmp(cmd, "rrb", 3) == 0 && ft_strlen(cmd) == 3)
		reverse_rotate_stack(stack_b);
	else if (ft_strncmp(cmd, "rrr", 3) == 0 && ft_strlen(cmd) == 3)
		reverse_rotate_2_stacks(stack_a, stack_b);
	else
		return (-1);
	return (1);
}

int	exec_cmds(t_stack *stack_a, t_stack *stack_b)
{
	char	*cmd;

	while (ft_read_line(&cmd))
	{
		if (ft_strncmp(cmd, "\n", 1) == 0
			&& ft_strlen(cmd) == 1)
			break ;
		if (exec_cmd(stack_a, stack_b, cmd) == -1)
			return (free(cmd), -1);
		free(cmd);
		cmd = NULL;
	}
	free(cmd);
	return (1);
}
