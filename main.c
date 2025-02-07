#include "push_swap.h"
#include <stdio.h>

void	ft_error(void)
{	
	write (2, "Error\n", 6);
	exit(1);
}

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

int main(int ac, char **av)
{
    t_stack *stack1;
    t_stack *stack2 = NULL;
    int len;

    if (!check_args(av, ac))
        return (0);
    stack1 = ft_parse_em(ac, av);
    if (!stack1)
        return (0);
    if (!check_sorted(stack1))
        return (0);
    len = ft_ft_lstsize(stack1);
    if (len == 2)
        sa_sb(&stack1, "sa\n");
    else if (len == 3)
        sort_three(&stack1);
    else if (len <= 5)
        sort_five(&stack1, &stack2);
    else if (len < 10)
        sort_less_than_10(&stack1, &stack2);
    else if (len <= 100)
        chunk_sort(&stack1, &stack2);
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