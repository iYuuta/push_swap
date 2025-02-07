#include "push_swap.h"

void sort_arr(int **arr, int size)
{
    int i;
    int j;
    int tmp1;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if ((*arr)[i] > (*arr)[j])
            {
                tmp1 = (*arr)[i];
                (*arr)[i] = (*arr)[j];
                (*arr)[j] = tmp1;
            }
            j++;
        }
        i++;
    }
}

void    current_index(t_stack *stack)
{
    int i;
    int median;

    i = 0;
    median = ft_ft_lstsize(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if (i <= median)
            stack->above_median = 1;
        else
            stack->above_median = 0;
        stack = stack->next;
        i++;
    }
}

int *get_chunks(t_stack *stack, int size)
{
    int *arr;
    int i;
    t_stack *tmp;

    arr = malloc(sizeof(int) * size);
    if (!arr)
        return (0);
    tmp = stack;
    i = 0;
    while (tmp && i < size)
    {
        arr[i] = tmp->data;
        tmp = tmp->next;
        i++;
    }
    i = 0;
    sort_arr(&arr, size);
    return arr;
}

int get_largest(t_stack *a)
{
    int     t;
    t_stack *temp;

    temp = a;
    t = a->data;
    while (temp)
    {
        if (t < temp->data)
            t = temp->data;
        temp = temp->next;
    }
    return (t);
}

void    get_target(t_stack *stack1, t_stack *stack2)
{
    t_stack *current;
    t_stack *target;
    long best_match;

    while (stack1)
    {
        best_match = LONG_MIN;
        current = stack2;
        while (current)
        {
            if (current->data < stack1->data &&
                current->data > best_match)
                {
                    best_match = current->data;
                    target = current;
                }
                current = current->next;
        }
        if (best_match == LONG_MIN)
            stack1->target_node = get_largest(stack2);
        else
            stack1->target_node = target;
        stack1 = stack1->next;
    }
}
void    update_info(t_stack **stack1, t_stack **stack2)
{
    current_index(*stack1);
    current_index(*stack2);
    get_target(*stack1, *stack2);
}

void	algorithm_shayt(t_stack **stack1, t_stack **stack2)
{
	int smallest;
	int biggest;

	smallest = get_smallest(*stack1);
	biggest = get_largest(*stack1);
    pa_pb(stack1, stack2, "pb\n");
    pa_pb(stack1, stack2, "pb\n");
}