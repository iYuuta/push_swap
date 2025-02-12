#include "push_swap.h"

void sort_three(t_stack **stack1)
{
	if ((*stack1)->next->data == get_smallest(*stack1) && (*stack1)->data < (*stack1)->next->next->data)
		sa_sb(stack1,"sa\n");
	else if ((*stack1)->data > (*stack1)->next->data && (*stack1)->next->data > (*stack1)->next->next->data)
	{
		sa_sb(stack1, "sa\n");
		rr_ab(stack1, "rra\n");
	}
	else if ((*stack1)->data > (*stack1)->next->next->data && get_smallest(*stack1) == (*stack1)->next->data)
		ra_rb(stack1, "ra\n");
	else if (get_smallest(*stack1) == (*stack1)->data && (*stack1)->next->data > (*stack1)->next->next->data)
	{
		sa_sb(stack1, "sa\n");
		ra_rb(stack1, "ra\n");
	}
	else if (get_smallest(*stack1) == (*stack1)->next->next->data && (*stack1)->data < (*stack1)->next->data)
		rr_ab(stack1, "rra\n");
}

void sort_five(t_stack **stack1, t_stack **stack2)
{
	while (ft_ft_lstsize(*stack1) > 3)
	{
		if ((*stack1)->data == get_smallest(*stack1))
			pa_pb(stack1, stack2, "pb\n");
		else
			ra_rb(stack1, "ra\n");
	}
	sort_three(stack1);
	pa_pb(stack2, stack1, "pa\n");
	pa_pb(stack2, stack1, "pa\n");
}

void	sort_less_than_10(t_stack **stack1, t_stack **stack2)
{
	int t;
	t_stack *temp;

	while (ft_ft_lstsize(*stack1) > 5)
	{
		t = get_smallest(*stack1);
		temp = *stack1;
		while (temp->data != t)
		{
			ra_rb(stack1, "ra\n");
			temp = *stack1;
		}
		pa_pb(stack1, stack2, "pb\n");
	}
	sort_five(stack1, stack2);
	while (*stack2)
		pa_pb(stack2, stack1, "pa\n");
}
