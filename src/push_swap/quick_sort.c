#include "push_swap.h"

//this file contains the core quickswap method
//using the two stacks

//initialize the elem_cnt and push offsets vars
//to certain values
static void	init_vars(int *elem_cnt, int *push_offset, int len)
{
	*elem_cnt = len;
	*push_offset = 0;
}

//stupid helper function cuz norm
//responsibile for moving the values
//>= median from b to a 
static void	b_moving(t_stacks *stacks, int median, int *p_o, int *len)
{
	if (stacks->b[0] >= median)
	{
		pa(stacks, 1);
		(*len)--;
	}
	else if (++(*p_o))
		rb(stacks, 1);
}

//quick sort algo for stack a
/*
BASE CASES : 
	- current parti is sorted, return
	- current parti length <= 3, sort and return
1. Get the median VALUE from the current partition
2. move all the values in that partition which are < median
	to stack b (shift down if needed)
3. shift up all ahifted down elements if there are multiple
	partitions in the stack
4. recursively call this func again til base case reached
5. recursively call quick sort b function

Since we always choose the median as pivot,
Every partition is always len of current partition / 2,
so the next recursive calls partition length will
always be current partition / 2.
*/
int	quick_sort_a(t_stacks *stacks, t_fun *fun_list, int len)
{
	int	median;
	int	elem_cnt;
	int	push_offset;

	if (is_sorted(stacks->a, len, 1))
		return (1);
	init_vars(&elem_cnt, &push_offset, len);
	if (len <= 3)
	{
		sort_3(stacks, fun_list, len, 1);
		return (1);
	}
	if (!get_median(&median, stacks->a, len))
		return (0);
	while (len != elem_cnt / 2 + elem_cnt % 2)
	{
		if (stacks->a[0] < median && (len--))
			pb(stacks, 1);
		else if ((++push_offset))
			ra(stacks, 1);
	}
	while (elem_cnt / 2 + elem_cnt % 2 != stacks->alen && push_offset--)
		rra(stacks, 1);
	return (quick_sort_a(stacks, fun_list, elem_cnt / 2 + elem_cnt % 2)
		&& quick_sort_b(stacks, fun_list, elem_cnt / 2));
}

//quick sort algo for stack b
/*
BASE CASES : 
	- current parti is sorted, push all to a, return
	- current parti length <= 3, sort and return
1. Get the median VALUE from the current partition
2. move all the values in that partition which are >= median
	to stack b (shift down if needed)
3. shift up all ahifted down elements if there are multiple
	partitions in the stack
4. recursively call sort a func again til base case reached
5. recursively call quick sort b function

Since we always choose the median as pivot,
Every partition is always len of current partition / 2,
so the next recursive calls partition length will
always be current partition / 2.
*/
int	quick_sort_b(t_stacks *stacks, t_fun *fun_list, int len)
{
	int	median;
	int	elem_cnt;
	int	push_offset;

	if (is_sorted(stacks->b, len, 0))
	{
		while (len--)
			pa(stacks, 1);
	}
	if (len <= 3)
	{
		push_sort_3(stacks, fun_list, len, 1);
		return (1);
	}
	init_vars(&elem_cnt, &push_offset, len);
	if (!get_median(&median, stacks->b, len))
		return (0);
	while (len != elem_cnt / 2)
		b_moving(stacks, median, &push_offset, &len);
	while (elem_cnt / 2 != stacks->blen && push_offset--)
		rrb(stacks, 1);
	return (quick_sort_a(stacks, fun_list, elem_cnt / 2 + elem_cnt % 2)
		&& quick_sort_b(stacks, fun_list, elem_cnt / 2));
}
