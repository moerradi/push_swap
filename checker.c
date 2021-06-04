/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:08:05 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/04 13:25:36 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	
}

void	ops_router(t_env *e, char *line)
{
	if (!ft_strcmp(line,"sa"))
		swap(e->a);
	else if (!ft_strcmp(line, "sb"))
		swap(e->b);
	else if (!ft_strcmp(line, "ss"))
		ss(e);
	else if (!ft_strcmp(line, "pa"))
		push(&e->a, &e->b);
	else if (!ft_strcmp(line, "pb"))
		push(&e->b, &e->a);
	else if (!ft_strcmp(line, "ra"))
		rotate(&e->a);
	else if (!ft_strcmp(line, "rb"))
		rotate(&e->b);
	else if (!ft_strcmp(line, "rr"))
		rr(e);
	else if (!ft_strcmp(line, "rra"))
		r_rotate(&e->a);
	else if (!ft_strcmp(line, "rrb"))
		r_rotate(&e->b);
	else if (!ft_strcmp(line, "rrr"))
		rrr(e);
	else
		exiterr();
}

int main(int argc, char **argv)
{
	t_env e;
	char *line;

	e.len = argc - 1;
	e.arr = malloc(sizeof(int) * e.len);
	if (argc < 2)
		exiterr();
	if (!init(&e, argv))
		exiterr();
	while (get_next_line(1, &line) > 0)
	{
		ops_router(&e, &line);
	}
	if (is_sorted(e->a))
	{
		
	}
	else
	{
		
	}
}