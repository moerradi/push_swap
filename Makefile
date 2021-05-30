NAME = push_swap
BON = checker
FLAGS = -Wall -Werror -Wextra
SRCS = stack.c push_swap.c

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -O $(NAME)

clean:
	make -C libft

fclean: clean
	/bin/rm push_swap
	/bin/rm checker

re: fclean all

.PHONY: clean fclean all re