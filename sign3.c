/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:11:33 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/16 20:23:08 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_sign31(t_list **stack_a, t_list **stack_b, int index, int ok)
{
	int	t;

	t = (ok * -1);
	while (t)
	{
		rra(stack_a);
		t--;
	}
	while (index)
	{
		rb(stack_b);
		index--;
	}
}

static void	get_sign32(t_list **stack_a, t_list **stack_b, int index, int ok)
{
	int	t;

	t = (index * -1);
	while (t)
	{
		rrb(stack_b);
		t--;
	}
	while (ok)
	{
		ra(stack_a);
		ok--;
	}
}

void	get_sign3(t_list **stack_a, t_list **stack_b, int index, int ok)
{
	if (ok < 0)
		get_sign31(stack_a, stack_b, index, ok);
	else if (ok > 0)
		get_sign32(stack_a, stack_b, index, ok);
}
