/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:52:55 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/11 15:33:12 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdbool.h>
# include "libft/libft.h"
# define	INT_MAX 2147483647
# define	INT_MIN -2147483648

typedef struct s_stack
{
	int				n;
	int				chunk;
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
bool	is_sorted(t_stack *stack, bool order);
bool	chunk_is_sorted(t_stack *stack, int chunk, bool order);
int		checknparse(char *s, int *arr);
int		init(t_env *e, char **argv);
void    print_arr(int *arr, int len);
void	print_stack(t_stack *stack);
t_stack	*new_node(int n, int chunk);
void	add_front(t_stack **stack, t_stack *new);
void	add_back(t_stack **stack, t_stack *new);
t_stack	*get_last(t_stack *stack);
int		stack_size(t_stack *stack);
void	pop(t_stack **stack);
void	pop_last(t_stack **stack);
void	swap(t_stack *stack, char name);
void	push(t_stack **src, t_stack **dest, int chunk, char name);
void	rotate(t_stack **stack, char name);
void	r_rotate(t_stack **stack, char name);
void	ss(t_env *e);
void	rr(t_env *e);
void	rrr(t_env *e);
void	swap_val(int *xp, int *yp);
void	go(t_env *e);



#endif