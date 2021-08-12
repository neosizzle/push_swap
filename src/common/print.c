#include "common.h"

//this function will print out the 
//instruction if isprint is 1
void	print_instr(char *instr, int is_print)
{
	if (is_print)
	{
		ft_putstr_fd(instr, 1);
		ft_putchar_fd('\n', 1);
	}
}
