/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 02:59:06 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/13 05:10:39 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rsr(t_stack **stack, char name)
{
	rotate(stack, name);
	swap(*stack, name);
	r_rotate(stack, name);
}

static void	sort_3_solo(t_stack **stack, bool order, char name)
{
	if (!order)
	{
		if ((*stack)->next->n < (*stack)->n)
			swap(*stack, name);
		if ((*stack)->next->next->n < (*stack)->next->n)
		{
			r_rotate(stack, name);
			if ((*stack)->next->n < (*stack)->n)
				swap(*stack, name);
		}	
	}
	else
	{
		if ((*stack)->next->n > (*stack)->n)
			swap(*stack, name);
		if ((*stack)->next->next->n > (*stack)->next->n)
		{
			r_rotate(stack, name);
			if ((*stack)->next->n > (*stack)->n)
				swap(*stack, name);
		}	
	}
}

static void	sort_3_multi(t_stack **stack, bool order, char name)
{
	if (!order)
	{
		if ((*stack)->next->n < (*stack)->n)
			swap(*stack, name);
		if ((*stack)->next->next->n < (*stack)->next->n)
		{
			rsr(stack, name);
			if ((*stack)->next->n < (*stack)->n)
				swap(*stack, name);
		}
	}
	else
	{
		if ((*stack)->next->n > (*stack)->n)
			swap(*stack, name);
		if ((*stack)->next->next->n > (*stack)->next->n)
		{
			rsr(stack, name);
			if ((*stack)->next->n > (*stack)->n)
				swap(*stack, name);
		}
	}
}

void	sort_rest(t_stack **stack, int len, bool order, char name)
{
	if (len == 2)
	{
		swap(*stack, name);
		return ;
	}
	if (solo_chunk(*stack))
		sort_3_solo(stack, order, name);
	else
		sort_3_multi(stack, order, name);
}
