/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:38:04 by mdinc             #+#    #+#             */
/*   Updated: 2025/06/10 13:37:09 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static t_stack	*new_stack_node(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		fault(NULL, NULL);
	node->element = value;
	node->next = NULL;
	return (node);
}

void	add_to_stack(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*temp;

	new_node = new_stack_node(value);
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}

void	exit_if_sorted(t_stack **stack_a)
{
	if (is_sorted(*stack_a))
	{
		destroy_stack(stack_a, NULL);
		exit(0);
	}
}
