#include "common.h"

//the main function of this file will generate
//a stack and return it

//this function will compare if any numbers
//in the stack are unique up till index
static int	is_unique(int *stack, int index)
{
	int		i;

	i = -1;
	while (++i < index)
		if (stack[i] == stack[index])
			return (0);
	return (1);
}

//this function will increment 
//the input string to point to the start
//of the number
//this is needed because when we extract the number,
//we move the char ptr which may mess up the offset
static int	go_to_start(char ***input)
{
	int		sign;

	while ((***input < '0' || ***input > '9') && ***input != '-')
	{
		if (!***input)
			(*input)++;
		else if (***input == ' ' || ***input == '\t')
			(**input)++;
		else
			return (0);
	}
	if (***input == '-')
	{
		sign = -1;
		**input += 1;
	}
	else
		sign = 1;
	if (***input < '0' || ***input > '9')
		return (0);
	return (sign);
}

//given an array of strings, extract the next integer
//and put it in the nbr int array
static int	get_number(int *nbr, char ***input)
{
	int		sign;

	*nbr = 0;
	sign = go_to_start(input);
	if (!sign)
		return (0);
	while (***input >= '0' && ***input <= '9')
	{
		if (*nbr > INT_MAX / 10 || (*nbr == INT_MAX / 10 && (***input > '8'
					|| (***input == '8' && sign == 1))))
			return (0);
		else if (*nbr == INT_MAX / 10 && ***input == '8' && sign == -1)
		{
			sign = 1;
			*nbr = -10 * *nbr - 8;
		}
		else
			*nbr = 10 * *nbr + ***input - '0';
		(**input)++;
	}
	if (***input != ' ' && ***input != 0 && ***input != '\t')
		return (0);
	*nbr *= sign;
	return (1);
}

//this function will get the total length of the 
//int array that can be generated given the arr
//of strings as input
int	get_ttl_len(char **input, int len)
{
	int		res;
	int		i;
	int		j;

	res = 0;
	i = -1;
	while (++i < len)
	{
		j = 0;
		while (input[i][j])
		{
			if (!j && input[i][j] != ' ')
				res++;
			else if (input[i][j] != ' ' && input[i][j - 1] == ' ')
				res++;
			j++;
		}
	}
	return (res);
}

//to generate an int array as a stack given the arr of strings
//does all the parsing and constraint checking
int	*gen_stack(char **input, int *len)
{
	int		*res;
	int		ttl_len;
	int		i;

	ttl_len = get_ttl_len(input, *len);
	res = (int *)malloc(sizeof(int) * ttl_len);
	if (!res)
		return (0);
	i = -1;
	while (++i < ttl_len)
	{
		if (!get_number(res + i, &input) || !is_unique(res, i))
		{
			free(res);
			return (0);
		}
	}
	*len = ttl_len;
	return (res);
}
