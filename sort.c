/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:34:11 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/02 09:07:32 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	put_index(t_list **stack_a)
{
	t_list	*tmp;

	tmp = (*stack_a);
	while ((*stack_a)->next)
	{
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->index = (*stack_a)->prev->index + 1 ;
	}
	(*stack_a)->index = (*stack_a)->prev->index + 1 ;
	(*stack_a) = tmp;
}

void	check_send(t_list **stack_a, t_list **stack_b, int *p, int max)
{
	int		i;
	t_list	*tmp;

	tmp = (*stack_a);
	while ((*stack_a)->next)
	{
		i = -1;
		while (++i < (max + 1))
		{
			if ((*stack_a)->content == p[i])
			{
				(*stack_a) = (*stack_a)->next;
				break ;
			}
		}
		if (i == (max + 1))
			function(stack_a, stack_b, &tmp);
	}
	while ((*stack_a)->prev)
		(*stack_a) = (*stack_a)->prev;
}

void	function(t_list **stack_a, t_list **stack_b, t_list **tmp)
{
	int	middle;
	int	a;

	middle = ((ft_lstsize(*tmp)) / 2);
	a = ((*stack_a)->content);
	while ((*stack_a)->index != 0 && (*tmp)->content != a)
	{
		if ((*stack_a)->index <= middle)
			ra(tmp);
		else
			rra(tmp);
	}
	pb (tmp, stack_b);
	(*stack_a) = *tmp;
}
