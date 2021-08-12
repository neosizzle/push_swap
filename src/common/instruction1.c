#include "common.h"

//sa, swap first 2 elems at stack a
//does nothing if there are less than 2 elems
void	sa(t_stacks *stacks, int is_print)
{
	print_instr("sa", is_print);
	if (stacks->alen > 1)
		ft_array_swap(stacks->a, 0, 1);
}

//sa, swap first 2 elems at stack b
//does nothing if there are less than 2 elems
void	sb(t_stacks *stacks, int is_print)
{
	print_instr("sb", is_print);
	if (stacks->blen > 1)
		ft_array_swap(stacks->b, 0, 1);
}

//ss, sa + sb -_-
void	ss(t_stacks *stacks, int is_print)
{
	print_instr("ss", is_print);
	sb(stacks, 0);
	sa(stacks, 0);
}

//pa, takes top elem at b and 
//push it to a
void	pa(t_stacks *stacks, int is_print)
{
	int	i;

	if (stacks->blen)
	{
		print_instr("pa", is_print);
		stacks->alen++;
		i = stacks->alen;
		while (--i > 0)
			stacks->a[i] = stacks->a[i - 1];
		stacks->a[0] = stacks->b[0];
		i = -1;
		stacks->blen--;
		while (++i < stacks->blen)
			stacks->b[i] = stacks->b[i + 1];
	}
}

//pa, takes top elem at a and 
//push it to b
void	pb(t_stacks *stacks, int is_print)
{
	int	i;

	if (stacks->alen)
	{
		print_instr("pb", is_print);
		stacks->blen++;
		i = stacks->blen;
		while (--i > 0)
			stacks->b[i] = stacks->b[i - 1];
		stacks->b[0] = stacks->a[0];
		i = -1;
		stacks->alen--;
		while (++i < stacks->alen)
			stacks->a[i] = stacks->a[i + 1];
	}
}
