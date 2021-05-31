/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:01:53 by moerradi          #+#    #+#             */
/*   Updated: 2021/05/31 15:03:25 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exiterr(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

int	has_dup(t_env *e)
{
	int	i;
	int	j;

	i = 0;
	while (i < e->len - 1)
	{
		j = i + 1;
		while (j < e->len)
		{
			if (e->arr[i] == e->arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_stack	*new_node(int n)
{
	t_stack	*out;

	out = (t_stack *)malloc(sizeof(t_list));
	if (!out)
		return (NULL);
	out->n = n;
	out->next = NULL;
	return (out);
}


void	add_back(t_stack **alst, t_stack *new)
{
	t_stack	*current;

	if (!alst)
		return ;
	current = *alst;
	if (current)
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
	else
	{
		*alst = new;
	}
}

int	array_to_stack(t_env *e)
{
	int		i;
	t_stack	*node;

	e->a = new_node(e->arr[0]);
	i = 1;
	while (i < e->len)
	{
		node = new_node(e->arr[i++]);
		add_back(&e->a, node);
	}
	return (1);
}

int	init(t_env *e, char **argv)
{
	int	i;

	i = 1;
	while (i < e->len + 1)
	{
		if (!checknparse(argv[i], &e->arr[i - 1]))
			return (0);
		i++;
	}
	if (has_dup(e))
		return (0);
	if (!array_to_stack(e))
		return(0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	e;

	e.len = argc - 1;
	e.arr = malloc(sizeof(int) * e.len);
	if (argc < 2)
		exiterr();
	if (!init(&e, argv))
		exiterr();
	swap(e.a);
	print_stack(e.a);
	//print_arr(&e);
	//push_swap(e);
	return (0);
}