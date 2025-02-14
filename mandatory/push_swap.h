#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h>
#include <limits.h>


typedef struct s_stack
{
	int				data;
	int				index;
	int				sorted_index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}			t_stack;

void	ft_error(void);
void	clear_stack(t_stack *stack);
int		check_string(int ac, char **av);
void	free_mem(char ***ptr);
int		check_dup(t_stack *stack);
int		check_sorted(t_stack *stack);
void	sort_five(t_stack **stack1, t_stack **stack2);
void	sort_less_than_10(t_stack **stack1, t_stack **stack2);
void	sort_three(t_stack **stack1);
int		get_smallest(t_stack *a);
t_stack	*ft_parse_em(int ac, char **av);
t_stack	*ft_ft_lstnew(int content);
int		ft_ft_lstsize(t_stack *lst);
t_stack	*ft_ft_lstlast(t_stack *lst);
void	ft_ft_lstadd_back(t_stack **lst, t_stack *new);
int		check_args(char **str, int index);
void	sa_sb(t_stack **stack, char *str);
void	pa_pb(t_stack **a, t_stack **b, char *str);
void	ra_rb(t_stack **stack, char *str);
void	rr_ab(t_stack **stack, char *str);
void	final_check(t_stack **stack);
void	sorting_algo(t_stack **stack1, t_stack **stack2);
void	update_position(t_stack *stack);
void	find_cheapest(t_stack *stack);
void	push_cost(t_stack *stack1, t_stack *stack2);
t_stack	*get_cheapest(t_stack *stack);
void	rotate_both(t_stack **stack1, t_stack **stack2, t_stack *cheapest);
void	rev_rotate_both(t_stack **stack1, t_stack **stack2, t_stack *cheapest);
void	push_to_b(t_stack **stack1, t_stack **stack2);
void	push_to_a(t_stack **stack1, t_stack **stack2);
void	update_nodes_a(t_stack *stack1, t_stack *stack2);
void	update_nodes_b(t_stack **stack1, t_stack **stack2);
void	check_for_push(t_stack **stack, t_stack *cheapest, int operation);
void	chunk_em(t_stack **stack1, t_stack **satck2);

#endif