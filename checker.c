/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:08:05 by moerradi          #+#    #+#             */
/*   Updated: 2021/05/31 23:17:43 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_sorted(t_stack stack)
{
	
}

void	ops_router()
{
	
}

int main(int argc, char **argv)
{
	t_env e;

	e.len = argc - 1;
	e.arr = malloc(sizeof(int) * e.len);
	if (argc < 2)
		exiterr();
	if (!init(&e, argv))
		exiterr();
	while ()
}