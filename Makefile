NAME = push_swap
BON = checker
FLAGS = -Wall -Werror -Wextra
SRCS = stack.c push_swap.c pw_validators.c
BON_SRCS = checker.c stack.c
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME)

clean:
	make -C libft clean

bonus: $(BON)

$(BON):
	gcc $(FLAGS) $(SRCS) $(LIBFT) -o $(BON) 

fclean: clean
	make -C libft fclean
	/bin/rm -f push_swap
	/bin/rm -f checker

re: fclean all

.PHONY: clean fclean all re