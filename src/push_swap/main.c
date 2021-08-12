#include "push_swap.h"

//throws error and exits program
void	error(void)
{
	ft_putstr_fd("Error!\n", 1);
	exit(0);
}

//func to free stacks
static void	delete_stacks(t_stacks stacks)
{
	free(stacks.a);
	free(stacks.b);
}

//this function is responsible to initialize the stacks in a struct
/*
1. gets the number of args and make it the length
of stack a

2. call helper to generate the stack for a (an int arr)

3. err checking to protect malloc

4. set the stack b length to 0 since we wanna start empty
*/
static t_stacks	init_stacks(int argc, char *argv[])
{
	t_stacks	stacks;

	stacks.alen = argc;
	stacks.blen = 0;
	stacks.a = gen_stack(argv, &stacks.alen);
	stacks.b = (int *)malloc(sizeof(int) * stacks.alen);
	if (!stacks.a || !stacks.b)
	{
		free(stacks.a);
		free(stacks.b);
		error();
	}
	return (stacks);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	t_fun		*fun_list;

	if (argc < 2)
		error();
	stacks = init_stacks(--argc, ++argv);
	fun_list = init_fun_list();
	if (!fun_list || !quick_sort_a(&stacks, fun_list, stacks.alen))
	{
		delete_stacks(stacks);
		delete_funlist(fun_list);
		error();
	}
	delete_stacks(stacks);
	delete_funlist(fun_list);
	return (0);
}
