#include "common.h"

//rrr, shifts down both
void	rrr(t_stacks *stacks, int is_print)
{
	print_instr("rrr", is_print);
	rrb(stacks, 0);
	rra(stacks, 0);
}
