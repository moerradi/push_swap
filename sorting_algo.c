/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:03:21 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/09 21:16:29 by moerradi         ###   ########.fr       */
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
		if (stack->chunk == chunk)
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

int	keep_rotating(t_stack **stack, int pivot, int chunk, int dir, bool v)
{
	int	c;
	int	size;

	size = stack_size(*stack);
	c = 0;

	while ((*stack)->n >= pivot && c < size)
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

int	rotate_optimizer(t_stack *stack, int chunk, int pivot)
{
	t_stack	*r;
	t_stack	*rr;
	int		rc;
	int		rrc;
	int		i;

	i = 0;
	r = stack_dup(stack);
	rr = stack_dup(stack);
	rc = keep_rotating(&r, pivot, chunk, 1, false);
	rrc = keep_rotating(&rr, pivot, chunk, 0, false);
	//free stacks
	return ((rc > rrc));
}

bool	still(t_stack *stack, int pivot)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->n < pivot)
			return (true);
		temp = temp->next;
	}
	return (false);
}

void	sort_3(t_stack **stack, bool order)
{

	if (!order)
	{
		if ((*stack)->next->n < (*stack)->n)
			swap(*stack);
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
		if ((*stack)->next->next->n > (*stack)->next->n)
		{
			r_rotate(stack);
			if ((*stack)->next->n > (*stack)->n)
				swap(*stack);
		}	
	}
}

void	go(t_env *e)
{
	int		pivot;
	t_stack *temp;
	int		chunk;
	int		rn;

	rn = 0;
	temp = e->a;
	chunk = 1;
	while (stack_size(e->a) > 3)
	{
		pivot = get_pivot(e->a, 0);
		ft_putnbr_fd(pivot, 1);
		while (still(e->a, pivot))
		{
			keep_rotating(&e->a, pivot, 0, rotate_optimizer(e->a, 0, pivot), true);
			push(&e->a, &e->b, chunk);	ft_putstr_fd("\n stack a :", 1);
			print_stack(e->a);
			ft_putstr_fd("\n stack b :", 1);
			print_stack(e->b);
		}
		chunk++;
	}
	chunk--;
	sort_3(&e->a, 0);
	// while (stack_size(e->b) > 3)
	// {
	// 	pivot = get_pivot(e->b, chunk);
	// 	while (still(e->a, pivot))
	// 	{
	// 		if ()
	// 		rn += keep_rotating(&e->a, chunk, pivot, 1, true);
	// 		push(&e->b, &e->a, chunk);
	// 	}
	// 	chunk--;
	// }
	//ft_putnbr_fd(pivot, 1);
	// ft_putstr_fd("\n stack a :", 1);
	// print_stack(e->a);
	// ft_putstr_fd("\n stack b :", 1);
	// print_stack(e->b);
}