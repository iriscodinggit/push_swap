/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:40:07 by irlozano          #+#    #+#             */
/*   Updated: 2024/09/08 19:40:09 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	push_init(t_stack *stack, int index, int number)
{
	t_node	*new_head;

	new_head = (t_node *)malloc(sizeof(t_node));
	if (!new_head)
		return ;
	new_head->number = number;
	new_head->key = index;
	new_head->next = stack->head;
	stack->head = new_head;
	stack->s_length++;
}

int	pop(t_stack *stack)
{
	t_node	*head;
	int		head_number;

	if (!stack->head)
		exit(1);
	head = stack->head;
	head_number = stack->head->number;
	stack->head = head->next;
	free(head);
	head = NULL;
	stack->s_length--;
	return (head_number);
}
