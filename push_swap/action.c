/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:49:46 by mdinc             #+#    #+#             */
/*   Updated: 2025/06/02 01:50:38 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	sa(t_stack *stack_a)
{
	int	temp_value;

	if (!stack_a || !stack_a->next)
		return ;
	temp_value = stack_a->element;
	stack_a->element = stack_a->next->element;
	stack_a->next->element = temp_value;
	write(1, "sa\n", 3);
}

void	ra(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*tail;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	head = *stack_a;
	*stack_a = head->next;
	tail = *stack_a;
	while (tail->next)
		tail = tail->next;
	tail->next = head;
	head->next = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*prev;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last = *stack_a;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write(1, "rra\n", 4);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	write(1, "pa\n", 3);
}
