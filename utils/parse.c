#include "../push_swap.h"

void free_mem(char ***ptr)
{

}

t_stack	*ft_ft_lstnew(int content)
{
	t_stack	*strc;

	strc = malloc(sizeof(t_stack));
	if (!strc)
		return (NULL);
	strc->data = content;
	strc->next = NULL;
	return (strc);
}

char	*ft_join_args(char const *s1, char const *s2, int ac, int index)
{
	size_t	i;
	size_t	size;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (s1[0] == '\0' && s2[0] == '\0')
		return (ft_strdup("\0"));
	size = ft_strlen(s1) + ft_strlen(s2) + 2;
	i = 0;
	str = (char *)malloc((size) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = ' ';
	while (i < size)
		str[i++] = *s2++;
	str[i] = '\0';
    free((void*)s1);
	return (str);
}


void	ft_ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!lst || !new)
		return ;
	temp = *lst;
    if (temp)
    {
        while (temp->next)
            temp = temp->next;
    }
	if (temp)
	{
		temp->next = new;
		return ;
	}
	*lst = new;
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
            return (NULL);
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
    return (head);
}
