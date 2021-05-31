/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:34:18 by moerradi          #+#    #+#             */
/*   Updated: 2021/05/31 20:57:16 by moerradi         ###   ########.fr       */
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
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*new;
	t_stack	*temp;

	if (*src == NULL)
		return ;
	new = new_node((*src)->n);
	add_back(dest, new);
	pop(src);
}

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*new;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	new = new_node(((*stack)->n));
	add_back(stack, new);
	pop(stack);
}

void	r_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*new;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	new = new_node(get_last(*stack));
	add_front(stack, new);
	pop_last(stack);
}