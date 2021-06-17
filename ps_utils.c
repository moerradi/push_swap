/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:33:14 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/14 17:29:20 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL)
		return ;
	temp = *stack;
	*stack = temp->next;
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

t_stack	*get_last(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (!stack)
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return (temp);
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
