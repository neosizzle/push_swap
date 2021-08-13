#include "common.h"

//my util go here

/*
** Swaps elements at index i1 and i2 if array exists.
*/
void	ft_array_swap(int *array, int i1, int i2)
{
	int		tmp;

	if (!array)
		return ;
	tmp = array[i1];
	array[i1] = array[i2];
	array[i2] = tmp;
}

/*
** Returns true if the n first characters of s1 and s2 are similar.
*/
int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	return (!ft_strncmp(s1, s2, n));
}

/*
** Returns true if the strangs are similar, false otherwise.
*/
int	ft_strequ(char const *s1, char const *s2)
{
	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	return (!ft_strcmp(s1, s2));
}

/*
** Compares s1 and s2 and returns 0 if they are similar, a different value
** otherwise.
*/
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

/*
** Replaces one character with another in a string
*/
void	ft_strrplc(char *str, char a, char b)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == a)
			str[i] = b;
	}
}
