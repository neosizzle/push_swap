#include "checker.h"

void	get_instr(char **instr)
{
	char	buf[1024];
	char	*temp;
	int		read_byte;

	read_byte = read(0, buf, 1024);
	*instr = ft_strdup("");
	while (read_byte > 0)
	{
		buf[read_byte] = 0;
		temp = ft_strjoin(*instr, buf);
		free(*instr);
		*instr = temp;
		read_byte = read(0, buf, 1024);
		if (read_byte < 0)
		{
			error();
			break ;
		}
	}
}
