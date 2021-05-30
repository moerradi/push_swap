/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:01:53 by moerradi          #+#    #+#             */
/*   Updated: 2021/05/30 16:37:13 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	exiterr(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

long long	ft_atoll(const char *str)
{
	long long	result;
	int		sign;

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

int	isnum(char *s)
{
	if (!s)
		return (0);
	if (*s == '-' || s == '+')
		s++;
	while (*s)
	{
		if(!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	checknparse(char *s, int *arr)
{
	if (!isnum(s))
		return (0);
}

int	init(t_env *e, int argc, char **argv)
{
	int i;

	i  = 1;
	while (i < argc)
	{
		if (!checknparse(argv[i], e->arr));
			return (0);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_env e;

	if (argc < 2)
		exiterr();
	if (!init(&e, argc, argv))
		exiterr();
	push_swap(e);
	return (0);
}