/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:43:59 by mdinc             #+#    #+#             */
/*   Updated: 2025/06/10 23:21:16 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "checker.h"
#include <stdlib.h>

static char	*my_split(char *str, const char *separators)
{
	static char	*next;
	char		*token;

	if (str)
		next = str;
	if (!next || *next == '\0')
		return (NULL);
	while (*next && ft_strchr(separators, *next))
		next++;
	if (*next == '\0')
		return (NULL);
	token = next;
	while (*next && !ft_strchr(separators, *next))
		next++;
	if (*next)
	{
		*next = '\0';
		next++;
	}
	return (token);
}

static void	argument(int ac, char *av[], t_stack **stack_a)
{
	char	*start;
	char	*token;
	int		nbr;
	int		i;

	i = 1;
	while (i < ac)
	{
		start = av[i];
		token = my_split(start, " ");
		while (token)
		{
			nbr = my_atoi(token, *stack_a);
			add_to_stack(stack_a, nbr);
			token = my_split(NULL, " ");
		}
		i++;
	}
}

static void	check_argument(t_stack *stack_a)
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

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	non_numeric(av);
	empty_argument(av);
	argument(ac, av, &stack_a);
	check_argument(stack_a);
	read_stdin(&stack_a, &stack_b, NULL);
	if (is_sorted(stack_a) && !stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	destroy_stack(&stack_a);
	destroy_stack(&stack_b);
}
