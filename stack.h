#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct		s_stack
{
	int				n;
	struct s_stack	*next;
}					t_stack;


typedef struct		s_env
{
	t_stack			*a;
	t_stack			*b;
	int				len;
}					t_env;



#endif