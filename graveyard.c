/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graveyard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:18:30 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/11 08:18:32 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

while (stack_size(e->a) > 3)
	{
		pivot = get_pivot(e->a, 0);
		// ft_putnbr_fd(pivot, 1);
		while (still(e->a, pivot))
		{
			keep_rotating(&e->a, pivot, rotate_optimizer(e->a, 0, pivot), true);
			push(&e->a, &e->b, chunk);

		}
		chunk++;
	}
	chunk--;
	sort_rest(&e->a, 0);
	
	while (stack_size(e->b) > 3)
	{
		pivot = get_pivot(e->b, chunk);
		while (still(e->a, pivot))
		{
			// if ()
			// rn += keep_rotating(&e->a, chunk, pivot, 1, true);
			// push(&e->b, &e->a, chunk);
		}
		chunk--;
	}