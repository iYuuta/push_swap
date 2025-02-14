#include "push_swap.h"

t_stack *get_last_node(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (stack)
	{
		if (stack->sorted_index > tmp->sorted_index)
			tmp = stack;
		stack = stack->next;
	}
	return (tmp);
}

void	sort_em(t_stack **stack1, t_stack **stack2)
{
	t_stack	*tmp;

	while (ft_ft_lstsize(*stack2))
	{
		update_position(*stack2);
		tmp = get_last_node(*stack2);
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

void	retarded_update_index(t_stack *lst)
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

void	chunk_em(t_stack **stack1, t_stack **stack2)
{
	int	i;
	int	size;
	int	*arr;
	
	size = ft_ft_lstsize(*stack1);
	i = 0;
	retarded_update_index(*stack1);
	while (*stack1)
	{
		if ((*stack1)->sorted_index <= i)
		{
			pa_pb(stack1, stack2, "pb\n");
			i++;
		}
		else if ((*stack1)->sorted_index < i + 34)
		{
			pa_pb(stack1, stack2, "pb\n");
			ra_rb(stack2, "rb\n");
			i++;
		}
		else
		 	ra_rb(stack1, "ra\n");
	}
	sort_em(stack1, stack2);
	final_check(stack1);
}
