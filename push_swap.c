/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:01:53 by moerradi          #+#    #+#             */
/*   Updated: 2021/05/30 17:51:55 by moerradi         ###   ########.fr       */
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
	if (*s == '-' || *s == '+')
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

int	has_dup(int *arr, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 2)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	init(t_env *e, int argc, char **argv)
{
	int i;

	i  = 1;
	while (i < argc)
	{
		if (!checknparse(argv[i], &e->arr[i - 1]))
			return (0);
		i++;
	}
	if (has_dup(e->arr, argc))
		return (0);
	return (1);
}

void	array_to_stack(t_env *e)
{
		
}

int	main(int argc, char **argv)
{
	t_env	e;

	e.arr = malloc(sizeof(int) * (argc - 1));
	if (argc < 2)
		exiterr();
	if (!init(&e, argc, argv))
		exiterr();

	//push_swap(e);
	return (0);
}