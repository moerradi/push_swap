/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:34:18 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/08 21:11:13 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_stack *stack)
{
	t_stack	*temp;
	int		n;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack;
	temp = temp->next;
	n = temp->n;
	temp->n = stack->n;
	stack->n = n;
	n = temp->chunk;
	temp->chunk = stack->chunk;
	stack->chunk = n;
}

void	push(t_stack **src, t_stack **dest, int chunk)
{
	t_stack	*new;

	if (*src == NULL)
		return ;
	new = new_node((*src)->n, chunk);
	if (!new)
		exiterr();
	add_front(dest, new);
	pop(src);
}

void	rotate(t_stack **stack)
{
	t_stack	*new;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	new = new_node(((*stack)->n), (*stack)->chunk);
	if (!new)
		exiterr();
	add_back(stack, new);
	pop(stack);
}

void	r_rotate(t_stack **stack)
{
	t_stack	*new;
	t_stack *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = get_last(*stack);
	new = new_node(last->n, last->chunk);
	add_front(stack, new);
	pop_last(stack);
}