#include "stack.h"


void	exiterr(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}


int		init(t_env *e, int argc, char **argv)
{
	int i;

	i  = 1;
	while (i < argc)
	{
		if (!check(argv[i++]))
			return (0);
		else
		{
			fill(e->a, argv[i]);
		}
	}
}

int		main(int argc, char **argv)
{
	t_env e;

	if (argc < 2)
		exiterr();
	if (!init(&e, argc, argv))
		exiterr();
	push_swap(e);
	return (0);
}