/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoayedde <yoayedde@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 19:48:22 by yoayedde          #+#    #+#             */
/*   Updated: 2025-02-14 19:48:22 by yoayedde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_atoi(const char *str, t_stack *stack)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i++] - 48);
	}
	if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
	{
		clear_stack(stack, NULL);
		ft_error();
	}
	return (result * sign);
}

void	free_mem(char ***ptr)
{
	int	i;
	int	j;

	if (ptr == NULL || *ptr == NULL)
		return ;
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

int	check_sorted(t_stack *stack)
{
	int	tmp;

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

char	***get_args(int ac, char **av)
{
	int		i;
	int		j;
	char	***args1;

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
	return (args1);
}

t_stack	*ft_parse(int ac, char **av)
{
	char	***args1;
	t_stack	*head;
	t_stack	*tmp;
	int		i;
	int		k;

	i = -1;
	head = NULL;
	args1 = get_args(ac, av);
	while (args1[++i])
	{
		k = 0;
		while (args1[i][k])
		{
			if (ft_strlen(args1[i][k]) > 11)
				return (free_mem(args1), write(2, "Error\n", 6), NULL);
			tmp = ft_ft_newlst(ft_atoi(args1[i][k], head));
			ft_ft_lstadd_back(&head, tmp);
			k++;
		}
	}
	if (!check_dup(head))
		return (write(2, "Error\n", 6), NULL);
	return (free_mem(args1), head);
}
