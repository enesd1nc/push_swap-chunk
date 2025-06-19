/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:04:36 by mdinc             #+#    #+#             */
/*   Updated: 2025/06/13 21:16:21 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
