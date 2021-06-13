/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 20:24:31 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/13 04:41:09 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*stack_dup(t_stack *head)
{
	t_stack	*node;

	if (!head)
		return (NULL);
	else
	{
		node = (t_stack *)malloc(sizeof(t_stack));
		node->n = head->n;
		node->chunk = head->chunk;
		node->next = stack_dup(head->next);
		return (node);
	}
}

int	keep_rotating2(t_stack **stack, int pivot, int dir, char v)
{
	int	c;
	int	size;

	size = stack_size(*stack);
	c = 0;
	while (((*stack)->n <= pivot) && c < size)
	{
		if (dir)
			rotate(stack, v);
		else
			r_rotate(stack, v);
		c++;
	}
	return (c);
}

int	keep_rotating(t_stack **stack, int pivot, int dir, char v)
{
	int	c;
	int	size;

	size = stack_size(*stack);
	c = 0;
	while (((*stack)->n >= pivot) && c < size)
	{
		if (dir)
			rotate(stack, v);
		else
			r_rotate(stack, v);
		c++;
	}
	return (c);
}

int	optimize_rot(t_stack *stack, int pivot, int dir)
{
	t_stack	*r;
	t_stack	*rr;
	int		rc;
	int		rrc;

	r = stack_dup(stack);
	rr = stack_dup(stack);
	if (!dir)
	{
		rc = keep_rotating(&r, pivot, 1, 0);
		rrc = keep_rotating(&rr, pivot, 0, 0);
	}
	else
	{
		rc = keep_rotating2(&r, pivot, 1, 0);
		rrc = keep_rotating2(&rr, pivot, 0, 0);
	}
	free_stack(&r);
	free_stack(&rr);
	return ((rc < rrc));
}

void	rev(t_stack **stack, int times, char v)
{
	int	c;

	c = 0;
	while (c < times)
	{
		r_rotate(stack, v);
		c++;
	}
}
