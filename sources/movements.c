/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:37:39 by irlozano          #+#    #+#             */
/*   Updated: 2024/09/08 19:37:41 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include <unistd.h>

void	swap(t_stack *stack, char stack_name)
{
	t_node	*ori_first;

	if (!(stack->head) || !(stack->head->next))
		return ;
	ori_first = stack->head;
	stack->head = ori_first->next;
	ori_first->next = stack->head->next;
	stack->head->next = ori_first;
	if (stack_name == 'a')
		write(1, "sa\n", 3);
	else if (stack_name == 'b')
		write(1, "sb\n", 3);
}

void	push(t_stack *stack1, t_stack *stack2, char stack_name)
{
	int	key;

	if (!(stack2->head))
		return ;
	key = stack2->head->key;
	push_init(stack1, key, pop(stack2));
	if (stack_name == 'a')
		write(1, "pa\n", 3);
	else if (stack_name == 'b')
		write(1, "pb\n", 3);
}

void	rotate(t_stack *stack, t_stack *stack_b, char stack_name)
{
	t_node	*ori_first;
	t_node	*current_node;

	if (!(stack->head) || !(stack->head->next) || !stack)
		return ;
	ori_first = stack->head;
	stack->head = ori_first->next;
	current_node = stack->head;
	while (current_node->next)
		current_node = current_node->next;
	current_node->next = ori_first;
	ori_first->next = NULL;
	if (stack_name == 'a')
		write(1, "ra\n", 3);
	else if (stack_name == 'b')
		write(1, "rb\n", 3);
	else if (stack_name == '2')
	{
		rotate(stack_b, NULL, '0');
		write(1, "rr\n", 3);
	}
}

void	rev_rotate(t_stack *stack, char stack_name)
{
	t_node	*current_node;
	t_node	*last_node;

	if (!stack->head || !stack->head->next || !stack)
		return ;
	current_node = stack->head;
	while (current_node->next->next)
		current_node = current_node->next;
	last_node = current_node->next;
	current_node->next = NULL;
	last_node->next = stack->head;
	stack->head = last_node;
	if (stack_name == 'a')
		write(1, "rra\n", 4);
	else if (stack_name == 'b')
		write(1, "rrb\n", 4);
}
