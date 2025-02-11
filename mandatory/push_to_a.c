#include "push_swap.h"

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
	return (max_node);;
}

void	set_target_b(t_stack *stack1, t_stack *stack2)
{
	long	best_match;
	t_stack	*target;
	t_stack	*current_a_node;

	while (stack2)
	{
		best_match = LONG_MAX;
		current_a_node = stack1;
		while (current_a_node)
		{
			if (current_a_node->data > stack2->data && current_a_node->data < best_match)
			{
				best_match = current_a_node->data;
				target = current_a_node;
			}
			current_a_node = current_a_node->next;
		}

		if (best_match == LONG_MAX)
			stack2->target = find_smallest_value(stack1);
		else
			stack2->target = target;

		stack2 = stack2->next;
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

void	update_nodes_b(t_stack **stack1, t_stack **stack2)
{
	update_position(*stack1);
	update_position(*stack2);
	set_target_b(*stack1, *stack2);
}

void	push_to_a(t_stack **stack1, t_stack **stack2)
{
	check_for_push(stack1, (*stack2)->target, 1);
	pa_pb(stack2, stack1, "pa\n");
}