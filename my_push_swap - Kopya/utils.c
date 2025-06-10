/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:04:19 by mdinc             #+#    #+#             */
/*   Updated: 2025/06/10 13:30:52 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	destroy_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (stack_a && *stack_a)
	{
		while (*stack_a)
		{
			temp = (*stack_a)->next;
			free(*stack_a);
			*stack_a = temp;
		}
		*stack_a = NULL;
	}
	if (stack_b && *stack_b)
	{
		while (*stack_b)
		{
			temp = (*stack_b)->next;
			free(*stack_b);
			*stack_b = temp;
		}
		*stack_b = NULL;
	}
}

void	fault(t_stack **a, t_stack **b)
{
	if ((a && *a) || (b && *b))
		destroy_stack(a, b);
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

void	init_stacks(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = NULL;
	*stack_b = NULL;
}

int	stack_length(t_stack *stack)
{
	t_stack	*ptr;
	int		total;

	if (!stack)
		return (0);
	total = 1;
	ptr = stack;
	while (ptr->next)
	{
		ptr = ptr->next;
		total++;
	}
	return (total);
}
