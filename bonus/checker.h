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
	int				sorted_index;
	int				above_median;
	struct s_stack	*next;
}			t_stack;

int		check_if_sorted(t_stack *stack);
int		check_move(char *str, char *move);
void	free_mem(char ***ptr);

t_stack	*ft_parse(int ac, char **av);

t_stack	*ft_ft_newlst(int content);
void	ft_ft_lstadd_back(t_stack **lst, t_stack *node);
int		ft_ft_lstsize(t_stack *lst);
t_stack	*ft_ft_lstlast(t_stack *lst);

void	clear_stack(t_stack *stack1, t_stack *stack2);
void	ft_error(void);
int		check_string(int ac, char **av);
int		check_args(char **str, int index);
int		check_dup(t_stack *stack);

char	*get_next_line(int fd);
int		check(char *str);
void	*free_em(char	**ptr1, char	**ptr2);
char	*duplicate(char	*str);

void	sa_sb(t_stack **stack, char *str);
void	pa_pb(t_stack **stack1, t_stack **stack2, char *str);
void	ra_rb(t_stack **stack, char *str);
void	rr_ab(t_stack **stack, char *str);
void	double_move(t_stack **stack1, t_stack **stack2, int move);

#endif
