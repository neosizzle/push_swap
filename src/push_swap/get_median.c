#include "push_swap.h"

//this function will receive
//an array and an int ptr and it will
//modify the int ptr with the median
//of that arr
int	get_median(int *median, int *stack, int len)
{
	int	*temp;
	int	i;

	temp = (int *)malloc(sizeof(int) * len);
	if (!temp)
		return (0);
	i = -1;
	while (++i < len)
		temp[i] = stack[i];
	quick_sort_reg(temp, 0, len - 1);
	*median = temp[len / 2];
	free(temp);
	return (1);
}
