/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:10:21 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/09 11:07:53 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_arr(int *arr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putnbr_fd(arr[i], 1);
		ft_putstr_fd(" ", 1);
		i++;
	}
	ft_putstr_fd("\n", 1);

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
		ft_putstr_fd(" ", 1);
		temp = temp->next;
	}
	 ft_putstr_fd("\n", 1);
}