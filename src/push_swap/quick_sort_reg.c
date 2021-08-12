#include "push_swap.h"

//this file contains the regular quicksort function
//without using stacks
//needed to find median

//quick sort partion function
//basically selects a pivot
//and rearranges the arr so that
//elems < pvot will be on the left of the pivot
//and vice versa for elems on the right
/*
1. selects an elem as pivot (i selected the elem at the end)
2. part_i is the final idx of pivot
3. start looping throu the arr
	- if we see any elems < pivot, we swap them with the 
	elem at patition i
	- increment part_i if we swap
4. swap pivot value with value at partition i and return part_i
*/
static int	partition(int *arr, int start, int end)
{
	int	pivot;
	int	temp;
	int	part_i;
	int	i;

	pivot = arr[end];
	i = start - 1;
	part_i = start;
	while (++i < end)
	{
		if (arr[i] <= pivot)
		{
			temp = arr[i];
			arr[i] = arr[part_i];
			arr[part_i++] = temp;
		}
	}
	temp = arr[i];
	arr[i] = arr[part_i];
	arr[part_i] = temp;
	return (part_i);
}

//quick sort
//only continues when start idx < end idx
//means it will stop when there is <= 1 elem
/*
1. call partition helper to rearrange arr and get part idx
2. recursively call to the left and right side of the arr
*/
void	quick_sort_reg(int *array, int start, int end)
{
	int	part_idx;

	if (start < end)
	{
		part_idx = partition(array, start, end);
		quick_sort_reg(array, start, part_idx - 1);
		quick_sort_reg(array, part_idx + 1, end);
	}
}
