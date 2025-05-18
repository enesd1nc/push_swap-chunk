#include "push_swap.h"

void    start_process(t_stack **a, t_stack **b)
{
    int	size;

	size = get_stack_size(*a);
	if (is_sorted(*a) || size <= 1)
		return ;
	assign_indices(*a);
	if (size <= 5)
		sort_small_stack(a, b);
	else
	{
		sort_large_stack(a, b);
		push_back_to_a(a, b);
	}
}