#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"
#include <stdio.h>

void	usage(void);
void	checker(t_stacks stacks);
void	get_instr(char **instr);
int		instr_check(char *instr, t_fun *fun_list);

#endif