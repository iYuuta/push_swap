#include "push_swap.h"
#include <stdio.h>

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

void    sort_less_than_10(t_stack **a, t_stack **b)
{
    int t;
    t_stack *temp;

    while (*a)
    {
        t = get_smallest(*a);
        temp = *a;
        while (temp->data != t)
        {
            ra_rb(a, 1);
            temp = *a;
        }
        pa_pb(b, a, 2);
    }

    while (*b)
        pa_pb(a, b, 1);
}

int main(int ac, char **av)
{
    t_stack *stack1;
    t_stack *stack2 = NULL;
    int len;

    if (ac < 2)
        return (0);
    stack1 = ft_parse_em(ac, av);
    if (!stack1)
        return (0);
    len = ft_ft_lstsize(stack1);
    if (len < 10)
        sort_less_than_10(&stack1, &stack2);
    while (stack1)
    {
        if (!stack1->next)
        {
            printf("%d\n", stack1->data);
            break;
        }
        printf("%d, ", stack1->data);
        stack1 = stack1->next;
    }
    return (0);
}