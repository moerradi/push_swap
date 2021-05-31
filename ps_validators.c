/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:56:08 by moerradi          #+#    #+#             */
/*   Updated: 2021/05/30 22:52:04 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	ft_atoll(const char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str++ - '0';
	}
	return (sign * result);
}

static int	isnum(char *s)
{
	if (!s)
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	checknparse(char *s, int *arr)
{
	long long	tmp;

	if (!isnum(s))
		return (0);
	tmp = ft_atoll(s);
	if (tmp > INT_MAX || tmp < INT_MIN)
		return (0);
	else
		*arr = (int)tmp;
	return (1);
}
