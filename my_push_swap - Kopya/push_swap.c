/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:47:30 by mdinc             #+#    #+#             */
/*   Updated: 2025/06/02 00:53:23 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

static char	*my_split(char *str, const char *separators)
{
	static char	*next;
	char		*current_number;

	if (str)
		next = str;
	if (!next || *next == '\0')
		return (NULL);
	while (*next && ft_strchr(separators, *next))
		next++;
	if (*next == '\0')
		return (NULL);
	current_number = next;
	while (*next && !ft_strchr(separators, *next))
		next++;
	if (*next)
	{
		*next = '\0';
		next++;
	}
	return (current_number);
}

static void	argument(int ac, char *av[], t_stack **stack_a)
{
	char	*start;
	char	*current_number;
	int		nbr;
	int		i;

	i = 1;
	while (i < ac)
	{
		start = av[i];
		current_number = my_split(start, " ");
		while (current_number)
		{
			nbr = my_atoi(current_number, *stack_a);
			add_to_stack(stack_a, nbr);
			current_number = my_split(NULL, " ");
		}
		i++;
	}
}

void	check_argument(t_stack *stack_a)
{
	t_stack	*current;
	t_stack	*checker;

	current = stack_a;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->element == checker->element)
				fault(&stack_a, NULL);
			checker = checker->next;
		}
		current = current->next;
	}
}

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		lenght;

	init_stacks(&stack_a, &stack_b);
	non_numeric(av);
	empty_argument(av);
	argument(ac, av, &stack_a);
	check_argument(stack_a);
	exit_if_sorted(&stack_a);
	lenght = stack_length(stack_a);
	start_process(&stack_a, &stack_b, lenght);
	return (0);
}
