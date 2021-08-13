#include "common.h"

//this function will run thru both stacks a and b
//reutns ko if unsorted and ok if otherwise
void	checker(t_stacks stacks)
{
	int		i;

	if (stacks.blen)
	{
		write(1, "KO\n", 3);
		return ;
	}
	i = -1;
	while (++i < stacks.alen - 1)
	{
		if (stacks.a[i] > stacks.a[i + 1])
		{
			write(1, "KO\n", 3);
			return ;
		}
	}
	write(1, "OK\n", 3);
}
