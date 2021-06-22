/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:52:55 by moerradi          #+#    #+#             */
/*   Updated: 2021/06/22 06:42:37 by moerradi         ###   ########.fr       */
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

void	exiterr(t_env *e);
bool	is_sorted(t_stack *stack, bool order);
bool	chunk_is_sorted(t_stack *stack, int chunk, bool order);
int		checknparse(char *s, int *arr);
int		init(t_env *e, char **argv);
void	print_arr(int *arr, int len);
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
void	keep_pushing(t_stack **src, t_stack **dest, int chunk, char v);
bool	solo_chunk(t_stack *stack);
int		chunk_len(t_stack *stack, int chunk);
t_stack	*stack_dup(t_stack *head);
int		keep_rotating(t_stack **stack, int pivot, int dir, char v);
int		keep_rotating2(t_stack **stack, int pivot, int dir, char v);
int		optimize_rot(t_stack *stack, int pivot, int dir);
void	rev(t_stack **stack, int times, char v);
int		get_pivot(t_stack *stack, int chunk);
void	free_stack(t_stack **stack);
void	sort_rest(t_stack **stack, int len, bool order, char name);
void	sort_array(int *arr, int len);
void	super_sort(t_env *e);
void	go(t_env *e);

#endif