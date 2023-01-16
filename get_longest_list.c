/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_longest_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:59:11 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/16 18:51:29 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_p(int **p, int to_check, t_list **tmp, t_list **tmp3)
{
	t_list	*tmp2;
	int		i;

	tmp2 = NULL;
	if (!(*tmp)->next)
		tmp2 = *tmp3;
	else
		tmp2 = (*tmp)->next;
	i = 0;
	p[0][i] = to_check;
	while ((*tmp)->content != tmp2->content)
	{
		if (to_check < tmp2->content)
		{
			to_check = tmp2->content;
			p[0][++i] = to_check;
		}
		if (tmp2->next == NULL)
			tmp2 = *tmp3;
		else
			tmp2 = tmp2->next;
	}
}

int	*put_longest(t_list **stack_a, int c_index, int max)
{
	t_list	*tmp;
	t_list	*tmp3;
	int		*p;

	tmp3 = (*stack_a);
	while (c_index != (*stack_a)->content)
		(*stack_a) = (*stack_a)->next;
	p = malloc (sizeof(int) * max + 1);
	if (!p)
		exit(1);
	tmp = (*stack_a);
	get_p(&p, tmp->content, &tmp, &tmp3);
	return (((*stack_a) = tmp3), p);
}

void	put_new_index(t_list **stack)
{
	int		i;
	int		num;
	int		middle;
	t_list	*tmp;
	int		size;

	num = -1;
	tmp = (*stack);
	size = (ft_lstsize(*stack));
	middle = (size / 2);
	if ((size % 2) != 0)
		middle += 1;
	i = -1;
	while (++i < middle)
	{
		(*stack)->index = (++num);
		(*stack) = (*stack)->next;
	}
	num = (size - i);
	while (i++ < size)
	{
		(*stack)->index = (num--) * (-1);
		(*stack) = (*stack)->next;
	}
	(*stack) = tmp;
}

void	check_send(t_list **stack_a, t_list **stack_b, int *p, int max)
{
	int		i;
	t_list	*tmp;
	int		size_a;

	size_a = ft_lstsize(*stack_a);
	tmp = (*stack_a);
	while (size_a--)
	{
		i = -1;
		while (++i < (max + 1))
		{
			if ((*stack_a)->content == p[i])
			{
				if ((*stack_a)->next != NULL)
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
	pb(tmp, stack_b);
	(*stack_a) = *tmp;
}
