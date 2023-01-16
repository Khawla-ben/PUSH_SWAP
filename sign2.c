/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:11:31 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/16 20:23:58 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_sign21(t_list **stack_a, t_list **stack_b, int index, int ok)
{
	int	t;

	t = (ok - index);
	while (index)
	{
		rr(stack_a, stack_b);
		index--;
	}
	while (t)
	{
		ra(stack_a);
		t--;
	}
}

static void	get_sign22(t_list **stack_a, t_list **stack_b, int index, int ok)
{
	int	t;

	t = (index - ok);
	while (ok)
	{
		rr(stack_a, stack_b);
		ok--;
	}
	while (t)
	{
		rb(stack_b);
		t--;
	}
}

void	get_sign2(t_list **stack_a, t_list **stack_b, int index, int ok)
{
	if ((index < ok))
		get_sign21(stack_a, stack_b, index, ok);
	else if ((ok < index))
		get_sign22(stack_a, stack_b, index, ok);
	else if (ok == index)
	{
		while (ok)
		{
			rr(stack_a, stack_b);
			ok--;
		}
	}
}
