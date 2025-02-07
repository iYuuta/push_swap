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

int is_in_chunk(int *arr, int nb, int y, int x)
{
    while (y < x)
    {
        if (nb == arr[y])
            return (1);
        y++;
    }
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
    if (stack_size < 200)
        chunk_size = stack_size / 10;
    else
        chunk_size = stack_size / 5;

    arr = get_chunks(*stack1, stack_size);
    j = chunk_size;
    printf("chunk_size: %d\n", chunk_size);
    k = 0;
    i = 0;
    while (i < stack_size)
    {
        while (k < j && i < stack_size)
        {
            if (is_in_chunk(arr, (*stack1)->data, i, j))
            {
                pa_pb(stack1, stack2, "pb\n");
                k++;
            }
            else
                ra_rb(stack1, "ra\n");
        }
        j += chunk_size;
    }
    free(arr);
}