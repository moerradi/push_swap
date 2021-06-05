/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mosa3ada.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:07:50 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/04 16:35:28 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_env *e)
{
	swap(e->a);
	swap(e->b);
}

void	rr(t_env *e)
{
	rotate(&e->a);
	rotate(&e->b);
}

void	rrr(t_env *e)
{
	r_rotate(&e->a);
	r_rotate(&e->b);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (stack)
	{
		size = 1;
		while (stack->next)
		{
			stack = stack->next;
			size++;
		}
	}
	return (size);
}
