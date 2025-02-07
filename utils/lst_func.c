#include "../push_swap.h"

t_stack	*ft_ft_lstnew(int content)
{
	t_stack	*strc;

	strc = malloc(sizeof(t_stack));
	if (!strc)
		return (NULL);
	strc->data = content;
	strc->next = NULL;
	strc->above_median = 0;
	strc->target_node = NULL;
	strc->cheapest = 0;
	strc->index = 0;
	strc->push_cost = 0;
	return (strc);
}

void	ft_ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!lst || !new)
		return ;
	temp = ft_ft_lstlast(*lst);
	if (temp)
	{
		temp->next = new;
		new->prev = temp;
		new->index = temp->index + 1;
	}
	else
	{
		*lst = new;
		new->prev = NULL;
		new->index = 0;
	}
}


int	ft_ft_lstsize(t_stack *lst)
{
	int		size;
	t_stack	*temp;

	size = 0;
	if (!lst)
		return (0);
	temp = lst;
	while (temp != NULL)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

t_stack	*ft_ft_lstlast(t_stack *lst)
{
	t_stack	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}
