/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:04:19 by mdinc             #+#    #+#             */
/*   Updated: 2025/05/18 18:08:36 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

void	free_stack(t_stack **stack)
{
    t_stack	*temp;

    while (*stack)
    {
        temp = (*stack)->next; // Geçici olarak bir sonraki düğümü sakla
        free(*stack); // Mevcut düğümü serbest bırak
        *stack = temp; // Bir sonraki düğüme geç
    }
    *stack = NULL; // Stack'i NULL yap
}

void	fault(t_stack **a, t_stack **b)
{
	if (a && *a)
		free_stack(a);
	if (b && *b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

int	my_atoi(char *str, t_stack *stack)
{
    int					m;
    int					i;
    unsigned long int	s;

    m = 1;
    i = 0;
    s = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-')
        m *= -1;
    if ((str[i] == '-' || str[i] == '+') && !(str[++i] >= '0' && str[i] <= '9'))
        fault(&stack, NULL); // İkinci parametre olarak NULL geç
    if (str[i] == 0)
        fault(&stack, NULL); // İkinci parametre olarak NULL geç
    while (str[i])
    {
        if (str[i] > '9' || str[i] < '0')
            fault(&stack, NULL); // İkinci parametre olarak NULL geç
        s = (str[i++] - 48) + (s * 10);
    }
    if ((s > 2147483647 && m == 1) || (s > 2147483648 && m == -1))
        fault(&stack, NULL); // İkinci parametre olarak NULL geç
    return (s * m);
}