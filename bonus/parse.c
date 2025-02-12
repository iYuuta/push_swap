#include "checker.h"

int	check_sorted(t_stack *stack)
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

char	***get_args(int ac, char **av, int *j)
{
    int		i;
	char	***args1;

	i = 0;
	*j = 0;
	args1 = malloc(sizeof(char **) * (ac + 1));
	if (!args1)
		return (NULL);
	while (++i < ac)
	{
		args1[*j] = ft_split(av[i], ' ');
		if (!args1[*j])
			return (free_mem(args1), NULL);
		(*j)++;
	}
	args1[*j] = NULL;
	return (args1);
}

t_stack	*ft_parse(int ac, char **av)
{
	char	***args1;
	t_stack	*head;
	t_stack	*tmp;
	int		i;
	int		j;
	int		k;

	i = -1;
	head = NULL;
	args1 = get_args(ac, av, &j);
	while (args1[++i])
	{
		k = 0;
		while (args1[i][k])
		{
		if (ft_strlen(args1[i][k]) > 11)
			return (free_mem(args1), write(2, "Error\n", 6), NULL);
		tmp = ft_ft_newlst(ft_atoi(args1[i][k]));
		ft_ft_lstadd_back(&head, tmp);
		k++;
		}
	}
	if (!check_dup(head))
		return (write(2, "Error\n", 6), NULL);
	return (free_mem(args1), head);
}
