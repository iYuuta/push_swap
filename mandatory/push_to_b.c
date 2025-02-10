#include "../push_swap.h"

t_stack	*find_largest_value(t_stack *stack)
{
	long	max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->data > max)
		{
			max = stack->data;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);;
}

void	set_target_a(t_stack *stack1, t_stack *stack2)
{
	long	best_match;
	t_stack	*target;
	t_stack	*current_b_node;

	while (stack1)
	{
		best_match = LONG_MIN;
		current_b_node = stack2;
		while (current_b_node)
		{
			if (current_b_node->data < stack1->data && current_b_node->data > best_match)
			{
				best_match = current_b_node->data;
				target = current_b_node;
			}
			current_b_node = current_b_node->next;
		}
		if (best_match == LONG_MIN)
			stack1->target = find_largest_value(stack2);
		else
			stack1->target = target;
		stack1 = stack1->next;
	}
}

void	update_nodes_a(t_stack *stack1, t_stack *stack2)
{
	update_position(stack1);
	update_position(stack2);
	set_target_a(stack1, stack2);
	push_cost(stack1, stack2);
	find_cheapest(stack1);
}

void	push_to_b(t_stack **stack1, t_stack **stack2)
{
	t_stack *cheapest;

	cheapest = get_cheapest(*stack1);
	if (cheapest->above_median == 1 && cheapest->target->above_median == 1)
		rotate_both(stack1, stack2, cheapest);
	else if (cheapest->above_median == 0 && cheapest->target->above_median == 0)
		rev_rotate_both(stack1, stack2, cheapest);
	check_for_push((stack1), cheapest, 1);
	check_for_push((stack2), cheapest->target, 0);
	pa_pb(stack1, stack2, "pb\n");
}
