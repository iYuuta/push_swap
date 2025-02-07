#include "../push_swap.h"

int check_sorted(t_stack *stack)
{
    int tmp;

    tmp = stack->data;
    stack = stack->next;
    while (stack)
    {
        if (tmp > stack->data)
            return (1);
        tmp = stack->data;
        stack = stack->next;
    }
    return (0);
}

int check_args(char **str, int index)
{
    int i;
    int j;

    i = 0;
    while (++i < index)
    {
        j = -1;
        if (str[i][0] == '\0')
            return (write(2, "Error\n", 7), 0);
        while (str[i][++j])
        {
            if ((str[i][j] < '0' || str[i][j] > '9') && str[i][j] != ' ' && str[i][j] != '-' && str[i][j] != '+')
                return (write(2, "Error\n", 7), 0);
            if (j > 0 && str[i][j - 1] && (str[i][j] == '-' || str[i][j] == '+') && str[i][j - 1] != ' ')
                return (write(2, "Error\n", 7), 0);
            if ((str[i][j] == '-' || str[i][j] == '+') && (!str[i][++j] || str[i][j] < '0' || str[i][j] > '9'))
                return (write(2, "Error\n", 7), 0);
        }
    }
    return (1);
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

int    check_dup(t_stack *stack)
{
    t_stack    *tmp;    
    t_stack    *head;
    int        data1;
    int        data2;

    head = stack;
    while (head)
    {
        tmp = head->next;
        data1 = head->data;
        while (tmp)
        {
            data2 = tmp->data;
            if (data1 == data2)
                return (0);
            tmp = tmp->next;
        }
        head = head->next;
    }
    return (1);
}

t_stack *ft_parse_em(int ac, char **av)
{
    int i, j;
    t_stack *head = NULL;
    t_stack *tmp;
    char ***args1;

    i = 0;
    j = 0;
    args1 = malloc(sizeof(char **) * (ac + 1));
    if (!args1)
        return (NULL);
    while (++i < ac)
    {
        args1[j] = ft_split(av[i], ' ');
        if (!args1[j])
            return (free_mem(args1), NULL);
        j++;
    }
    args1[j] = NULL;
    i = 0;
    while (i < j)
    {
        int k = 0;
        while (args1[i][k])
        {
            tmp = ft_ft_lstnew(ft_atoi(args1[i][k]));
            ft_ft_lstadd_back(&head, tmp);
            k++;
        }
        i++;
    }
    if (!check_dup(head))
        return (write(1, "Error\n", 7), NULL);
    return (head);
}
