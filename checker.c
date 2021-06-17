/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:08:05 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/17 03:39:15 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stacks(t_env *e)
{
	if (e->a)
		free_stack(&e->a);
	if (e->b)
		free_stack(&e->b);
}

static void	exec_ops(t_env *e, char *line)
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

	ft_bzero(&e, sizeof(t_env));
	e.len = argc - 1;
	e.arr = malloc(sizeof(int) * e.len);
	if (argc < 2)
		exiterr(&e);
	if (!init(&e, argv))
		exiterr(&e);
	while (get_next_line(0, &line) > 0)
	{
		ft_putendl_fd(line, 1);
		exec_ops(&e, line);
		if (line)
		{
			free(line);
			line = NULL;
		}
	}
	free(line);
	ft_putnbr_fd(stack_size(e.a), 1);
		ft_putendl_fd("", 1);

	ft_putnbr_fd(is_sorted(e.a, 0), 1);
	if (is_sorted(e.a, 0) && stack_size(e.a) == e.len)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
		// ft_putendl_fd("", 1);

	print_stack(e.a);
	ft_putendl_fd("", 1);
	print_stack(e.b);	
	free_stacks(&e);
	free(e.arr);
	return (0);
}
