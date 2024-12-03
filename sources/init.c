/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:37:04 by irlozano          #+#    #+#             */
/*   Updated: 2024/09/08 19:37:06 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	get_key(int number, int *number_array)
{
	int	i;

	i = 0;
	while (number_array[i] != number)
		i++;
	return (i);
}

void	sort_ints(int number_array[], int val_arg)
{
	int	current_number;
	int	i;
	int	j;

	i = 1;
	while (i < val_arg)
	{
		current_number = number_array[i];
		j = i - 1;
		while (j >= 0 && number_array[j] > current_number)
		{
			number_array[j + 1] = number_array[j];
			j = j - 1;
		}
		number_array[j + 1] = current_number;
		i++;
	}
}

void	new_stacka(t_stack *stack_a, t_stack *stack_b, int *num, int v_arg)
{
	int		counter_arg;
	t_node	*current_node;

	stack_b->head = NULL;
	stack_a->head = NULL;
	stack_b->s_length = 0;
	stack_a->s_length = 0;
	counter_arg = v_arg - 1;
	while (counter_arg != -1)
	{
		push_init(stack_a, 0, num[counter_arg]);
		counter_arg--;
	}
	sort_ints(num, v_arg);
	current_node = stack_a->head;
	while (current_node)
	{
		current_node->key = get_key(current_node->number, num);
		current_node = current_node->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		val_arg;
	int		*number_array;

	if (ac == 1)
		exit(0);
	val_arg = valid_chars(ac, av);
	if (val_arg < 0)
		exit(0);
	number_array = arg_to_ints(ac, av, val_arg);
	if (val_arg <= 1 || any_duplicates(number_array, val_arg))
	{
		free(number_array);
		if (val_arg == 1)
			exit(0);
		display_error("Error\n");
	}
	new_stacka(&stack_a, &stack_b, number_array, val_arg);
	algor(&stack_a, &stack_b, number_array, val_arg);
	free(number_array);
	free_stack(&stack_a);
	return (0);
}
