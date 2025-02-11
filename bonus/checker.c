#include "checker.h"

void    ft_error(void)
{
    write(2, "Error\n", 7);
    exit(0);
}

void free_mem(char ***ptr)
{
    int    i;
    int    j;

    if (ptr == NULL || *ptr == NULL)
        return;
    i = -1;
    while (ptr[++i])
    {
        j = -1;
        while (ptr[i][++j])
            free(ptr[i][j]);
        free(ptr[i]);
    }
    free(ptr);
}

int	check_if_sorted(t_stack *stack)
{
    int	tmp;

	tmp = stack->data;
	stack = stack->next;
	while (stack)
	{
		if (tmp > stack->data)
			return (1);
		tmp = stack->data;
		stack = stack->next;
	}
	return (0);
}

int check_move(char *str, char *move)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == move[i])
			j++;	
		i++;
	}
	if (i == j)
		return (1);
	return (0);
}

void	preform_move(char *str, t_stack **stack1, t_stack **stack2)
{
	if (check_move(str, "pa\n"))
		pa_pb(stack2, stack1, NULL);
	else if (check_move(str, "pb\n"))
		pa_pb(stack1, stack2, NULL);
	else if (check_move(str, "sa\n"))
		sa_sb(stack1, NULL);
	else if (check_move(str, "sb\n"))
		sa_sb(stack2, NULL);
	else if (check_move(str, "ss\n"))
		double_move(stack1, stack2, 1);
	else if (check_move(str, "ra\n"))
		ra_rb(stack1, NULL);
	else if (check_move(str, "rra\n"))
		rr_ab(stack1, NULL);
	else if (check_move(str, "rr\n"))
		double_move(stack1, stack2, 2);
	else if (check_move(str, "rb\n"))
		ra_rb(stack2, NULL);
	else if (check_move(str, "rrb\n"))
		rr_ab(stack2, NULL);
	else if (check_move(str, "rrr\n"))
		double_move(stack1, stack2, 3);
	else
		printf("Error\n");
}

int main(int ac, char **av)
{
	char *str;
	t_stack *stack1;
	t_stack *stack2;

	stack1 = ft_parse(ac, av);
	str = get_next_line(0);
	while (str)
	{
		preform_move(str, &stack1, &stack2);
		free(str);
		str = get_next_line(0);
	}
	if (ft_ft_lstsize(stack2) != 0 || check_if_sorted(stack1))
		printf("KO\n");
	else if (!check_if_sorted(stack1))
		printf("OK\n");
}
