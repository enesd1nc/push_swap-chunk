/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:11:13 by mdinc             #+#    #+#             */
/*   Updated: 2025/06/19 18:13:03 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MY_INT_MAX 2147483647
# define MY_INT_MIN 2147483648

typedef struct s_stack
{
	int				element;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	int				chunk_size;
	int				total_push;
	int				do_rotate;
}					t_data;

void				fault(t_stack **a, t_stack **b);
int					my_atoi(char *str, t_stack *stack);
void				exit_if_sorted(t_stack **stack_a);
void				sa(t_stack *a);
void				ra(t_stack **a);
void				rra(t_stack **a);
void				start_process(t_stack **stack_a, t_stack **stack_b,
						int lenght);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				rb(t_stack **b);
void				rrb(t_stack **b);
void				destroy_stack(t_stack **stack_a, t_stack **stack_b);
void				push_by_chunks(t_stack **stack_a, t_stack **stack_b,
						int lenght);
int					stack_length(t_stack *stack);
int					*create_value_array(t_stack *stack, int size);
void				rank_array(int *array, int size, t_stack *stack);
void				non_numeric(char **av);
void				empty_argument(char **av);
void				add_to_stack(t_stack **stack, int value);
int					ft_chunk_size(int size);
void				new_value(t_stack *stack, int size);
void				init_stacks(t_stack **stack_a, t_stack **stack_b);
int					is_sorted(t_stack *stack);

#endif