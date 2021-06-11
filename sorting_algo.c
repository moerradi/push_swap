/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:03:21 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/11 12:21:49 by moerradi         ###   ########.fr       */
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
		if (stack->chunk == chunk)
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

int	keep_rotating2(t_stack **stack, int pivot, int dir, bool v)
{
	int	c;
	int	size;
	bool tstya;

	size = stack_size(*stack);
	c = 0;
	while (((*stack)->n <= pivot) && c < size)
	{
		if (v && dir)
			ft_putendl_fd("r", 1);
		else if (v && !dir)
			ft_putendl_fd("rr", 1);
		if (dir)
			rotate(stack);
		else
			r_rotate(stack);
		c++;
	}
	return (c);
}

int	keep_rotating(t_stack **stack, int pivot, int dir, bool v)
{
	int	c;
	int	size;
	bool tstya;

	size = stack_size(*stack);
	c = 0;
	while (((*stack)->n >= pivot) && c < size)
	{
		if (v && dir)
			ft_putendl_fd("r", 1);
		else if (v && !dir)
			ft_putendl_fd("rr", 1);
		if (dir)
			rotate(stack);
		else
			r_rotate(stack);
		c++;
	}
	return (c);
}

// int	rotate_optimizer(t_stack *stack, int chunk, int pivot)
// {
// 	t_stack	*r;
// 	t_stack	*rr;
// 	int		rc;
// 	int		rrc;
// 	int		i;

// 	i = 0;
// 	r = stack_dup(stack);
// 	rr = stack_dup(stack);
// 	rc = keep_rotating(&r, pivot, 1, false);
// 	rrc = keep_rotating(&rr, pivot, 0, false);
// 	//free stacks
// 	return ((rc < rrc));
// }

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

void	sort_rest(t_stack **stack, bool order)
{
	int	len;

	len = stack_size(*stack);
	if (!order)
	{
		if ((*stack)->next->n < (*stack)->n)
			swap(*stack);
		if (len == 2)
			return ;
		if ((*stack)->next->next->n < (*stack)->next->n)
		{
			r_rotate(stack);
			if ((*stack)->next->n < (*stack)->n)
				swap(*stack);
		}
	}
	else
	{
		if ((*stack)->next->n > (*stack)->n)
			swap(*stack);
		if (len == 2)
			return ;
		if ((*stack)->next->next->n > (*stack)->next->n)
		{
			r_rotate(stack);
			if ((*stack)->next->n > (*stack)->n)
				swap(*stack);
		}	
	}
}

void	rev(t_stack **stack, int times, bool v)
{
	int	c;
	
	c = 0;
	while (c < times)
	{
		if (v)
			ft_putendl_fd("rr", 1);
		r_rotate(stack);
		c++;
	}
}

int		keep_pushing(t_stack **src, t_stack **dest, int chunk)
{
	while ((*src) && (*src)->chunk == chunk)
		push(src, dest, chunk);
}

void	go(t_env *e)
{
	int		pivot;
	int		chunk;
	int		rn;

	chunk = 1;
	while (!is_sorted(e->a, 0) || stack_size(e->a) != e->len)
	{
		ft_putnbr_fd(chunk_is_sorted(e->a, e->a->chunk, 0), 1);
		ft_putstr_fd("\n stack a :", 1);
		print_stack(e->a);
		if (e->b)
			ft_putnbr_fd(chunk_is_sorted(e->b, e->b->chunk, 1), 1);
		ft_putstr_fd("\n stack b :", 1);
		print_stack(e->b);
		rn = 0;
		if (!chunk_is_sorted(e->a, e->a->chunk, 0))
		{
			if (chunk_len(e->a, e->a->chunk) == 2)
				swap(e->a);
			else
			{
				pivot = get_pivot(e->a, e->a->chunk);
				while (still(e->a, e->a->chunk, pivot, 0))
				{
					rn += keep_rotating(&e->a, pivot, 1, false);
					push(&e->a, &e->b, chunk);
				}
				rev(&e->a, rn, false);
				chunk++;
			}
		}
		else
		{
			if (chunk_is_sorted(e->b, e->b->chunk, 1))
				keep_pushing(&e->b, &e->a, e->b->chunk);
			else if (chunk_len(e->b, e->b->chunk) == 2)
			{
				swap(e->b);
				keep_pushing(&e->b, &e->a, e->b->chunk);
			}
			else
			{
				pivot = get_pivot(e->b, e->b->chunk);
				ft_putstr_fd("pivot : ", 1);
				ft_putnbr_fd(pivot, 1);
				ft_putstr_fd("\n", 1);
				while (still(e->b, e->b->chunk, pivot, 1))
				{
					rn += keep_rotating2(&e->b, pivot, 1, false);
					push(&e->b, &e->a, chunk);
				}
				ft_putstr_fd("rn : ", 1);
				ft_putnbr_fd(rn, 1);
				ft_putstr_fd("\n", 1);
				rev (&e->b, rn, false);
				chunk++;
			}
		}
	}
	ft_putnbr_fd(pivot, 1);
	ft_putstr_fd("\n stack a :", 1);
	print_stack(e->a);
	ft_putstr_fd("\n stack b :", 1);
	print_stack(e->b);
}