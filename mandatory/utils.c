#include "push_swap.h"

int	check_biggest_subsequence(t_stack *stack)
{
	int	descending;
	int	i;

	i = 0;
	descending = 0;
	while (i < ft_ft_lstsize(stack) / 2)
	{
		if (stack->next && stack->data > stack->next->data)
			descending++;
		else
			descending--;
		i++;
		stack = stack->next;
	}
	return (descending);
}

void	free_mem(char ***ptr)
{
	int	i;
	int	j;

	if (*ptr == NULL || **ptr == NULL || ptr == NULL)
		return ;
	i = -1;
	while (ptr[++i])
	{
		j = -1;
		while (ptr[i] && ptr[i][++j])
			free(ptr[i][j]);
		free(ptr[i]);
	}
	free(ptr);
}

void	update_position(t_stack *stack)
{
	int	index;
	int	median;

	if (!stack)
		return ;
	median = ft_ft_lstsize(stack) / 2;
	index = 0;
	while (stack)
	{
		stack->index = index;
		if (index <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		index++;
	}
}

t_stack	*find_smallest_value(t_stack *stack)
{
	long	min;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*get_biggest_node(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (stack)
	{
		if (stack->sorted_index > tmp->sorted_index)
			tmp = stack;
		stack = stack->next;
	}
	return (tmp);
}
