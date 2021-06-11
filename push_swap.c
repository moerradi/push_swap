/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:01:53 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/11 15:56:32 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_env	e;

	e.len = argc - 1;
	e.arr = malloc(sizeof(int) * e.len);
	if (argc < 2)
	{
		ft_putendl_fd("here ??", 1);
		exiterr();
	}
	if (!init(&e, argv))
	{
		ft_putendl_fd("or here ??", 1);
		exiterr();
	}
	// push(&e.a, &e.b, 0);
	// push(&e.a, &e.b);
	//swap(e.a);
	// push(&e.a, &e.b, 1);
	// // rotate(&e.a);
	// //rotate(&e.b);
	// ft_putstr_fd("Stack a : ", 1);
	// print_stack(e.a);
	// //push(&e.b, &e.a);
	// ft_putstr_fd("Stack b : ", 1);
	// print_stack(e.b);
	//print_stack(e.b);
	//print_arr(&e);
	//push_swap(e);
	go(&e);
	return (0);
}