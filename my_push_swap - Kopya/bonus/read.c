/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:45:07 by mdinc             #+#    #+#             */
/*   Updated: 2025/05/28 18:01:21 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "checker.h"
#include "get_next_line/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

int	apply_operation(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strncmp(op, "sa", 10))
		sa(*a);
	else if (!ft_strncmp(op, "sb", 10))
		sb(*b);
	else if (!ft_strncmp(op, "ss", 10))
		ss(*a, *b);
	else if (!ft_strncmp(op, "pa", 10))
		pa(a, b);
	else if (!ft_strncmp(op, "pb", 10))
		pb(a, b);
	else if (!ft_strncmp(op, "ra", 10))
		ra(a);
	else if (!ft_strncmp(op, "rb", 10))
		rb(b);
	else if (!ft_strncmp(op, "rr", 10))
		rr(a, b);
	else if (!ft_strncmp(op, "rra", 10))
		rra(a);
	else if (!ft_strncmp(op, "rrb", 10))
		rrb(b);
	else if (!ft_strncmp(op, "rrr", 10))
		rrr(a, b);
	else
		return (0);
	return (1);
}

void	read_stdin(t_stack **stack_a, t_stack **stack_b, char *line)
{
	line = get_next_line(0);
	while (line != NULL)
	{
		if (line[0] == '\0' || (line[0] == '\n' && line[1] == '\0'))
		{
			free(line);
			write(2, "Error\n", 6);
			destroy_stack(stack_a);
			destroy_stack(stack_b);
			exit(1);
		}
		if (line[ft_strlen_gnl(line) - 1] == '\n')
			line[ft_strlen_gnl(line) - 1] = '\0';
		if (!apply_operation(stack_a, stack_b, line))
		{
			free(line);
			write(2, "Error\n", 6);
			destroy_stack(stack_a);
			destroy_stack(stack_b);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
}
