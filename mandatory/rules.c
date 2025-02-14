/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoayedde <yoayedde@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 19:52:14 by yoayedde          #+#    #+#             */
/*   Updated: 2025-02-14 19:52:14 by yoayedde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_stack **stack, char *str)
{
	int	tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->data;
		(*stack)->data = (*stack)->next->data;
		(*stack)->next->data = tmp;
	}
	if (str)
		write(1, str, 3);
}

void	pa_pb(t_stack **stack1, t_stack **stack2, char *str)
{
	t_stack	*tmp;

	if (!stack1 || !*stack1)
		return ;
	tmp = *stack1;
	*stack1 = (*stack1)->next;
	tmp->next = *stack2;
	*stack2 = tmp;
	if (str)
		write(1, str, 3);
}

void	ra_rb(t_stack **stack, char *str)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	if (str)
		write(1, str, 3);
}

void	rr_ab(t_stack **stack, char *str)
{
	t_stack	*tmp;
	t_stack	*nd_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	nd_last = tmp;
	tmp = tmp->next;
	nd_last->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	if (str)
		write(1, str, 4);
}
