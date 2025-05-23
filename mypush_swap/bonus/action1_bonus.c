/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:48:33 by mdinc             #+#    #+#             */
/*   Updated: 2025/05/23 18:48:35 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}

void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	*b = first->next;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*prev;

	if (!*b || !(*b)->next)
		return ;
	last = *b;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
}
