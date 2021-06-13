/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:03:21 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/13 04:58:13 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	still(t_stack *stack, int chunk, int pivot, bool order)
{
	t_stack	*temp;

	temp = stack;
	while (temp && temp->chunk == chunk)
	{
		if (!order)
		{
			if (temp->n < pivot)
				return (true);
		}
		else
		{
			if (temp->n > pivot)
				return (true);
		}
		temp = temp->next;
	}
	return (false);
}

void	atob(t_env *e, int *chunk, int len)
{
	int	rn;
	int	pivot;

	rn = 0;
	if (len > 1 && len <= 3)
		sort_rest(&e->a, len, 0, 'a');
	else
	{
		pivot = get_pivot(e->a, e->a->chunk);
		while (still(e->a, e->a->chunk, pivot, 0))
		{
			if (solo_chunk(e->a))
				keep_rotating(&e->a, pivot, optimize_rot(e->a, pivot, 0), 'a');
			else
				rn += keep_rotating(&e->a, pivot, 1, 'a');
			push(&e->a, &e->b, *chunk, 'b');
		}
		rev(&e->a, rn, 'a');
		(*chunk)++;
	}
}

void	btoa(t_env *e, int *chunk, int len)
{
	int	rn;
	int	pivot;

	rn = 0;
	if (chunk_is_sorted(e->b, e->b->chunk, 1))
		keep_pushing(&e->b, &e->a, e->b->chunk, 'a');
	else if (len > 1 && len <= 3)
	{
		sort_rest(&e->b, len, 1, 'b');
		keep_pushing(&e->b, &e->a, e->b->chunk, 'a');
	}
	else
	{
		pivot = get_pivot(e->b, e->b->chunk);
		while (still(e->b, e->b->chunk, pivot, 1))
		{
			if (solo_chunk(e->b))
				keep_rotating2(&e->b, pivot, optimize_rot(e->b, pivot, 1), 'b');
			else
				rn += keep_rotating2(&e->b, pivot, 1, 'b');
			push(&e->b, &e->a, *chunk, 'a');
		}
		rev(&e->b, rn, 'b');
		(*chunk)++;
	}
}

void	go(t_env *e)
{
	int	chunk;
	int	len;

	chunk = 1;
	while (!is_sorted(e->a, 0) || stack_size(e->a) != e->len)
	{
		if (!chunk_is_sorted(e->a, e->a->chunk, 0))
		{
			len = chunk_len(e->a, e->a->chunk);
			atob(e, &chunk, len);
		}
		else
		{
			len = chunk_len(e->b, e->b->chunk);
			btoa(e, &chunk, len);
		}
	}
}
