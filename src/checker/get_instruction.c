#include "checker.h"

//this function will get all input
//from stdin and put it in
//*instr
/*
1. init instr with empty string and read the first 1024 bytes
2. while the read bytes is more than 0 (got input)
3. null terminate buffer
4. join the instructions with the buffer
5. read until EOF or error occur
*/
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
			ft_putstr_fd("Read Error\n", 1);
			exit(-1);
			break ;
		}
	}
}
