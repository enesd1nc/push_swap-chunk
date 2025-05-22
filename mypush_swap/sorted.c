/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:31:43 by mdinc             #+#    #+#             */
/*   Updated: 2025/05/22 23:14:56 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (1);
	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	exit_if_sorted(t_stack **stack_a)
{
	if (is_sorted(*stack_a))
	{	
		free_stack(stack_a);
		exit(1);
	}
}

int	get_stack_size(t_stack *stack)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = stack;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*create_value_array(t_stack *stack, int size)
{
	t_stack	*current;
	int		*array;
	int		i;

	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	current = stack;
	i = 0;
	while (current)
	{
		array[i++] = current->value;
		current = current->next;
	}
	return (array);
}
