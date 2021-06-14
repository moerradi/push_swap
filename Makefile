# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/05 13:23:46 by moerradi          #+#    #+#              #
#    Updated: 2021/06/13 20:32:32 by moerradi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BON = checker
FLAGS = -Wall -Werror -Wextra -g -fsanitize=address
SRCS_GEN =  ps_validators.c  general_utils.c is_sorted.c mosa3ada.c	\
			ps_ops.c ps_utils.c
OBJS_GEN = $(SRCS_GEN:%.c=%.o)
SRCS =  chunking_utils.c push_swap.c pivot_utils.c rotating_utils.c	\
		sorting_algo.c sort_utils.c
OBJS = $(SRCS:%.c=%.o)
BON_SRCS = checker.c
BON_OBJS=$(BON_SRCS:%.c=%.o)
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS_GEN) $(OBJS)
	make -C libft
	gcc $(FLAGS) $(OBJS) $(OBJS_GEN) $(LIBFT) -o $(NAME)

$(OBJS): $(SRCS)
	gcc -c $(FLAGS) $(SRCS)

$(OBJS_GEN): $(SRCS_GEN)
	gcc -c $(FLAGS) $(SRCS_GEN)

bonus: $(BON)

$(BON): $(OBJS_GEN) $(BON_OBJS)
	make -C libft
	gcc $(FLAGS) $(BON_OBJS) $(OBJS_GEN) $(LIBFT) -o $(BON) 

$(BON_OBJS): $(BON_SRCS)
	gcc -c $(FLAGS) $(BON_SRCS)

clean:
	make -C libft clean
	/bin/rm -f $(OBJS) $(OBJS_GEN) $(BON_OBJS)

fclean: clean
	make -C libft fclean
	/bin/rm -f push_swap
	/bin/rm -f checker

re: fclean all

.PHONY: clean fclean all re