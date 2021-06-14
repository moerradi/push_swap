/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 12:57:09 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/13 20:19:44 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exiterr(t_env *e)
{
	write(2, "Error\n", 6);
	if (e->a)
		free_stack(&e->a);
	if (e->b)
		free_stack(&e->b);
	exit(-1);
}

static int	has_dup(t_env *e)
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

t_stack	*new_node(int n, int chunk)
{
	t_stack	*out;

	out = (t_stack *)malloc(sizeof(t_stack));
	if (!out)
		return (NULL);
	out->chunk = chunk;
	out->n = n;
	out->next = NULL;
	return (out);
}

static int	array_to_stack(t_env *e)
{
	int		i;
	t_stack	*node;

	i = 0;
	while (i < e->len)
	{
		node = new_node(e->arr[i++], 0);
		if (!node)
			return (0);
		add_back(&e->a, node);
	}
	return (1);
}

int	init(t_env *e, char **argv)
{
	int	i;

	i = 1;
	e->a = NULL;
	e->b = NULL;
	while (i < e->len + 1)
	{
		if (!checknparse(argv[i], &e->arr[i - 1]))
			return (0);
		i++;
	}
	if (has_dup(e))
		return (0);
	if (!array_to_stack(e))
		return (0);
	return (1);
}
