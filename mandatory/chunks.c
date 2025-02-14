#include "push_swap.h"

void	sort_em(t_stack **stack1, t_stack **stack2)
{
	t_stack	*tmp;

	while (ft_ft_lstsize(*stack2))
	{
		update_position(*stack2);
		tmp = get_biggest_node(*stack2);
		while (*stack2 != tmp)
		{
			if (tmp->above_median == 1)
				ra_rb(stack2, "rb\n");
			else
				rr_ab(stack2, "rrb\n");
		}
		pa_pb(stack2, stack1, "pa\n");
	}
}

void	update_index(t_stack *lst)
{
	t_stack	*head;
	t_stack	*tmp;

	head = lst;
	tmp = head;
	while (head)
	{
		while (lst)
		{
			if (head->data > lst->data)
				head->sorted_index++;
			lst = lst->next;
		}
		lst = tmp;
		head = head->next;
	}
}

void	final_check(t_stack **stack)
{
	t_stack	*tmp;

	tmp = find_smallest_value(*stack);
	if (tmp->above_median == 1)
	{
		while (*stack != tmp)
			ra_rb(stack, "ra\n");
	}
	else if (tmp->above_median == 0)
	{
		while (*stack != tmp)
			rr_ab(stack, "rra\n");
	}
}

void	cut_em(t_stack **stack1, t_stack **stack2, int chunk_size)
{
	int	i;
	int	direction;
	int	size;

	i = 0;
	size = ft_ft_lstsize(*stack1);
	direction = check_biggest_subsequence(*stack1);
	update_index(*stack1);
	while (*stack1)
	{
		if ((*stack1)->sorted_index <= i)
		{
			pa_pb(stack1, stack2, "pb\n");
			i++;
		}
		else if ((*stack1)->sorted_index < i + chunk_size)
		{
			pa_pb(stack1, stack2, "pb\n");
			ra_rb(stack2, "rb\n");
			i++;
		}
		else if (direction >= size / 3)
			rr_ab(stack1, "rra\n");
		else
			ra_rb(stack1, "ra\n");
	}
}

void	chunk_em(t_stack **stack1, t_stack **stack2)
{
	int	size;
	int	chunk_size;

	chunk_size = 20;
	size = ft_ft_lstsize(*stack1);
	if (size > 200)
		chunk_size = 35;
	cut_em(stack1, stack2, chunk_size);
	sort_em(stack1, stack2);
	final_check(stack1);
}
