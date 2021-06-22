/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 20:20:54 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/22 06:29:47 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	keep_pushing(t_stack **src, t_stack **dest, int chunk, char v)
{
	while ((*src) && (*src)->chunk == chunk)
		push(src, dest, chunk, v);
}

bool	solo_chunk(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->chunk != temp->next->chunk)
			return (false);
		temp = temp->next;
	}
	return (true);
}

int	chunk_len(t_stack *stack, int chunk)
{
	t_stack	*temp;
	int		len;

	temp = stack;
	len = 0;
	while (temp)
	{
		if (temp->chunk == chunk)
			len++;
		temp = temp->next;
	}
	return (len);
}
