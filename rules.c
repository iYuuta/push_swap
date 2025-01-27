#include "push_swap.h"

void sa_sb(t_stack **stack, int M)
{
    int tmp;

    if (*stack && (*stack)->next)
    {
        tmp = (*stack)->data;
        (*stack)->data = (*stack)->next->data;
        (*stack)->next->data = tmp;
    }
    if (M == 1)
        write(1, "sa\n", 3);
    if (M == 2)
        write(1, "sb\n", 3);
    if (M == 3)
        write(1, "sa\n", 3);
}

void pa_pb(t_stack **a, t_stack **b, int M)
{
    t_stack *last;
    t_stack *tmp;

    if (!*b)
        return;
    tmp = *b;
    *b = (*b)->next;
    tmp->next = *a;
    *a = tmp;
    if (M == 1)
        write(1, "pa\n", 3);
    if (M == 2)
        write(1, "pb\n", 3);
}

void ra_rb(t_stack **stack, int M)
{
    t_stack *tmp;
    t_stack *last;

    if (!stack || !(*stack) || !(*stack)->next)
        return;
    tmp = *stack;
    last = ft_ft_lstlast(*stack);
    *stack = (*stack)->next;
    last->next = tmp;
    tmp->next = NULL;
    if (M == 1)
        write(1, "ra\n", 3);
    if (M == 2)
        write(1, "rb\n", 3);
    if (M == 3)
        write(1, "rr\n", 3);
}

void rr_ab(t_stack **stack, int M)
{
    t_stack *tmp;
    t_stack *nd_last;

    if (!stack || !(*stack) || !(*stack)->next)
        return;
    tmp = *stack;
    while (tmp->next && tmp->next->next)
        tmp = tmp->next;
    nd_last = tmp;
    tmp = tmp->next;
    nd_last->next = NULL;
    tmp->next = *stack;
    *stack = tmp;
    if (M == 1)
        write(1, "rra\n", 4);
    if (M == 2)
        write(1, "rrb\n", 4);
    if (M == 3)
        write(1, "rrr\n", 4);
}