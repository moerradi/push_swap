/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:08:05 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/13 05:14:37 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_ops(t_env *e, char *line)
{
	if (!ft_strcmp(line, "sa"))
		swap(e->a, 0);
	else if (!ft_strcmp(line, "sb"))
		swap(e->b, 0);
	else if (!ft_strcmp(line, "ss"))
		ss(e);
	else if (!ft_strcmp(line, "pa"))
		push(&e->b, &e->a, 0, 0);
	else if (!ft_strcmp(line, "pb"))
		push(&e->a, &e->b, 0, 0);
	else if (!ft_strcmp(line, "ra"))
		rotate(&e->a, 0);
	else if (!ft_strcmp(line, "rb"))
		rotate(&e->b, 0);
	else if (!ft_strcmp(line, "rr"))
		rr(e);
	else if (!ft_strcmp(line, "rra"))
		r_rotate(&e->a, 0);
	else if (!ft_strcmp(line, "rrb"))
		r_rotate(&e->b, 0);
	else if (!ft_strcmp(line, "rrr"))
		rrr(e);
	else
		exiterr(e);
}

int	main(int argc, char **argv)
{
	t_env	e;
	char	*line;

	e.len = argc - 1;
	e.arr = malloc(sizeof(int) * e.len);
	if (argc < 2)
		exiterr(&e);
	if (!init(&e, argv))
		exiterr(&e);
	while (get_next_line(0, &line))
	{
		exec_ops(&e, line);
		free(line);
		line = NULL;
	}
	free(line);
	if (is_sorted(e.a, 0) && stack_size(e.a) == e.len)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
