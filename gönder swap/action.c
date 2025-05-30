/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:49:46 by mdinc             #+#    #+#             */
/*   Updated: 2025/05/29 12:46:15 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	sa(t_stack *a)
{
	int	temp_value;

	if (!a || !a->next)
		return ;
	temp_value = a->element;
	a->element = a->next->element;
	a->next->element = temp_value;
	write(1, "sa\n", 3);
}

void	ra(t_stack **a)
{
	t_stack	*head;
	t_stack	*tail;

	if (!*a || !(*a)->next)
		return ;
	head = *a;
	*a = head->next;
	tail = *a;
	while (tail->next)
		tail = tail->next;
	tail->next = head;
	head->next = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*prev;

	if (!*a || !(*a)->next)
		return ;
	last = *a;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	write(1, "pa\n", 3);
}
