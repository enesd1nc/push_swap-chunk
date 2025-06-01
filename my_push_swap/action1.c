/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:50:01 by mdinc             #+#    #+#             */
/*   Updated: 2025/05/29 14:41:46 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	write(1, "pb\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*head;
	t_stack	*tail;

	if (!*b || !(*b)->next)
		return ;
	head = *b;
	*b = head->next;
	tail = *b;
	while (tail->next)
		tail = tail->next;
	tail->next = head;
	head->next = NULL;
	write(1, "rb\n", 3);
}

void	rrb(t_stack **b)
{
	t_stack	*tail;
	t_stack	*prev;

	if (!*b || !(*b)->next)
		return ;
	tail = *b;
	prev = NULL;
	while (tail->next)
	{
		prev = tail;
		tail = tail->next;
	}
	prev->next = NULL;
	tail->next = *b;
	*b = tail;
	write(1, "rrb\n", 4);
}
