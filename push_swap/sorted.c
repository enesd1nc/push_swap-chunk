/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:31:43 by mdinc             #+#    #+#             */
/*   Updated: 2025/06/19 18:19:56 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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

void	rank_array(int *array, int size, t_stack *stack)
{
	int	*original_array;
	int	i;
	int	j;
	int	rank;

	original_array = malloc(sizeof(int) * size);
	if (!original_array)
		fault(&stack, NULL);
	i = -1;
	while (++i < size)
		original_array[i] = array[i];
	i = 0;
	while (i < size)
	{
		rank = 0;
		j = -1;
		while (++j < size)
		{
			if (original_array[j] < original_array[i])
				rank++;
		}
		array[i] = rank;
		i++;
	}
	free(original_array);
}
