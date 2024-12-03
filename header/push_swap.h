/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:32:55 by irlozano          #+#    #+#             */
/*   Updated: 2024/09/08 19:32:58 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>

# include "../libft/includes/libft.h"

typedef struct s_node
{
	int				number;
	int				key;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	int				s_length;
}					t_stack;

int			get_key(int n, int *arr);
void		sort_ints(int number_array[], int val_arg);
void		new_stacka(t_stack *stack_a, t_stack *stack_b, int *num, int v_arg);

void		push(t_stack *stack1, t_stack *stack2, char stack_name);
void		rev_rotate(t_stack *stack, char stack_name);
void		rotate(t_stack *stack, t_stack *stack_b, char stack_name);
void		swap(t_stack *stack, char stack_name);

int			any_duplicates(int *number_array, int val_arg);
int			*arg_to_ints(int ac, char **av, int val_arg);
int			valid_chars(int ac, char **av);
int			check_characters(char *arg, int *val_arg);
void		valid_ints(char **s_numbers, int *numbers);

int			single_rot_3(t_stack *stack);
void		sort_3(t_stack *stack, int val_arg, int ori_len);
void		sort_4_7(t_stack *stack_a, t_stack *stack_b, int i);
void		k_sort1(t_stack *stack_a, t_stack *stack_b, int val_arg);
void		k_sort2(t_stack *stack_a, t_stack *stack_b, int val_arg);

int			check_order(t_stack *stack);
void		algor(t_stack *stack_a, t_stack *stack_b, int *numbers, int length);
int			rot_count(t_node *stack, int index);

void		push_init(t_stack *stack, int key, int number);
int			pop(t_stack *stack);

void		free_stack(t_stack *stack);
void		free_s_array(char **arr);

#endif
