/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:31:57 by mdinc             #+#    #+#             */
/*   Updated: 2025/05/29 13:11:26 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	new_value(t_stack *stack, int size, int i, int found)
{
	t_stack	*node;
	int		*array;

	array = create_value_array(stack, size);
	if (!array)
		fault(&stack, NULL);
	bubble_sort(array, size);
	node = stack;
	while (node)
	{
		i = 0;
		found = 0;
		while (i < size && !found)
		{
			if (node->element == array[i])
			{
				node->element = i;
				found = 1;
			}
			else
				i++;
		}
		node = node->next;
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
	if (first->element > second->element && first->element > third->element)
	{
		ra(a);
	}
	else if (second->element > first->element
		&& second->element > third->element)
	{
		rra(a);
	}
	if ((*a)->element > (*a)->next->element)
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
	min_value = a->element;
	min_index = 0;
	current_index = 0;
	current = a->next;
	while (current)
	{
		current_index++;
		if (current->element < min_value)
		{
			min_value = current->element;
			min_index = current_index;
		}
		current = current->next;
	}
	return (min_index);
}

static void	sort_small(t_stack **a, t_stack **b)
{
	int	min_index;
	int	size;

	while (stack_length(*a) > 3)
	{
		min_index = find_min_index(*a);
		size = stack_length(*a);
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
	if (stack_length(*a) == 3)
		sort_three(a);
	else if (stack_length(*a) == 2 && (*a)->element > (*a)->next->element)
		sa(*a);
	while (*b)
		pa(a, b);
}

void	start_process(t_stack **stack_a, t_stack **stack_b)
{
	int	lenght;

	lenght = stack_length(*stack_a);
	if (lenght == 2)
		sa(*stack_a);
	else if (lenght == 3)
		sort_three(stack_a);
	else if (lenght <= 5)
		sort_small(stack_a, stack_b);
	else
		push_by_chunks(stack_a, stack_b, lenght);
}
