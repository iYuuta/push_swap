#include "push_swap.h"

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size && arr[j])
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*get_arr(t_stack *stack)
{
	int	*arr;
	int	i;
	int	size;

	size = ft_ft_lstsize(stack);
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i++] = stack->data;
		stack = stack->next;
	}
	sort_arr(arr, size);
	return (arr);
}

void	index_stack(t_stack *stack, int *arr, int size)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	while (i < size)
	{
		tmp = stack;
		while (tmp)
		{
			if (tmp->data == arr[i])
				tmp->sorted_index = i;
			tmp = tmp->next;
		}
		i++;
	}
}

t_stack *get_closest_node(t_stack *stack, int index)
{
	while (stack)
	{
		if (stack->sorted_index == index)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	sort_em(t_stack **stack1, t_stack **stack2)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	while (ft_ft_lstsize(*stack2))
	{
		update_position(*stack2);
		tmp = get_closest_node(*stack2, i);
		while (*stack2 != tmp)
		{
			if (tmp->above_median == 1)
				ra_rb(stack2, "rb\n");
			else
				rr_ab(stack2, "rrb\n");
		}
		pa_pb(stack2, stack1, "pa\n");
		i++;
	}
}

void	chunk_em(t_stack **stack1, t_stack **stack2)
{
	int	i;
	int	size;
	int	*arr;
	
	size = ft_ft_lstsize(*stack1);
	arr = get_arr(*stack1);
	i = 0;
	index_stack(*stack1, arr, size);
	while (i < size)
	{
		if ((*stack1)->sorted_index <= i)
		{
			pa_pb(stack1, stack2, "pb\n");
			i++;
		}
		else if ((*stack1)->sorted_index <= i * 34)
		{
			pa_pb(stack1, stack2, "pb\n");
			ra_rb(stack2, "ra\n");
			i++;
		}
		else
			ra_rb(stack1, "ra\n");
	}
	sort_em(stack1, stack2);
}
