/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac3_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:36:57 by mdinc             #+#    #+#             */
/*   Updated: 2025/05/22 21:36:57 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

// rrr fonksiyonu - rra ve rrb komutlarını aynı anda uygular
void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}

// rr fonksiyonu - ra ve rb komutlarını aynı anda uygular
void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
// ss fonksiyonu - sa ve sb komutlarını aynı anda uygular
void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

// sb fonksiyonu - b stack'indeki ilk iki elemanı değiştirir
void	sb(t_stack *b)
{
	int	temp_value;

	if (!b || !b->next)
		return ;
	temp_value = b->value;
	b->value = b->next->value;
	b->next->value = temp_value;
}
