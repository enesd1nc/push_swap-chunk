/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:54:19 by mdinc             #+#    #+#             */
/*   Updated: 2025/05/20 13:54:57 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void pb(t_stack **a, t_stack **b)
{
    t_stack *temp;
    
    if (!*a)
        return;
    
    temp = *a;
    *a = (*a)->next;
    temp->next = *b;
    *b = temp;
    
    write(1, "pb\n", 3);
}

void rb(t_stack **b)
{
    t_stack *first;
    t_stack *last;
    
    if (!*b || !(*b)->next)
        return;
    
    first = *b;
    *b = first->next;
    
    last = *b;
    while (last->next)
        last = last->next;
    
    last->next = first;
    first->next = NULL;
    
    write(1, "rb\n", 3);
}

void rrb(t_stack **b)
{
    t_stack *last;
    t_stack *prev;
    
    if (!*b || !(*b)->next)
        return;
    
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
    
    write(1, "rrb\n", 4);
}
