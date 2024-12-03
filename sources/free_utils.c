/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:36:34 by irlozano          #+#    #+#             */
/*   Updated: 2024/09/08 19:36:35 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*head;

	while (stack->head)
	{
		head = stack->head;
		stack->head = stack->head->next;
		free(head);
		head = NULL;
		stack->s_length--;
	}
}

void	free_s_array(char **arr)
{
	size_t	i;

	i = 0;
	while (arr && arr[i])
	{
		if (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		i++;
	}
	free(arr);
	arr = NULL;
}
