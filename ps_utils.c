/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:33:14 by moerradi          #+#    #+#             */
/*   Updated: 2021/05/31 21:09:42 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

void	pop_last(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;
	
	if (*stack == NULL)
		return ;
	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	free(last);
}

int	get_last(t_stack *stack)
{
	if (!stack)
		exiterr();
	while (stack->next)
		stack = stack->next;
	return (stack->n);
}

void	add_front(t_stack **stack, t_stack *new)
{
	if (!stack)
		return ;
	if ((*stack) == NULL)
	{
		*stack = new;
		return ;
	}
	if (stack && new)
	{
		new->next = *stack;
		*stack = new;
	}
}

void	add_back(t_stack **stack, t_stack *new)
{
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	if (current)
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
	else
		*stack = new;
}