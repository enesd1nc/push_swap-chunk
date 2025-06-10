/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:31:43 by mdinc             #+#    #+#             */
/*   Updated: 2025/06/10 23:22:00 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (1);
	current = stack;
	while (current->next)
	{
		if (current->element > current->next->element)
			return (0);
		current = current->next;
	}
	return (1);
}

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(int *array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
		j++;
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

static void	quick_sort_recursive(int *array, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high);
		quick_sort_recursive(array, low, pivot_index - 1);
		quick_sort_recursive(array, pivot_index + 1, high);
	}
}

void	quick_sort(int *array, int size)
{
	if (array && size > 1)
		quick_sort_recursive(array, 0, size - 1);
}
