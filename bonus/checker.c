#include "checker.h"

void	preform_move(int move, t_stack **stack1, t_stack **stack2)
{
	if (move == 1)
		pa_pb(stack2, stack1, NULL);
	else if (move == 2)
		pa_pb(stack1, stack2, NULL);
	else if (move == 3)
		sa_sb(stack1, NULL);
	else if (move == 4)
		sa_sb(stack2, NULL);
	else if (move == 5)
		double_move(stack1, stack2, 1);
	else if (move == 6)
		ra_rb(stack1, NULL);
	else if (move == 7)
		rr_ab(stack1, NULL);
	else if (move == 8)
		double_move(stack1, stack2, 2);
	else if (move == 9)
		ra_rb(stack2, NULL);
	else if (move == 10)
		rr_ab(stack2, NULL);
	else if (move == 11)
		double_move(stack1, stack2, 3);
}

int	store_moves(t_stack *stack, char *str)
{
	if (check_move(str, "pa\n"))
		stack->data = 1;
	else if (check_move(str, "pb\n"))
		stack->data = 2;
	else if (check_move(str, "sa\n"))
		stack->data = 3;
	else if (check_move(str, "sb\n"))
		stack->data = 4;
	else if (check_move(str, "ss\n"))
		stack->data = 5;
	else if (check_move(str, "ra\n"))
		stack->data = 6;
	else if (check_move(str, "rra\n"))
		stack->data = 7;
	else if (check_move(str, "rr\n"))
		stack->data = 8;
	else if (check_move(str, "rb\n"))
		stack->data = 9;
	else if (check_move(str, "rrb\n"))
		stack->data = 10;
	else if (check_move(str, "rrr\n"))
		stack->data = 11;
	else
		return (write(2, "Error\n", 6), 0);
	return (1);
}

int	buffer_exe(t_stack **stack1, t_stack **stack2)
{
	char	*str;
	t_stack	*moves;
	t_stack	*tmp;

	moves = NULL;
	str = get_next_line(0);
	while (str)
	{
		tmp = ft_ft_newlst(0);
		if (!tmp)
			return (free(str), clear_stack(*stack1, moves), 1);
		ft_ft_lstadd_back(&moves, tmp);
		if (!store_moves(tmp, str))
			return (free(str), clear_stack(*stack1, moves), 1);
		free(str);
		str = get_next_line(0);
	}
	tmp = moves;
	while (moves && moves->data)
	{
		preform_move(moves->data, stack1, stack2);
		moves = moves->next;
	}
	return (clear_stack(tmp, NULL), 0);
}

int	main(int ac, char **av)
{
	t_stack	*stack1;
	t_stack	*stack2;

	stack2 = NULL;
	if (ac < 2)
		return (0);
	if (!check_args(av, ac) || !check_string(ac, av))
		return (write(1, "Error\n", 6), 1);
	stack1 = ft_parse(ac, av);
	if (!stack1)
		return (1);
	if (!check_dup(stack1))
		return (clear_stack(stack1, NULL), write(2, "Error\n", 6), 1);
	if (buffer_exe(&stack1, &stack2))
		return (1);
	if (ft_ft_lstsize(stack2) != 0 || check_if_sorted(stack1))
		write(1, "KO\n", 3);
	else if (!check_if_sorted(stack1))
		write(1, "OK\n", 3);
	return (clear_stack(stack1, stack2), 0);
}
