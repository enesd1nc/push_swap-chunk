/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:31:57 by mdinc             #+#    #+#             */
/*   Updated: 2025/05/22 14:14:30 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	set_indices(t_stack *stack, int size, int i)
{
	t_stack	*current;
	int		*array;

	array = create_value_array(stack, size);
	if (!array)
		fault(&stack,NULL);
	bubble_sort(array, size);
	current = stack;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == array[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	free(array);
}

static void	sort_three(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!*a || !(*a)->next || !(*a)->next->next || (*a)->next->next->next)
		return ;
	first = *a;
	second = first->next;
	third = second->next;
	if (first->value > second->value && first->value > third->value)
	{
		ra(a);
	}
	else if (second->value > first->value && second->value > third->value)
	{
		rra(a);
	}
	if ((*a)->value > (*a)->next->value)
	{
		sa(*a);
	}
}

static int	find_min_index(t_stack *a)
{
	t_stack	*current;
	int		min_value;
	int		min_index;
	int		current_index;

	if (!a)
		return (-1);
	min_value = a->value;
	min_index = 0;
	current_index = 0;
	current = a->next;
	while (current)
	{
		current_index++;
		if (current->value < min_value)
		{
			min_value = current->value;
			min_index = current_index;
		}
		current = current->next;
	}
	return (min_index);
}

static	void	sort_small(t_stack **a, t_stack **b)
{
	int	min_index;
	int	size;

	while (get_stack_size(*a) > 3)
	{
		min_index = find_min_index(*a);
		size = get_stack_size(*a);
		while (min_index > 0)
		{
			if (min_index <= size / 2)
				ra(a);
			else
				rra(a);
			min_index = find_min_index(*a);
		}
		pb(a, b);
	}
	if (get_stack_size(*a) == 3)
		sort_three(a);
	else if (get_stack_size(*a) == 2 && (*a)->value > (*a)->next->value)
		sa(*a);
	while (*b)
		pa(a, b);
}

void	start_process(t_stack **a, t_stack **b)
{
	int	size;

	size = get_stack_size(*a);
	set_indices(*a, size, 0);
	if (size == 2)
		sa(*a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_small(a, b);
	else
	{
		push_by_chunks(a, b, size);
		move_all_to_a(a, b);
	}
}
