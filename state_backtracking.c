/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_backtracking.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:59:20 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/17 03:29:56 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	rot_to_find(t_stack **stack, int tofind, int dir, char v)
{
	int	c;
	int	size;

	size = stack_size(*stack);
	c = 0;
	while (((*stack)->n != tofind) && c < size)
	{
		if (dir)
			rotate(stack, v);
		else
			r_rotate(stack, v);
		c++;
	}
	return (c);
}

int	rot_opt(t_stack *stack, int tofind)
{
	t_stack	*r;
	t_stack	*rr;
	int		rc;
	int		rrc;

	r = stack_dup(stack);
	rr = stack_dup(stack);
	rc = rot_to_find(&r, tofind, 1, 0);
	rrc = rot_to_find(&rr, tofind, 0, 0);
	free_stack(&r);
	free_stack(&rr);
	return ((rc < rrc));
}

int	count_ops(t_env *e)
{
	t_stack *tra;
	t_stack	*trra;
	t_stack *tb;
	int		cr;
	int		crr;

	tra = stack_dup(e->a);
	trra = stack_dup(e->a);
	tb = stack_dup(e->b);
	cr = 0;
	while (tb->n < get_last(tra)->n || tb->n > tra->n)
	{
		rotate(&tra, 0);
		cr++;
	}
	crr = 0;
	while (tb->n < get_last(trra)->n || tb->n > trra->n)
	{
		r_rotate(&trra, 0);
		crr++;
	}
	free_stack(&tra);
	free_stack(&trra);
	free_stack(&tb);
	if (cr > crr)
		return (crr);
	else
		return (cr);
}


int		kwada(t_env *e)
{
	t_stack *tb;
	int		i;
	int		len;
	int		ops;
	int		last_ops;
	int		best;
	int		rots;

	len = stack_size(e->a);
	tb = stack_dup(e->b);
	ops = INT_MAX;
	i = 0;
	rots = 0;
	while (i < len)
	{
		last_ops = count_ops(e) + rots;
		best = tb->n;
		rotate(&e->b, 0);
		rots++;
		if (ops > last_ops)
		{
			ops = last_ops;
			best = tb->n;
		}
		i++;
	}
	free_stack(&tb);
	return (best);
}

void	super_sort(t_env *e)
{
	int	max;
	int	min;
	// int	currentmoves;
	// int thismoves;
	// int	best;

	// currentmoves = 0;
	// thismoves = 0;
	sort_array(e->arr, e->len);
	max = e->arr[e->len - 1];
	min = e->arr[0];
	while (stack_size(e->a) > 2)
	{
		if (e->a->n != max && e->a->n != min)
			push(&e->a, &e->b, 0, 'b');
		else
			rotate(&e->a, 'a');
	}
	if (!is_sorted(e->a, 1))
		swap(e->a, 'a');
	push(&e->b, &e->a, 0, 'a');
	while (stack_size(e->b))
	{
		rot_to_find(&e->b, kwada(e), 0, 'b');
		while (e->b->n < get_last(e->a)->n || e->b->n > e->a->n)
			rotate(&e->a, 'a');
		push(&e->b, &e->a, 0, 'a');
	}
	while (!is_sorted(e->a, 0))
		rotate(&e->a, 'a');
	// while (stack_size(e->b))
	// {
	// 	currentmoves = calculate_moves(e);
	// }
	// print_stack(e->a);
	// ft_putendl_fd("", 1);
	// print_stack(e->b);
}