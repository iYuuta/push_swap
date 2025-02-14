#include "push_swap.h"

t_stack	*find_smallest(t_stack *a)
{
	t_stack	*t;
	t_stack	*temp;

	temp = a;
	t = a;
	while (temp)
	{
		if (t->data > temp->data)
			t = temp;
		temp = temp->next;
	}
	return (t);
}

void	sort_three(t_stack **stack1)
{
	if ((*stack1)->next == find_smallest(*stack1)
		&& (*stack1)->data < (*stack1)->next->next->data)
		sa_sb(stack1, "sa\n");
	else if ((*stack1)->data > (*stack1)->next->data
		&& (*stack1)->next->data > (*stack1)->next->next->data)
	{
		sa_sb(stack1, "sa\n");
		rr_ab(stack1, "rra\n");
	}
	else if ((*stack1)->data > (*stack1)->next->next->data
		&& find_smallest(*stack1) == (*stack1)->next)
		ra_rb(stack1, "ra\n");
	else if (find_smallest(*stack1) == *stack1
		&& (*stack1)->next->data > (*stack1)->next->next->data)
	{
		sa_sb(stack1, "sa\n");
		ra_rb(stack1, "ra\n");
	}
	else if (find_smallest(*stack1) == (*stack1)->next->next
		&& (*stack1)->data < (*stack1)->next->data)
		rr_ab(stack1, "rra\n");
}

void	sort_five(t_stack **stack1, t_stack **stack2)
{
	t_stack	*tmp;

	update_position(*stack1);
	while (ft_ft_lstsize(*stack1) > 3)
	{
		tmp = find_smallest(*stack1);
		if ((*stack1) == tmp)
			pa_pb(stack1, stack2, "pb\n");
		else if (tmp->above_median == 1)
			ra_rb(stack1, "ra\n");
		else
			rr_ab(stack1, "rra\n");
	}
	sort_three(stack1);
	pa_pb(stack2, stack1, "pa\n");
	pa_pb(stack2, stack1, "pa\n");
}
