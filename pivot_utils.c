/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 20:21:40 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/13 02:09:14 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_val(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

static void	sort_array(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap_val(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

static int	*chunk_to_array(t_stack *stack, int chunk)
{
	t_stack	*temp;
	int		*ret;
	int		i;

	temp = stack;
	ret = (int *)malloc(sizeof(int) * chunk_len(stack, chunk));
	if (!ret)
		return (NULL);
	i = 0;
	while (temp)
	{
		if (temp->chunk == chunk)
			ret[i] = temp->n;
		i++;
		temp = temp->next;
	}
	return (ret);
}

int	get_pivot(t_stack *stack, int chunk)
{
	int	*arr;
	int	len;
	int	ret;

	len = chunk_len(stack, chunk);
	arr = chunk_to_array(stack, chunk);
	sort_array(arr, len);
	ret = arr[len / 2];
	free(arr);
	return (ret);
}
