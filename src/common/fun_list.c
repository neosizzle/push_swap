#include "common.h"

//this file contains all the functions that
//are related to the stack actions

//this populates the instruction strings for 
//the func structs
static void	init_fun_list_instr(t_fun *fun_list)
{
	fun_list[0].instr = ft_strdup("sa");
	fun_list[1].instr = ft_strdup("sb");
	fun_list[2].instr = ft_strdup("ss");
	fun_list[3].instr = ft_strdup("pa");
	fun_list[4].instr = ft_strdup("pb");
	fun_list[5].instr = ft_strdup("ra");
	fun_list[6].instr = ft_strdup("rb");
	fun_list[7].instr = ft_strdup("rr");
	fun_list[8].instr = ft_strdup("rra");
	fun_list[9].instr = ft_strdup("rrb");
	fun_list[10].instr = ft_strdup("rrr");
	fun_list[11].instr = 0;
}

//this function populates the instruction
//functions for action struct
static void	initialize_fun_list_f(t_fun *fun_list)
{
	fun_list[0].f = &sa;
	fun_list[1].f = &sb;
	fun_list[2].f = &ss;
	fun_list[3].f = &pa;
	fun_list[4].f = &pb;
	fun_list[5].f = &ra;
	fun_list[6].f = &rb;
	fun_list[7].f = &rr;
	fun_list[8].f = &rra;
	fun_list[9].f = &rrb;
	fun_list[10].f = &rrr;
	fun_list[11].f = 0;
}

//this function initializes a list
//of action name and pointers to the actions funcs
//and returns it
//TODO : probably need err checking if helpers fail
t_fun	*init_fun_list(void)
{
	t_fun	*fun_list;

	fun_list = (t_fun *)malloc(sizeof(t_fun) * 12);
	if (!fun_list)
		return (0);
	init_fun_list_instr(fun_list);
	initialize_fun_list_f(fun_list);
	return (fun_list);
}

//this function frees the func list provided as
//param
void	delete_funlist(t_fun *fun_list)
{
	int	i;

	i = -1;
	while (++i < 11)
	{
		if (fun_list[i].instr)
			free(fun_list[i].instr);
	}
	free(fun_list);
}
