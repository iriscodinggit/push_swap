/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_algorithmss.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:40:43 by irlozano          #+#    #+#             */
/*   Updated: 2024/09/08 19:40:45 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include <stdio.h>

int	single_rot_3(t_stack *stack)
{
	int	head;
	int	body;
	int	tail;

	head = stack->head->number;
	body = stack->head->next->number;
	tail = stack->head->next->next->number;
	if (body < tail && head > tail)
		return (1);
	if (tail < head && head < body)
		return (1);
	return (0);
}

void	sort_3(t_stack *stack, int length, int ori_len)
{
	int		min_s_index;
	int		r;

	min_s_index = 0;
	if (ori_len > 3)
		min_s_index = ori_len - 3;
	if (check_order(stack))
		return ;
	r = rot_count(stack->head, min_s_index);
	if (!single_rot_3(stack))
	{
		swap(stack, 'a');
		if (check_order(stack))
			return ;
	}
	if (r < length - r)
		rotate(stack, NULL, 'a');
	else
		rev_rotate(stack, 'a');
}

void	sort_4_7(t_stack *stack_a, t_stack *stack_b, int val_arg)
{
	int	min_index;
	int	pushed_num;
	int	ori_length;
	int	rrot_num;

	min_index = 0;
	pushed_num = 0;
	ori_length = val_arg;
	while (pushed_num++ < ori_length - 3)
	{
		rrot_num = ori_length - min_index - rot_count(stack_a->head, min_index);
		if (rot_count(stack_a->head, min_index) <= rrot_num)
			while (stack_a->head->key != min_index)
				rotate(stack_a, NULL, 'a');
		else
			while (stack_a->head->key != min_index)
				rev_rotate(stack_a, 'a');
		push(stack_b, stack_a, 'b');
		val_arg--;
		min_index++;
	}
	sort_3(stack_a, val_arg, ori_length);
	pushed_num = 0;
	while (pushed_num++ < ori_length - 3)
		push(stack_a, stack_b, 'a');
}

void	k_sort1(t_stack *stack_a, t_stack *stack_b, int val_arg)
{
	int	pushed_b;
	int	funnel;

	pushed_b = 0;
	funnel = ft_sqrt(val_arg) * 12 / 10;
	while (stack_a->head)
	{
		if (stack_a->head->key <= pushed_b)
		{
			push(stack_b, stack_a, 'b');
			pushed_b++;
		}
		else if (stack_a->head->key <= pushed_b + funnel)
		{
			push(stack_b, stack_a, 'b');
			pushed_b++;
			if (!(stack_a->head->key <= pushed_b + funnel))
				rotate(stack_a, stack_b, '2');
			else
				rotate(stack_b, NULL, 'b');
		}
		else
			rotate(stack_a, NULL, 'a');
	}
}

void	k_sort2(t_stack *stack_a, t_stack *stack_b, int val_arg)
{
	int	rb_count;
	int	rrb_count;

	while (val_arg - 1 >= 0)
	{
		rb_count = rot_count(stack_b->head, val_arg - 1);
		rrb_count = val_arg - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_b->head->key != val_arg - 1)
				rotate(stack_b, NULL, 'b');
			push(stack_a, stack_b, 'a');
			val_arg--;
		}
		else
		{
			while (stack_b->head->key != val_arg - 1)
				rev_rotate(stack_b, 'b');
			push(stack_a, stack_b, 'a');
			val_arg--;
		}
	}
}
