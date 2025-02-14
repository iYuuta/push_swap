#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				sorted_index;
	int				above_median;
	int				index;
	struct s_stack	*next;
}			t_stack;

t_stack	*ft_ft_lstlast(t_stack *lst);
int		ft_ft_lstsize(t_stack *lst);
void	ft_ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_ft_lstnew(int content);

void	sa_sb(t_stack **stack, char *str);
void	pa_pb(t_stack **a, t_stack **b, char *str);
void	ra_rb(t_stack **stack, char *str);
void	rr_ab(t_stack **stack, char *str);

int		check_args(char **str, int index);
int		check_string(int ac, char **av);
int		check_sorted(t_stack *stack);
t_stack	*ft_parse_em(int ac, char **av);
int		check_dup(t_stack *stack);

void	sort_three(t_stack **stack1);
void	sort_five(t_stack **stack1, t_stack **stack2);
void	chunk_em(t_stack **stack1, t_stack **stack2);

void	update_position(t_stack *stack);
t_stack	*find_smallest_value(t_stack *stack);
t_stack	*get_biggest_node(t_stack *stack);
int	check_biggest_subsequence(t_stack *stack);
void	clear_stack(t_stack *stack);
void	free_mem(char ***ptr);
void	ft_error(void);

#endif