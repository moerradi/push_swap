# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moerradi <moerradi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/05 13:23:46 by moerradi          #+#    #+#              #
#    Updated: 2021/06/07 18:30:51 by moerradi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BON = checker
FLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c pw_validators.c
BON_SRCS = checker.c ps_utils.c ps_ops.c mosa3ada.c general_utils.c \
		ps_validators.c
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME)

clean:
	make -C libft clean

bonus: $(BON)

$(BON):
	make -C libft
	gcc $(FLAGS) $(BON_SRCS) $(LIBFT) -o $(BON) 

fclean: clean
	make -C libft fclean
	/bin/rm -f push_swap
	/bin/rm -f checker

re: fclean all

.PHONY: clean fclean all re