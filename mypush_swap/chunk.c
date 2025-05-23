/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:50:02 by mdinc             #+#    #+#             */
/*   Updated: 2025/05/22 14:16:09 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_chunk_size(int size)
{
	int	chunk_size;

	if (size <= 100)
		chunk_size = size / 5;
	else if (size <= 250)
		chunk_size = size / 8;
	else if (size <= 500)
		chunk_size = size / 11;
	else
		chunk_size = size / 14;
	return (chunk_size);
}

void	push_by_chunks(t_stack **a, t_stack **b, int size)
{
	int	total_push;
	int	chunk_size;
	int	do_rotate;

	total_push = 0;
	chunk_size = ft_chunk_size(size);
	while (total_push < size && *a)
	{
		if ((*a)->index <= total_push + chunk_size)
		{
			do_rotate = ((*a)->index <= total_push);
			pb(a, b);
			if (do_rotate)
				rb(b);
			total_push++;
		}
		else
			ra(a);
	}
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
		if (current->index == goal_index)
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

void	move_all_to_a(t_stack **a, t_stack **b)
{
	int	b_size;
	int	goal_index;
	int	index_offset;

	while (*b)
	{
		b_size = get_stack_size(*b);
		goal_index = b_size - 1;
		index_offset = get_index_offset(*b, goal_index, b_size);
		if (index_offset >= 0)
		{
			while (index_offset-- > 0)
				rb(b);
		}
		else
		{
			index_offset *= -1;
			while (index_offset-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}
