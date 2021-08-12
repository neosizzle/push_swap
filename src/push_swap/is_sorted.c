#include "push_swap.h"

//this function will receive an 
//arr to check if its sorted or no
int	is_sorted(int *stack, int len, int is_ascend)
{
	int		i;

	i = -1;
	while (++i < len - 1)
		if ((is_ascend && stack[i] > stack[i + 1])
			|| (!(is_ascend) && stack[i] < stack[i + 1]))
			return (0);
	return (1);
}
