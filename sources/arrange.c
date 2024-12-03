/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:35:47 by irlozano          #+#    #+#             */
/*   Updated: 2024/09/08 19:35:49 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	rot_count(t_node *stack, int min_index)
{
	int	rot_num;

	rot_num = 0;
	while (stack && stack->key != min_index)
	{
		stack = stack->next;
		rot_num++;
	}
	return (rot_num);
}

int	check_order(t_stack *stack)
{
	t_node	*current_node;

	current_node = stack->head;
	while (current_node->next)
	{
		if (current_node->number > current_node->next->number)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}

void	algor(t_stack *stack_a, t_stack *stack_b, int *n, int val_arg)
{
	if (check_order(stack_a))
	{
		free(n);
		free_stack(stack_a);
		exit(0);
	}
	if (val_arg == 2)
		swap(stack_a, 'a');
	else if (val_arg == 3)
		sort_3(stack_a, val_arg, -1);
	else if (val_arg <= 7)
		sort_4_7(stack_a, stack_b, val_arg);
	else
	{
		k_sort1(stack_a, stack_b, val_arg);
		k_sort2(stack_a, stack_b, val_arg);
	}
}
