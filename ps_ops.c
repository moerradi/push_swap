/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:34:18 by moerradi          #+#    #+#             */
/*   Updated: 2021/05/31 15:01:35 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_stack *stack)
{
	t_stack	*temp;
	int		n;

	temp = stack;
	temp = temp->next;
	n = temp->n;
	temp->n = stack->n;
	stack->n = n;
}