/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:04:19 by mdinc             #+#    #+#             */
/*   Updated: 2025/05/23 20:15:35 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
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
	int					mark;
	int					i;
	unsigned long int	s;

	mark = 1;
	i = 0;
	s = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		mark *= -1;
	if ((str[i] == '-' || str[i] == '+') && !(str[++i] >= '0' && str[i] <= '9'))
		fault(&stack, NULL);
	if (str[i] == 0)
		fault(&stack, NULL);
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			fault(&stack, NULL);
		s = (str[i++] - 48) + (s * 10);
	}
	if ((s > 2147483647 && mark == 1) || (s > 2147483648 && mark == -1))
		fault(&stack, NULL);
	return (s * mark);
}
