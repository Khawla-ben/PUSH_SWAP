/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_longest_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:27:18 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/02 13:21:27 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*put_longest(t_list **stack_a, int c_index, int max)
{
	t_list *tmp;
	t_list *tmp2;
	t_list *tmp3;
	int		to_check;
	int 	*p;
	int		i;

	tmp3 = (*stack_a);
	while (c_index != (*stack_a)->content)
		(*stack_a) = (*stack_a)->next;
	p = malloc (sizeof (int) *  max + 1);
	if (!p)
		exit(1);
	tmp = (*stack_a);
	to_check = tmp->content;
	if (!tmp->next)
		tmp2= tmp3;
	else
		tmp2 = tmp->next;
	i = 0;
	p[i] = to_check;
	while (tmp->content != tmp2->content)
	{
		if (to_check < tmp2->content)
		{
			to_check = tmp2->content;
			p[++i] = to_check;
		}
		if (tmp2->next == NULL)
			tmp2 = *stack_a;
		else
			tmp2 = tmp2->next;
	}
	return (((*stack_a) = tmp3),p);
}

void put_new_index(t_list **stack)
{
	int		i;
	int		size;
	int		num;
	int		middle;
	t_list	*tmp;
	
	num = -1;
	tmp = (*stack);
	size = (ft_lstsize(*stack));
	middle = (size / 2);
	if ((size % 2) != 0)
		middle +=1;
	i = -1;
	while (++i < middle)
	{
		(*stack)->index = num + 1;
		(*stack) = (*stack)->next;
		num++;
	}
	num = (size - i);
	while(i < size)
	{
		(*stack)->index = num * (-1);
		(*stack) = (*stack)->next;
		num--;
		i++;
	}
	(*stack) = tmp;
}

int	max_content(t_list **stack_a)
{
	t_list *tmp;
	int		max;
	tmp = (*stack_a);
	max = 0;
	
	while (*stack_a)
	{
		if ((*stack_a)->content > max)
		max = (*stack_a)->content;
		(*stack_a) = (*stack_a)->next;
	}
	
	(*stack_a) = tmp;
	
	return(max);
}

int	min_content(t_list **stack_a)
{
	t_list *tmp;
	int		min;
	
	tmp = (*stack_a);
	min = (*stack_a)->content;
	(*stack_a) = (*stack_a)->next;
	
	while ((*stack_a))
	{
		if (min >(*stack_a)->content)
			min = (*stack_a)->content;
		(*stack_a) = (*stack_a)->next;
	}
	(*stack_a) = tmp;
	
	return(min);
}