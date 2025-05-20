#include "push_swap.h"

void	sort_large_stack(t_stack **a, t_stack **b, int size)
{
	int	pushed_count;
	int	chunk_size;

	pushed_count = 0;
	chunk_size = 15 + size / 25;
	while (pushed_count < size)
	{
		if (!(*a))
			break ;
		if ((*a)->index <= pushed_count)
		{
			pb(a, b);
			rb(b);
			pushed_count++;
		}
		else if ((*a)->index <= pushed_count + chunk_size)
		{
			pb(a, b);
			pushed_count++;
		}
		else
			ra(a);
	}
}

int	find_index_position(t_stack *stack, int target_index)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->index == target_index)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	b_size;
	int	target_index;
	int	target_pos;
	int	moves;

	while (*b)
	{
		b_size = get_stack_size(*b);
		target_index = b_size - 1;
		target_pos = find_index_position(*b, target_index);
		moves = 0;
		if (target_pos <= b_size / 2)
		{
			moves = target_pos;
			while (moves-- > 0)
				rb(b);
		}
		else
		{
			moves = b_size - target_pos;
			while (moves-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}