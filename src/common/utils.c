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
** Initializes the stream associated with the file path.
*/
t_file	*ft_fopen(const char *path)
{
	t_file	*stream;

	if (!(stream = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	if ((stream->fd = open(path, O_RDONLY)) == -1)
	{
		free(stream);
		return (NULL);
	}
	ft_bzero(stream->buf, sizeof(char) * (1024 + 1));
	stream->i = 0;
	return (stream);
}