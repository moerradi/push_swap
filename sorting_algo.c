/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:03:21 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/12 21:38:54 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_solo(t_stack **stack, bool order, char name)
{
	if (!order)
	{
		if ((*stack)->next->n < (*stack)->n)
			swap(*stack, name);
		if ((*stack)->next->next->n < (*stack)->next->n)
		{
			r_rotate(stack, name);
			if ((*stack)->next->n < (*stack)->n)
				swap(*stack, name);
		}	
	}
	else
	{
		if ((*stack)->next->n > (*stack)->n)
			swap(*stack, name);
		if ((*stack)->next->next->n > (*stack)->next->n)
		{
			r_rotate(stack, name);
			if ((*stack)->next->n > (*stack)->n)
				swap(*stack, name);
		}	
	}
}

void	sort_3_multi(t_stack **stack, bool order, char name)
{
	if (!order)
	{
		if ((*stack)->next->n < (*stack)->n)
			swap(*stack, name);
		if ((*stack)->next->next->n < (*stack)->next->n)
		{
			rotate(stack, name);
			swap(*stack, name);
			r_rotate(stack, name);
			if ((*stack)->next->n < (*stack)->n)
				swap(*stack, name);
		}
	}
	else
	{
		if ((*stack)->next->n > (*stack)->n)
			swap(*stack, name);
		if ((*stack)->next->next->n > (*stack)->next->n)
		{
			rotate(stack, name);
			swap(*stack, name);
			r_rotate(stack, name);
			if ((*stack)->next->n > (*stack)->n)
				swap(*stack, name);
		}
	}
}

void	sort_3(t_stack **stack, bool order, char name)
{
	if (solo_chunk(*stack))
		sort_3_solo(stack, order, name);
	else
		sort_3_multi(stack, order, name);
}
 
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

void	go(t_env *e)
{
	int		pivot;
	int		chunk;
	int		rn;

	chunk = 1;
	while (!is_sorted(e->a, 0) || stack_size(e->a) != e->len)
	{
		rn = 0;
		// ft_putstr_fd("\n stack a :", 1);
		// print_stack(e->a);
		// ft_putstr_fd("\n stack b :", 1);
		// print_stack(e->b);
		if (!chunk_is_sorted(e->a, e->a->chunk, 0))
		{
			if (chunk_len(e->a, e->a->chunk) == 2)
				swap(e->a, 'a');
			else if (chunk_len(e->a, e->a->chunk) == 3)
			{
				// ft_putendl_fd("SPECIAIDAOISDIAOSASD", 1);
				sort_3(&e->a, 0, 'a');
			}
			else
			{
				pivot = get_pivot(e->a, e->a->chunk);
				while (still(e->a, e->a->chunk, pivot, 0))
				{
					if (solo_chunk(e->a))
						keep_rotating(&e->a, pivot, rotate_optimizer(e->a, pivot, 0), 'a');
					else
						rn += keep_rotating(&e->a, pivot, 1, 'a');
					push(&e->a, &e->b, chunk, 'b');
				}
				rev(&e->a, rn, 'a');
				chunk++;
			}
		}
		else
		{
			if (chunk_is_sorted(e->b, e->b->chunk, 1))
				keep_pushing(&e->b, &e->a, e->b->chunk, 'a');
			else if (chunk_len(e->b, e->b->chunk) == 2)
			{
				swap(e->b, 'b');
				keep_pushing(&e->b, &e->a, e->b->chunk, 'a');
			}
			else if (chunk_len(e->b, e->b->chunk) == 3)
			{
				sort_3(&e->b, 1, 'b');
				// ft_putendl_fd("SPECIAIDAOISDIAOSASD", 1);
				keep_pushing(&e->b, &e->a, e->b->chunk, 'a');
			}
			else
			{
				pivot = get_pivot(e->b, e->b->chunk);
				while (still(e->b, e->b->chunk, pivot, 1))
				{
					if (solo_chunk(e->b))
						keep_rotating2(&e->b, pivot, rotate_optimizer(e->b, pivot, 1), 'b');
					else
						rn += keep_rotating2(&e->b, pivot, 1, 'b');
					push(&e->b, &e->a, chunk, 'a');
				}
				rev(&e->b, rn, 'b');
				chunk++;
			}
		}
	}
	// ft_putnbr_fd(pivot, 1);
	// ft_putstr_fd("\n stack a :", 1);
	// print_stack(e->a);
	// ft_putstr_fd("\n stack b :", 1);
	// print_stack(e->b);
}