#include "checker.h"

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

int	check_move(char *str, char *move)
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

void	free_mem(char ***ptr)
{
	int	i;
	int	j;

	if (ptr == NULL || *ptr == NULL)
		return ;
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
