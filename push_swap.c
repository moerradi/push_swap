/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:01:53 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/22 06:55:02 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	e.len = argc - 1;
	e.arr = malloc(sizeof(int) * e.len);
	if (argc < 2)
	{
		free(e.arr);
		return (0);
	}
	if (!init(&e, argv))
		exiterr(&e);
	go(&e);
	if (e.a)
		free_stack(&e.a);
	if (e.b)
		free_stack(&e.b);
	if (e.arr)
		free(e.arr);
	return (0);
}
