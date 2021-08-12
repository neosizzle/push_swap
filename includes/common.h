#ifndef COMMON_H
# define COMMON_H

# include "../libft/libft.h"
# include <limits.h>
# include <fcntl.h>

//a struct that stores both of the stacks and their lengths
typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		alen;
	int		blen;
}				t_stacks;

//a struct that stores an action name and its function
typedef struct s_fun {
	char	*instr;
	void	(*f)(t_stacks *, int);
}				t_fun;

//a struct for file IO
typedef struct	s_file
{
	int				fd;
	char			buf[1024 + 1];
	int				i;
}				t_file;

//funcs
void	error(void);

//stack related functions
int		*gen_stack(char **input, int *len);

//stack actions
t_fun	*init_fun_list(void);
void	delete_funlist(t_fun *fun_list);
void	sa(t_stacks *stacks, int is_print);
void	sb(t_stacks *stacks, int is_print);
void	ss(t_stacks *stacks, int is_print);
void	pa(t_stacks *stacks, int is_print);
void	pb(t_stacks *stacks, int is_print);
void	ra(t_stacks *stacks, int is_print);
void	rb(t_stacks *stacks, int is_print);
void	rr(t_stacks *stacks, int is_print);
void	rra(t_stacks *stacks, int is_print);
void	rrb(t_stacks *stacks, int is_print);
void	rrr(t_stacks *stacks, int is_print);

//print funcs
void	print_instr(char *instr, int is_print);

//utils
void	ft_array_swap(int *array, int i1, int i2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);

#endif  //!__COMMON__H__