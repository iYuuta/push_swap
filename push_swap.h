#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>
#include <limits.h>


typedef struct s_stack
{
	int			    data;
	int				index;
	int				chunk_index;
	struct s_stack	*next;
}			t_stack;

void	ft_error(void);
int check_sorted(t_stack *stack);
void sort_five(t_stack **stack1, t_stack **stack2);
void    sort_less_than_10(t_stack **stack1, t_stack **stack2);
void sort_three(t_stack **stack1);
int get_smallest(t_stack *a);
void sort_five(t_stack **stack1, t_stack **stack2);
void    sort_less_than_10(t_stack **stack1, t_stack **stack2);
void sort_three(t_stack **stack1);
t_stack *ft_parse_em(int ac, char **av);
void	ft_ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack  *ft_ft_lstnew(int content);
int	ft_ft_lstsize(t_stack *lst);
t_stack	*ft_ft_lstlast(t_stack *lst);
void chunk_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_ft_lstadd_back(t_stack **lst, t_stack *new);
int check_args(char **str, int index);
void sa_sb(t_stack **stack, char *str);
void pa_pb(t_stack **a, t_stack **b, char *str);
void ra_rb(t_stack **stack, char *str);
void rr_ab(t_stack **stack, char *str);
void	ft_error(void);

#endif