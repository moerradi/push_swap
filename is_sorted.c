/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 06:37:53 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/13 00:33:14 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack, bool order)
{
	if (stack == NULL || stack->next == NULL)
		return (1);
	if (!order)
		return ((stack->n < stack->next->n) && is_sorted(stack->next, order));
	else
		return ((stack->n > stack->next->n) && is_sorted(stack->next, order));
}

bool	chunk_is_sorted(t_stack *stack, int chunk, bool order)
{
	t_stack	*temp;

	temp = stack;
	if (stack == NULL)
		return (true);
	while (temp->next && temp->next->chunk == chunk)
	{
		if (!order)
		{
			if (temp->n > temp->next->n)
				return (false);
		}
		else
		{
			if (temp->n < temp->next->n)
				return (false);
		}
		temp = temp->next;
	}
	return (true);
}
