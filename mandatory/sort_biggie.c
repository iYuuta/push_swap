#include "push_swap.h"

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

void	push_cost(t_stack *stack1, t_stack *stack2)
{
	int	stack1_len;
	int	stack2_len;

	stack1_len = ft_ft_lstsize(stack1);
	stack2_len = ft_ft_lstsize(stack2);
	while (stack1)
	{
		stack1->push_cost = stack1->index;
		if (!(stack1->above_median))
			stack1->push_cost = stack1_len - (stack1->index);
		if (stack1->target->above_median)
			stack1->push_cost += stack1->target->index;
		else
			stack1->push_cost += stack2_len - (stack1->target->index);
		stack1 = stack1->next;
	}
}

void	check_for_push(t_stack **stack, t_stack *cheapest, int operation)
{
	while (*stack != cheapest)
	{
		if (operation == 1)
		{
			if (cheapest->above_median == 1)
				ra_rb(stack, "ra\n");
			else
				rr_ab(stack, "rra\n");
		}
		else
		{
			if (cheapest->above_median == 1)
				ra_rb(stack, "rb\n");
			else
				rr_ab(stack, "rrb\n");
		}
	}
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	sorting_algo(t_stack **stack1, t_stack **stack2)
{
	int	a_len;

	a_len = ft_ft_lstsize(*stack1);
	if (a_len > 3)
		pa_pb(stack1, stack2, "pb\n");
	if (a_len > 3)
		pa_pb(stack1, stack2, "pb\n");
	while (ft_ft_lstsize(*stack1) > 3)
	{
		update_nodes_a(*stack1, *stack2);
		push_to_b(stack1, stack2);
	}
	sort_three(stack1);
	while (*stack2)
	{
		update_nodes_b(stack1, stack2);
		push_to_a(stack1, stack2);
	}
	update_position(*stack1);
	final_check(stack1);
}