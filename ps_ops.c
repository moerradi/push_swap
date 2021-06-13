/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:34:18 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/13 05:12:38 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char name)
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
	if (name)
	{
		ft_putstr_fd("s", 1);
		ft_putchar_fd(name, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	push(t_stack **src, t_stack **dest, int chunk, char name)
{
	t_stack	*new;

	if (*src == NULL)
		return ;
	new = new_node((*src)->n, chunk);
	add_front(dest, new);
	pop(src);
	if (name)
	{
		ft_putstr_fd("p", 1);
		ft_putchar_fd(name, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	rotate(t_stack **stack, char name)
{
	t_stack	*new;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	new = new_node(((*stack)->n), (*stack)->chunk);
	add_back(stack, new);
	pop(stack);
	if (name)
	{
		ft_putstr_fd("r", 1);
		ft_putchar_fd(name, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	r_rotate(t_stack **stack, char name)
{
	t_stack	*new;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = get_last(*stack);
	new = new_node(last->n, last->chunk);
	add_front(stack, new);
	pop_last(stack);
	if (name)
	{
		ft_putstr_fd("rr", 1);
		ft_putchar_fd(name, 1);
		ft_putstr_fd("\n", 1);
	}
}
