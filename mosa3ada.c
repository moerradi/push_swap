/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mosa3ada.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:07:50 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/11 15:36:15 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_env *e)
{
	swap(e->a, 0);
	swap(e->b, 0);
}

void	rr(t_env *e)
{
	rotate(&e->a, 0);
	rotate(&e->b, 0);
}

void	rrr(t_env *e)
{
	r_rotate(&e->a, 0);
	r_rotate(&e->b, 0);
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

void swap_val(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
