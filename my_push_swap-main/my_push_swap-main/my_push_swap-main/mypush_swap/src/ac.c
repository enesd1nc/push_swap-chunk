/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:51:54 by mdinc             #+#    #+#             */
/*   Updated: 2025/05/20 13:51:54 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void sa(t_stack *a)
{
    int temp_value;
    int temp_index;
    
    if (!a || !a->next)
        return;
    
    temp_value = a->value;
    temp_index = a->index;
    
    a->value = a->next->value;
    a->index = a->next->index;
    
    a->next->value = temp_value;
    a->next->index = temp_index;
    
    write(1, "sa\n", 3);
}

void ra(t_stack **a)
{
    t_stack *first;
    t_stack *last;
    
    if (!*a || !(*a)->next)
        return;
    
    first = *a;
    *a = first->next;
    
    last = *a;
    while (last->next)
        last = last->next;
    
    last->next = first;
    first->next = NULL;
    
    write(1, "ra\n", 3);
}

void rra(t_stack **a)
{
    t_stack *last;
    t_stack *prev;
    
    if (!*a || !(*a)->next)
        return;
    
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

void pa(t_stack **a, t_stack **b)
{
    t_stack *temp;
    
    if (!*b)
        return;
    
    temp = *b;
    *b = (*b)->next;
    temp->next = *a;
    *a = temp;
    
    write(1, "pa\n", 3);
}

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
