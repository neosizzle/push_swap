#include "checker.h"

//frees all malloc ptrs passed in as args
static void	end(t_stacks stacks, t_fun *fun_list, char *instr, char *temp)
{
	free(stacks.a);
	free(stacks.b);
	free(temp);
	free(instr);
	delete_funlist(fun_list);
}

//same purpsoe as init stacks on push_swap main.c
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
		ft_putstr_fd("Error\n", 1);
		exit(-1)
	}
	return (stacks);
}

/*
1. checks for invalid args
2. init stacks and func list
3. call helper to get instructions from stdin
4. replace \n with spaces and trim the last space
5. call helper function to execute all the instructions
6. calls checker function to validate its sorted or not
7. free all malloced memory
*/
int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	t_fun		*fun_list;
	char		*instr;
	char		*temp;

	if (argc < 2)
	{
		ft_putstr_fd("Error!\n", 1);
		exit(0);
	}
	stacks = init_stacks(--argc, ++argv);
	fun_list = init_fun_list();
	get_instr(&instr);
	ft_strrplc(instr, '\n', ' ');
	temp = ft_substr(instr, 0, ft_strlen(instr) - 1);
	free(instr);
	instr = ft_strdup(temp);
	exe_instr(&stacks, fun_list, instr, 0);
	checker(stacks);
	end(stacks, fun_list, instr, temp);
	return (0);
}
