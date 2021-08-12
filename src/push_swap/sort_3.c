#include "push_swap.h"

//this file contains the sorting funcs are arr length
//<= 3

/*
CASE 1 - stack looks like 5 7 6 (a[0] least & a[1] > a[2])
	1. shift down all elemts - 6 5 7
	2. switch the top two elems - 5 6 7

CASE 2- stack looks like 7 6 5 or 7 5 6 (a[0] most)
	1. for 7 6 5 , sa to 6 7 5, rra to 5 6 7
	2. for 7 5 6, ra to 5 6 7

CASE 3- stack looks like 6 7 5 or 6 5 7 (a[0] mid)
	1. for 6 7 5, rra into 5 6 7
	2. for 6 5 7, sa into 5 6 7
*/
static void	a_sort_3(t_stacks *stacks, t_fun *fun_list, int is_print)
{
	if (stacks->a[0] < stacks->a[1] && stacks->a[0] < stacks->a[2])
	{
		if (stacks->a[1] > stacks->a[2])
			exe_instr(stacks, fun_list, "rra sa", is_print);
	}
	else if (stacks->a[0] > stacks->a[1] && stacks->a[0] > stacks->a[2])
	{
		if (stacks->a[1] < stacks->a[2])
			ra(stacks, is_print);
		else
			exe_instr(stacks, fun_list, "sa rra", is_print);
	}
	else
	{
		if (stacks->a[1] < stacks->a[2])
			sa(stacks, is_print);
		else
			rra(stacks, is_print);
	}
}

//stupid helper func norm
//literally just call pb and decrement len
static void	call_pb_dec_len(t_stacks *stacks, int is_print, int *len)
{
	pb(stacks, is_print);
	(*len)--;
}

/*
this func will call specific helpers or actions depending on the cases
CASE 1 - a.len = 3 and the numbers of elements is 3
	1. call a_sort_3

CASE 2 - the length of the stack a is 2
	1. sa if the 0th elem is > 1st elem

CASE 3 - number of elems is 3 but length of stack a is not 3 (cant use ra or rra)
	SUBCASE 1, stack looks like 6 5 7
		- sa
	SUBCASE 2, stack looks like 5 7 6 
		-cant use rra, so we push to b, sa and push to a again
	
*/
void	sort_3(t_stacks *stacks, t_fun *fun_list, int len, int is_print)
{
	if (len == 3 && stacks->alen == 3)
		a_sort_3(stacks, fun_list, is_print);
	else if (len == 2)
	{
		if (stacks->a[0] > stacks->a[1])
			sa(stacks, is_print);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stacks->a[0] < stacks->a[1]
				&& stacks->a[1] < stacks->a[2]))
		{
			if (len == 3 && stacks->a[0] > stacks->a[1] && stacks->a[2])
				sa(stacks, is_print);
			else if (len == 3 && !(stacks->a[2] > stacks->a[0]
					&& stacks->a[2] > stacks->a[1]))
				call_pb_dec_len(stacks, is_print, &len);
			else if (stacks->a[0] > stacks->a[1])
				sa(stacks, is_print);
			else if (len++)
				pa(stacks, is_print);
		}
	}
}

//this func will get called is stack b
//reached the base case, it will sort by pushing elems to a
/*
CASE 1 - a : _ 2 3 4, b : 1
	-pa

CASE 2 - a : _ _ 4 5 6 , b : 2 3
	-sb if not sorted and pa
	
CASE 3 - a : _ _ _ 5 6 7, b : 3 2 1
	- do all the sbs needed to push max elem to a
*/
void	push_sort_3(t_stacks *stacks, t_fun *fun_list, int len, int is_print)
{
	if (len == 1)
		pa(stacks, is_print);
	else if (len == 2)
	{
		if (stacks->b[0] < stacks->b[1])
			sb(stacks, is_print);
		exe_instr(stacks, fun_list, "pa pa", is_print);
	}
	else if (len == 3)
	{
		while (len || !(stacks->a[0] < stacks->a[1]
				&& stacks->a[1] < stacks->a[2]))
		{
			if (len == 1 && stacks->a[0] > stacks->a[1])
				sa(stacks, is_print);
			else if (len == 1 || (len >= 2 && stacks->b[0] > stacks->b[1])
				|| (len == 3 && stacks->b[0] > stacks->b[2]))
			{
				pa(stacks, is_print);
				len--;
			}
			else
				sb(stacks, is_print);
		}
	}
}
