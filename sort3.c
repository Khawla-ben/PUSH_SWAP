/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:32:37 by kben-ham          #+#    #+#             */
/*   Updated: 2022/12/23 15:19:01 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f1(t_list	*stack_a)
{
	int		a;
	t_list	*tmp;

	tmp = stack_a;
	a = stack_a->content;
	stack_a = stack_a->next;
	if (stack_a->content > stack_a->next->content)
	{
		if (a < (stack_a->next->content))
		{
			sa(&tmp);
			ra(&tmp);
		}
		else if (a > (stack_a->next->content))
		{
			stack_a = stack_a->prev;
			rra(&tmp);
		}
	}	
	stack_a = tmp;
}

void	f2(t_list	*stack_a)
{
	int		a;
	t_list	*tmp;

	tmp = stack_a;
	a = stack_a->content;
	stack_a = stack_a->next;
	if (stack_a && stack_a->content < stack_a->next->content)
	{
		stack_a = stack_a->prev;
		if (a < (stack_a->next->next->content))
			sa(&tmp);
		else if (a > (stack_a->next->next->content))
			ra(&tmp);
	}
	else if (stack_a && stack_a->content > stack_a->next->content)
	{
		if (a > (stack_a->next->content))
		{
			stack_a = stack_a->prev;
			sa(&tmp);
			rra(&tmp);
		}
	}
	stack_a = tmp;
}

void	do_it_3(t_list *stack_a)
{
	while (stack_a->next)
	{
		if ((stack_a->content) < (stack_a->next->content))
		{
			f1(stack_a);
			break ;
		}
		if ((stack_a->content) > (stack_a->next->content))
		{
			f2(stack_a);
			break ;
		}
		stack_a = stack_a->next;
	}
}
