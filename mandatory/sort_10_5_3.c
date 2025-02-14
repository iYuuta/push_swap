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
