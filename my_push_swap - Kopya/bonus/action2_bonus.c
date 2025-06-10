/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:48:53 by mdinc             #+#    #+#             */
/*   Updated: 2025/06/10 23:27:10 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
