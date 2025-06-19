/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:48:53 by mdinc             #+#    #+#             */
/*   Updated: 2025/06/13 21:16:21 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	sb(t_stack *b)
{
	int	temp_value;

	if (!b || !b->next)
		return ;
	temp_value = b->element;
	b->element = b->next->element;
	b->next->element = temp_value;
}
