/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:55:50 by mdinc             #+#    #+#             */
/*   Updated: 2025/05/24 15:08:02 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "checker.h"
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
	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
		mark *= -1;
	if ((mark < 0 || str[i] == '+') && (++i, !ft_isdigit(str[i])))
		fault(&stack, NULL);
	if (!str[i])
		fault(&stack, NULL);
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			fault(&stack, NULL);
		s = (str[i++] - '0') + (s * 10);
	}
	if ((s > MY_INT_MAX && mark == 1) || (s > MY_INT_MIN && mark == -1))
		fault(&stack, NULL);
	return (s * mark);
}
