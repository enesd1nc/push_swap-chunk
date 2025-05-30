/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:50:02 by mdinc             #+#    #+#             */
/*   Updated: 2025/05/29 13:11:26 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_all_to_a(t_stack **a, t_stack **b);

void	push_by_chunks(t_stack **stack_a, t_stack **stack_b, int lenght)
{
	t_data	data;

	new_value(*stack_a, lenght, 0, 0);
	data.total_push = 0;
	data.chunk_size = ft_chunk_size(lenght);
	while (data.total_push < lenght && *stack_a)
	{
		if ((*stack_a)->element <= data.total_push + data.chunk_size)
		{
			data.do_rotate = ((*stack_a)->element <= data.total_push);
			pb(stack_a, stack_b);
			if (data.do_rotate)
				rb(stack_b);
			data.total_push++;
		}
		else
			ra(stack_a);
	}
	move_all_to_a(stack_a, stack_b);
}

static int	get_index_offset(t_stack *stack, int goal_index, int stack_size)
{
	t_stack	*current;
	int		forward_pos;
	int		backward_pos;

	if (!stack)
		return (-1);
	current = stack;
	forward_pos = 0;
	while (current)
	{
		if (current->element == goal_index)
			break ;
		forward_pos++;
		current = current->next;
		if (forward_pos >= stack_size)
			return (-1);
	}
	backward_pos = stack_size - forward_pos;
	if (forward_pos <= backward_pos)
		return (forward_pos);
	else
		return (-backward_pos);
}

static void	rotate_stack_to_position(t_stack **stack, int offset)
{
	int	i;
	int	abs_offset;

	i = 0;
	if (offset > 0)
	{
		while (i < offset)
		{
			rb(stack);
			i++;
		}
	}
	else if (offset < 0)
	{
		abs_offset = -offset;
		i = 0;
		while (i < abs_offset)
		{
			rrb(stack);
			i++;
		}
	}
}

static int	find_max_element_position(t_stack *stack, int stack_size)
{
	int	max_index;
	int	position;

	max_index = stack_size - 1;
	position = get_index_offset(stack, max_index, stack_size);
	return (position);
}

static void	move_all_to_a(t_stack **a, t_stack **b)
{
	int	remaining_elements;
	int	position;

	if (!b || !*b)
		return ;
	remaining_elements = stack_length(*b);
	while (remaining_elements > 0)
	{
		position = find_max_element_position(*b, remaining_elements);
		rotate_stack_to_position(b, position);
		pa(a, b);
		remaining_elements--;
	}
}
