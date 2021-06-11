/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:03:21 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/11 18:33:04 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
void	sort_array(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap_val(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

int		chunk_len(t_stack *stack, int chunk)
{
	t_stack	*temp;
	int		len;

	temp = stack;
	len = 0;
	while(temp)
	{
		if (temp->chunk == chunk)
			len++;
		temp = temp->next;
	}
	return (len);
}

int		*chunk_to_array(t_stack *stack, int chunk)
{
	t_stack	*temp;
	int 	*ret;
	int		i;

	temp = stack;
	ret = (int *)malloc(sizeof(int) * chunk_len(stack, chunk));
	if (!ret)
		exiterr();
	i = 0;
	while(temp)
	{
		if (temp->chunk == chunk)
			ret[i] = temp->n;
		i++;
		temp = temp->next;
	}
	return (ret);
}

int		get_pivot(t_stack *stack, int chunk)
{
	int	*arr;
	int	len;
	int	ret;

	len = chunk_len(stack, chunk);
		
	arr = chunk_to_array(stack, chunk);
	sort_array(arr, len);
	ret = arr[len / 2];
	free(arr);
	return (ret);
}

t_stack	*stack_dup(t_stack *head)
{
	t_stack* node;

	if (!head)
		return NULL;
	else
	{
		node = (t_stack *)malloc(sizeof(t_stack));
		node->n = head->n;
		node->chunk = head->chunk;
		node->next = stack_dup(head->next);
		return node;
	}
}

int	keep_rotating2(t_stack **stack, int pivot, int dir, char v)
{
	int	c;
	int	size;

	size = stack_size(*stack);
	c = 0;
	while (((*stack)->n <= pivot) && c < size)
	{
		if (dir)
			rotate(stack, v);
		else
			r_rotate(stack, v);
		c++;
	}
	return (c);
}

int	keep_rotating(t_stack **stack, int pivot, int dir, char v)
{
	int	c;
	int	size;

	size = stack_size(*stack);
	c = 0;
	while (((*stack)->n >= pivot) && c < size)
	{
		if (dir)
			rotate(stack, v);
		else
			r_rotate(stack, v);
		c++;
	}
	return (c);
}

int	rotate_optimizer(t_stack *stack, int pivot, int dir)
{
	t_stack	*r;
	t_stack	*rr;
	int		rc;
	int		rrc;
	int		i;

	i = 0;
	r = stack_dup(stack);
	rr = stack_dup(stack);
	if (!dir)
	{
		rc = keep_rotating(&r, pivot, 1, 0);
		rrc = keep_rotating(&rr, pivot, 0, 0);
	}
	else
	{
		rc = keep_rotating2(&r, pivot, 1, 0);
		rrc = keep_rotating2(&rr, pivot, 0, 0);
	}
	//free stacks
	return ((rc < rrc));
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

void	rev(t_stack **stack, int times, char v)
{
	int	c;
	
	c = 0;
	while (c < times)
	{
		r_rotate(stack, v);
		c++;
	}
}

int		keep_pushing(t_stack **src, t_stack **dest, int chunk, char v)
{
	while ((*src) && (*src)->chunk == chunk)
		push(src, dest, chunk, v);
}

bool	solo_chunk(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->chunk != temp->next->chunk)
			return (false);
		temp = temp->next;
	}
	return (true);
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
			else
			{
				pivot = get_pivot(e->a, e->a->chunk);
				while (still(e->a, e->a->chunk, pivot, 0))
				{
					if (solo_chunk(e->a))
					{
						keep_rotating(&e->a, pivot, rotate_optimizer(e->a, pivot, 0), 'a');
					}
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