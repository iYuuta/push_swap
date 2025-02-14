#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_stack
{
	int				data;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}			t_stack;

void	ft_error(void);
int		ft_atoi(const char *str, t_stack *stack);
void	clear_stack(t_stack *stack1, t_stack *stack2);
int		check_string(int ac, char **av);
int		check_args(char **str, int index);
int		check_dup(t_stack *stack);
char	*duplicate(char *str);
void	*free_em(char **ptr1, char **ptr2);
void	free_mem(char ***ptr);
int		check(char *str);
char	*get_next_line(int fd);
t_stack	*ft_parse(int ac, char **av);
t_stack	*ft_ft_newlst(int content);
int		ft_ft_lstsize(t_stack *lst);
t_stack	*ft_ft_lstlast(t_stack *lst);
void	ft_ft_lstadd_back(t_stack **lst, t_stack *node);
void	sa_sb(t_stack **stack, char *str);
void	pa_pb(t_stack **a, t_stack **b, char *str);
void	ra_rb(t_stack **stack, char *str);
void	rr_ab(t_stack **stack, char *str);
void	double_move(t_stack **stack1, t_stack **stack2, int move);

#endif
