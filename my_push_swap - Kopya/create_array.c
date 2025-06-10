/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:31:56 by mdinc             #+#    #+#             */
/*   Updated: 2025/06/10 13:31:56 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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
		array[i++] = current->element;
		current = current->next;
	}
	return (array);
}
