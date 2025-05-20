/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:47:30 by mdinc             #+#    #+#             */
/*   Updated: 2025/05/20 13:49:56 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void	empty_argument(char **av)
{
    int	i;

    i = 1;
    while (av[i])
    {
        if (av[i][0] == '\0')
            fault(NULL, NULL);
        i++;
    }
}

static void	non_numeric(char **av)
{
    int		i;
    int		j;
    int		flag;

    i = 1;
    flag = 0;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (av[i][j] != 32)
                flag = 1;
            j++;
        }
        if (flag == 0)
            fault(NULL, NULL);
        flag = 0;
        i++;
    }
}

static char	*my_split(char *str, const char *delim)
{
    static char	*next;
    char		*token;

    if (str)
        next = str;
    if (!next || *next == '\0')
        return (NULL);
    while (*next && strchr(delim, *next))
        next++;
    if (*next == '\0')
        return (NULL);
    token = next;
    while (*next && !strchr(delim, *next))
        next++;
    if (*next)
    {
        *next = '\0';
        next++;
    }
    return (token);
}

t_stack	*new_stack_node(int value)
{
    t_stack	*node;

    node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        fault(NULL, NULL);
    node->value = value;
    node->index = -1;
    node->next = NULL;
    return (node);
}

void	add_to_stack(t_stack **stack, int value)
{
    t_stack	*new_node;
    t_stack	*temp;

    new_node = new_stack_node(value);
    if (!*stack)
    {
        *stack = new_node;
        return ;
    }
    temp = *stack;
    while (temp->next)
        temp = temp->next;
    temp->next = new_node;
}

void	argument(int ac, char *av[], t_stack **stack_a)
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
            if (current->value == checker->value)
                fault(&stack_a, NULL);
            checker = checker->next;
        }
        current = current->next;
    }
}

int main(int ac, char *av[])
{
    t_stack	*stack_a;
    t_stack	*stack_b;

    stack_a = NULL;
    stack_b = NULL;
    non_numeric(av);
    empty_argument(av);
    argument(ac, av, &stack_a);
    check_argument(stack_a);
    exit_if_sorted(&stack_a, &stack_b);
    start_process(&stack_a, &stack_b);
    free_stack(&stack_a);
    free_stack(&stack_b);
}
