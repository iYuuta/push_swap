#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack1;
	t_stack	*stack2;
	int		len;

	stack2 = NULL;
	if (ac < 2)
		return (0);
	if (!check_args(av, ac) || !check_string(ac, av))
		return (write(2, "Error\n", 6), 1);
	stack1 = ft_parse_em(ac, av);
	if (!stack1)
		return (1);
	if (!check_sorted(stack1))
		return (clear_stack(stack1), 0);
	len = ft_ft_lstsize(stack1);
	if (len == 2)
		sa_sb(&stack1, "sa\n");
	else if (len == 3)
		sort_three(&stack1);
	else if (len <= 5)
		sort_five(&stack1, &stack2);
	else
		chunk_em(&stack1, &stack2);
	return (clear_stack(stack1), 0);
}
