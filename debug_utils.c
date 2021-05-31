/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:10:21 by moerradi          #+#    #+#             */
/*   Updated: 2021/05/31 00:51:38 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_arr(t_env *e)
{
    int i;

    i = 0;
    while (i < e->len)
    {
        ft_putnbr_fd(e->arr[i], 1);
        ft_putstr_fd("\n", 1);
        i++;
    }
}

void	print_stack(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	temp = stack;
	while (temp)
	{
		ft_putnbr_fd(temp->n, 1);
        ft_putstr_fd("\n", 1);
		temp = temp->next;
	}
}