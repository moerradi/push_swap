/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:52:55 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/04 13:08:45 by moerradi         ###   ########.fr       */
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

void	exiterr(void);
int		checknparse(char *s, int *arr);
void	print_arr(t_env *e);
void	print_stack(t_stack *stack);
t_stack	*new_node(int n);
void	add_front(t_stack **stack, t_stack *new);
void	add_back(t_stack **stack, t_stack *new);
int		get_last(t_stack *stack);
void	pop(t_stack **stack);
void	pop_last(t_stack **stack);
void	swap(t_stack *stack);
void	push(t_stack **src, t_stack **dest);
void	rotate(t_stack **stack);
void	r_rotate(t_stack **stack);
void	ss(t_env *e);
void	rr(t_env *e);
void	rrr(t_env *e);


#endif