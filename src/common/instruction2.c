#include "common.h"

//ra, shift all elements in a up
void	ra(t_stacks *stacks, int is_print)
{
	int	i;
	int	temp;

	print_instr("ra", is_print);
	temp = stacks->a[0];
	i = -1;
	while (++i < stacks->alen - 1)
		stacks->a[i] = stacks->a[i + 1];
	stacks->a[stacks->alen - 1] = temp;
}

//rb, shift all elements in b up
void	rb(t_stacks *stacks, int is_print)
{
	int	i;
	int	temp;

	print_instr("rb", is_print);
	temp = stacks->b[0];
	i = -1;
	while (++i < stacks->blen - 1)
		stacks->b[i] = stacks->b[i + 1];
	stacks->b[stacks->blen - 1] = temp;
}

//rr , ra + rb
void	rr(t_stacks *stacks, int is_print)
{
	print_instr("rr", is_print);
	ra(stacks, 0);
	rb(stacks, 0);
}

//rra, shift all elements in a down
void	rra(t_stacks *stacks, int is_print)
{
	int	i;
	int	temp;

	print_instr("rra", is_print);
	temp = stacks->a[stacks->alen - 1];
	i = stacks->alen;
	while (--i > 0)
		stacks->a[i] = stacks->a[i - 1];
	stacks->a[0] = temp;
}

//rrb, shift all elements in b down
void	rrb(t_stacks *stacks, int is_print)
{
	int	i;
	int	temp;

	print_instr("rrb", is_print);
	temp = stacks->b[stacks->blen - 1];
	i = stacks->blen;
	while (--i > 0)
		stacks->b[i] = stacks->b[i - 1];
	stacks->b[0] = temp;
}
