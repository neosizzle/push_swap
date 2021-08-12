#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

int		is_sorted(int *stack, int len, int is_ascend);
void	quick_sort_reg(int *array, int start, int end);
int		exe_instr(t_stacks *stacks, t_fun *fun_list, char *instr, int is_print);
void	sort_3(t_stacks *stacks, t_fun *fun_list, int len, int is_print);
void	push_sort_3(t_stacks *stacks, t_fun *fun_list, int len, int is_print);
int		get_median(int *median, int *stack, int len);
int		quick_sort_a(t_stacks *stacks, t_fun *fun_list, int len);
int		quick_sort_b(t_stacks *stacks, t_fun *fun_list, int len);

#endif  //!__PUSH_SWAP__H__