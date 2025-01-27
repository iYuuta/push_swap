#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>


typedef struct s_stack
{
	int			    data;
	struct s_stack	*next;
}			t_stack;

t_stack *ft_parse_em(int ac, char **av);
void	ft_ft_lstadd_front(t_stack **lst, t_stack *new);
int	ft_ft_lstsize(t_stack *lst);
t_stack	*ft_ft_lstlast(t_stack *lst);
void	ft_ft_lstadd_back(t_stack **lst, t_stack *new);
void sa_sb(t_stack **stack, int M);
void pa_pb(t_stack **a, t_stack **b, int M);
void ra_rb(t_stack **stack, int M);
void rr_ab(t_stack **stack, int M);

#endif