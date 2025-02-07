#include "push_swap.h"

void sa_sb(t_stack **stack, char *str)
{
    int tmp;
    t_stack *temp;

    if (*stack && (*stack)->next)
    {
        temp = (*stack)->prev;
        tmp = (*stack)->data;
        (*stack)->data = (*stack)->next->data;
        (*stack)->prev = (*stack)->next->prev;
        (*stack)->next->prev = temp;
        (*stack)->next->data = tmp;
    }
    if (str)
        write(1, str, 3);
}

void pa_pb(t_stack **stack1, t_stack **stack2, char *str)
{
    t_stack *tmp;

    if (!stack1 || !*stack1)
        return;
    tmp = *stack1;
    *stack1 = (*stack1)->next;
    if (*stack1)
        (*stack1)->prev = NULL;
    tmp->next = *stack2;
    if (*stack2)
        (*stack2)->prev = tmp;
    *stack2 = tmp;
    tmp->prev = NULL;
    if (str)
        write(1, str, 3);
}

void ra_rb(t_stack **stack, char *str)
{
    t_stack *tmp;
    t_stack *last;

    if (!stack || !(*stack) || !(*stack)->next)
        return;
    tmp = *stack;
    last = ft_ft_lstlast(*stack);
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last->next = tmp;
    tmp->prev = last;
    tmp->next = NULL;
    if (str)
        write(1, str, 3);
}

void rr_ab(t_stack **stack, char *str)
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
    (*stack)->prev = tmp;
    *stack = tmp;
    tmp->prev = NULL;
    if (str)
        write(1, str, 4);
}