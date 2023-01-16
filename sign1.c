/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:05:56 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/16 20:22:41 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_sign11(t_list **stack_a, t_list **stack_b, int index_, int ok_)
{
	int	t;

	t = (index_ - ok_);
	while (ok_)
	{
		rrr(stack_a, stack_b);
		ok_--;
	}
	while (t)
	{
		rrb(stack_b);
		t--;
	}
}

static void	get_sign12(t_list **stack_a, t_list **stack_b, int index_, int ok_)
{
	int	t;

	t = (ok_ - index_);
	while (index_)
	{
		rrr(stack_a, stack_b);
		index_--;
	}
	while (t)
	{
		rra(stack_a);
		t--;
	}
}

void	get_sign1(t_list **stack_a, t_list **stack_b, int index, int ok)
{
	int	ok_;
	int	index_;

	ok_ = (ok * -1);
	index_ = (index * -1);
	if ((ok_ < index_))
		get_sign11(stack_a, stack_b, index_, ok_);
	else if ((ok_ > index_))
		get_sign12(stack_a, stack_b, index_, ok_);
	else if (ok_ == index_)
	{
		while (ok_)
		{
			rrr(stack_a, stack_b);
			ok_--;
		}
	}
}
