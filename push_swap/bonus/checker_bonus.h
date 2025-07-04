/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:43:04 by mdinc             #+#    #+#             */
/*   Updated: 2025/06/13 00:14:43 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# define MY_INT_MAX 2147483647
# define MY_INT_MIN 2147483648

typedef struct s_stack
{
	int				element;
	struct s_stack	*next;
}					t_stack;

void				empty_argument(char **av);
void				destroy_stack(t_stack **stack);
void				non_numeric(char **av);
void				fault(t_stack **a, t_stack **b);
int					my_atoi(char *str, t_stack *stack);
void				add_to_stack(t_stack **stack, int value);
void				sa(t_stack *a);
void				ra(t_stack **a);
void				rra(t_stack **a);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				rb(t_stack **b);
void				rrb(t_stack **b);
void				sb(t_stack *b);
void				rrr(t_stack **a, t_stack **b);
void				ss(t_stack *a, t_stack *b);
void				rr(t_stack **a, t_stack **b);
void				read_stdin(t_stack **stack_a, t_stack **stack_b,
						char *line);
int					is_sorted(t_stack *stack);
void				add_to_stack(t_stack **stack, int value);

#endif