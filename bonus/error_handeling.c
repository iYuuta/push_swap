#include "checker.h"

void	clear_stack(t_stack *stack1, t_stack *stack2)
{
	t_stack	*tmp;

	if (stack1)
	{
		while (stack1)
		{
			tmp = stack1;
			stack1 = stack1->next;
			free(tmp);
		}
	}
	if (stack2)
		clear_stack(stack2, NULL);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	check_string(int ac, char **av)
{
	int	i;
	int	j;
	int	nbr;

	j = 0;
	while (++j < ac)
	{
		i = -1;
		nbr = 0;
		while (av[j][++i])
		{
			if (ft_isdigit(av[j][i]))
				nbr = 1;
		}
		if (nbr == 0)
			return (0);
	}
	return (1);
}

int	check_args(char **str, int index)
{
	int	i;
	int	j;

	i = 0;
	while (++i < index)
	{
		j = -1;
		if (str[i][0] == '\0')
			return (0);
		while (str[i][++j])
		{
			if ((!ft_isdigit(str[i][j])) && str[i][j] != ' '
				&& str[i][j] != '-' && str[i][j] != '+')
				return (0);
			if (j > 0 && str[i][j - 1] && (str[i][j] == '-'
				|| str[i][j] == '+') && str[i][j - 1] != ' ')
				return (0);
			if ((str[i][j] == '-' || str[i][j] == '+')
				&& (!str[i][++j] || !ft_isdigit(str[i][j])))
				return (0);
		}
	}
	return (1);
}

int	check_dup(t_stack *stack)
{
	t_stack	*tmp;	
	t_stack	*head;
	int		data1;
	int		data2;

	head = stack;
	while (head)
	{
		tmp = head->next;
		data1 = head->data;
		while (tmp)
		{
			data2 = tmp->data;
			if (data1 == data2)
				return (0);
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (1);
}
