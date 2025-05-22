/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:11:13 by mdinc             #+#    #+#             */
/*   Updated: 2025/05/22 19:05:51 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

void				fault(t_stack **a, t_stack **b);
int					my_atoi(char *str, t_stack *stack);
void				exit_if_sorted(t_stack **stack_a);
void				sa(t_stack *a);
void				ra(t_stack **a);
void				rra(t_stack **a);
void				start_process(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				rb(t_stack **b);
void				rrb(t_stack **b);
void				free_stack(t_stack **stack);
void				push_by_chunks(t_stack **a, t_stack **b, int size);
int					get_stack_size(t_stack *stack);
void				move_all_to_a(t_stack **a, t_stack **b);
int					*create_value_array(t_stack *stack, int size);
void				bubble_sort(int *array, int size);
int					get_stack_size(t_stack *stack);
void				non_numeric(char **av);
void				empty_argument(char **av);
void				add_to_stack(t_stack **stack, int value);

#endif