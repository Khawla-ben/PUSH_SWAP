/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:08:51 by kben-ham          #+#    #+#             */
/*   Updated: 2022/12/23 14:55:03 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	int	a;

	a = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = a;
}

void	rotate(t_list **stack)
{
	int		a;
	t_list	*tmp;

	tmp = *stack;
	a = (*stack)->content;
	while ((*stack)->next)
	{
		(*stack)->content = (*stack)->next->content;
		(*stack) = (*stack)->next;
	}
	(*stack)->content = a;
	(*stack) = tmp;
}

void	push(t_list	**stack_1, t_list **stack_2)
{
	t_list	*head;

	head = (*stack_1);
	*stack_1 = (*stack_1)->next;
	if (*stack_1)
		(*stack_1)->prev = NULL;
	head->next = NULL;
	ft_lstadd_front(stack_2, head);
}

void	rotate_reverse(t_list	**stack_1)
{
	int		a;
	t_list	*tmp;

	tmp = *stack_1;
	*stack_1 = ft_lstlast(*stack_1);
	a = (*stack_1)->content;
	while ((*stack_1)->prev)
	{
		(*stack_1)->content = (*stack_1)->prev->content;
		(*stack_1) = (*stack_1)->prev;
	}
	(*stack_1)->content = a;
	(*stack_1) = tmp;
}

void	rrr(t_list	**stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
