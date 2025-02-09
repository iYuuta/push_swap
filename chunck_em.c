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

int *get_arr(t_stack *stack, int size)
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
    sort_arr(&arr, size);
    return arr;
}

void index_stack(t_stack *stack, int *arr, int size)
{
    int i;
    t_stack *tmp;

    i = 0;
    while (i < size)
    {
        tmp = stack;
        while (tmp && i < size)
        {
            if (tmp->data == arr[i])
                tmp->index = i++;
            tmp = tmp->next;
        }
    }
}

void    update_position(t_stack *stack, int *arr, int chunk, int size)
{
    int i;
    int j;
    t_stack *tmp;

    i = 0;
    j = 1;
    while (i < size)
    {
        while (i < j * chunk && i < size)
        {
            tmp = stack;
            while (tmp)
            {
                if (tmp->data == arr[i])
                {
                    tmp->chunk_index = j;
                    i++;
                    break;
                }
                tmp = tmp->next;
            }
        }
        j++;
    }
}

int get_chunks(int *arr, t_stack *stack, int size)
{
    int chunk_size;

    if (size < 200)
        chunk_size = 16;
    else
        chunk_size = 34;
    update_position(stack, arr, chunk_size, size);
    index_stack(stack, arr, size);
    return (chunk_size);
}

int decide_direction(t_stack *tmp, int index, int size)
{
    int i;

    i = 0;
    while (tmp)
    {
        if (tmp->index == index)
            break;
        i++;
        tmp = tmp->next;
    }
    if (i < size / 2)
        return (1);
    return (0);
}

void chunk_sort(t_stack **stack1, t_stack **stack2)
{
    int chunk_size;
    int stack_size;
    int *arr;
    int i;
    int j;
    int k;

    stack_size = ft_ft_lstsize(*stack1);
    arr = get_arr(*stack1, stack_size);
    chunk_size = get_chunks(arr, *stack1, stack_size);
    i = 0;
    j = 1;
    while (i < stack_size)
    {
        while (i < chunk_size * j && i < stack_size)
        {
            if ((*stack1)->chunk_index == j)
            {
                pa_pb(stack1, stack2, "pb\n");
                i++;
            }
            else
                ra_rb(stack1, "ra\n");
        }
        j++;
    }
    i = stack_size - 1;;
    while (i >= 0)
    {
        if ((*stack2)->index == i)
        {
            pa_pb(stack2, stack1, "pa\n");
            i--;
        }
        else if (!decide_direction(*stack2, i, stack_size))
            rr_ab(stack2, "rrb\n");
        else
            ra_rb(stack2, "rb\n");
    }
    // while (*stack2)
    // {
    //     printf("data->%d   :chunk index%d  :index%d\n", (*stack2)->data, (*stack2)->chunk_index, (*stack2)->index);
    //     (*stack2) = (*stack2)->next;
    // }
}
