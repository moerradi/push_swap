/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:52:55 by moerradi          #+#    #+#             */
/*   Updated: 2021/05/31 15:02:11 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"
# define	INT_MAX 2147483647
# define	INT_MIN -2147483648

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
}					t_stack;

typedef struct s_env
{
	t_stack			*a;
	t_stack			*b;
	int				*arr;
	int				len;
}					t_env;

int	checknparse(char *s, int *arr);
void    print_arr(t_env *e);
void	print_stack(t_stack *stack);
void    swap(t_stack *stack);

#endif