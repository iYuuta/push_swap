#include "../push_swap.h"

int get_smallest(t_stack *a)
{
    int     t;
    t_stack *temp;

    temp = a;
    t = a->data;
    while (temp)
    {
        if (t > temp->data)
            t = temp->data;
        temp = temp->next;
    }
    return (t);
}

void free_mem(char ***ptr)
{
    int    i;
    int    j;

    if (ptr == NULL || *ptr == NULL)
        return;
    i = -1;
    while (ptr[++i])
    {
        j = -1;
        while (ptr[i][++j])
            free(ptr[i][j]);
        free(ptr[i]);
    }
    free(ptr);
}

void	rotate_both(t_stack **stack1, t_stack **stack2, t_stack *cheapest)
{
	while (*stack2 != cheapest->target && *stack1 != cheapest)
	{
		ra_rb(stack1, "rr\n");
		ra_rb(stack2, NULL);
	}
	update_position(*stack1);
	update_position(*stack2);
}

void	rev_rotate_both(t_stack **stack1, t_stack **stack2, t_stack *cheapest)
{
	while (*stack2 != cheapest->target && *stack1 != cheapest)
	{
		rr_ab(stack1, "rrr\n");
		rr_ab(stack2, NULL);
	}
	update_position(*stack1);
	update_position(*stack2);
}

void	find_cheapest(t_stack *stack)
{
	long	least_moves;
	t_stack	*cheapest;

	if (!stack)
		return ;
	least_moves = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < least_moves)
		{
			least_moves = stack->push_cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	cheapest->cheapest = 1;
}
