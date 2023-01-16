/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:59:11 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/16 16:19:02 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_content(t_list **stack_a)
{
	t_list	*tmp;
	int		max;

	tmp = (*stack_a);
	max = (*stack_a)->content;
	while ((*stack_a)->next)
	{
		(*stack_a) = (*stack_a)->next;
		if ((*stack_a)->content > max)
			max = (*stack_a)->content;
	}
	return (((*stack_a) = tmp), max);
}

int	i_max_content(t_list **stack_a)
{
	t_list	*tmp;
	int		i_max;
	int		max;

	tmp = (*stack_a);
	i_max = 0;
	max = (*stack_a)->content;
	while ((*stack_a)->next)
	{
		(*stack_a) = (*stack_a)->next;
		if ((*stack_a)->content > max)
		{
			max = (*stack_a)->content;
			i_max = (*stack_a)->index;
		}
	}
	return (((*stack_a) = tmp), i_max);
}

int	min_content(t_list **stack_a)
{
	t_list	*tmp;
	int		min;

	tmp = (*stack_a);
	min = (*stack_a)->content;
	while ((*stack_a)->next)
	{
		(*stack_a) = (*stack_a)->next;
		if (min > (*stack_a)->content)
			min = (*stack_a)->content;
	}
	(*stack_a) = tmp;
	return (min);
}

int	i_min_content(t_list **stack_a)
{
	t_list	*tmp;
	int		min;
	int		i_min;

	tmp = (*stack_a);
	min = (*stack_a)->content;
	i_min = 0;
	while ((*stack_a)->next)
	{
		(*stack_a) = (*stack_a)->next;
		if (min > (*stack_a)->content)
		{
			min = (*stack_a)->content;
			i_min = (*stack_a)->index;
		}
	}
	(*stack_a) = tmp;
	return (i_min);
}

int	small_node(t_list *stack_a)
{
	int	count;
	int	min;
	int	index_min;

	index_min = 0;
	min = stack_a->content;
	count = 0;
	while (stack_a->next)
	{
		if (min > (stack_a->next->content))
		{
			min = stack_a->next->content;
			index_min = count + 1;
		}
		count++;
		stack_a = stack_a->next;
	}
	return (index_min);
}
