#include "push_swap.h"

int	ft_chunk_size(int size)
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

void	sort_large_stack(t_stack **a, t_stack **b, int size)
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

int	find_index_position(t_stack *stack, int target_index, int stack_size)
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
        if (current->index == target_index)
            break;
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
        target_pos = find_index_position(*b, target_index, b_size);
        if (target_pos >= 0)
        {
            moves = target_pos;
            while (moves-- > 0)
                rb(b);
        }
        else
        {
            moves = -target_pos;
            while (moves-- > 0)
                rrb(b);
        }
        pa(a, b);
    }
}
