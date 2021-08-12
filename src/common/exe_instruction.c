#include "common.h"

//this file will contains the function exe_instr

//find the length of instruction
//deliminated by whitespace
static int	leninstr(char *instr)
{
	int		res;

	res = 0;
	while (instr && instr[res] && instr[res] != ' ')
		res++;
	return (res);
}

//exe instr takes a set if instructions e.g. "pb pb sa"
//and exeutes them 1 by 1
//created this for norm, because it would be more clearer
//to call pb() pb() sa() in parent func
/*
1. while the instr string has content, do sth
	- attempt to find the curr pointer instr in fun_list
	- executes function if found
	- returns 0 if not
	- increments pointer to point to next instr
*/
int	exe_instr(t_stacks *stacks, t_fun *fun_list, char *instr, int is_print)
{
	int	i;
	int	instr_found;

	while (instr[0])
	{
		while (instr[0] == ' ')
			instr++;
		instr_found = 0;
		i = -1;
		while (!instr_found && fun_list[++i].instr)
		{
			if (ft_strnequ(instr, fun_list[i].instr, leninstr(instr)))
			{
				fun_list[i].f(stacks, is_print);
				instr_found = 1;
			}
		}
		if (!instr_found)
			return (0);
		instr += leninstr(instr);
	}
	return (1);
}
