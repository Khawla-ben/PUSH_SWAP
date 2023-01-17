/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:59:57 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/17 01:35:35 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sign(t_list	**stack_a, t_list	**stack_b, int b_mv, int *all)
{
	int		i;
	int		index;
	int		ok;
	t_list	*tmp;

	tmp = (*stack_b);
	i = b_mv;
	while (b_mv > 0)
	{
		tmp = tmp->next;
		b_mv--;
	}
	index = tmp->index;
	ok = all[i];
	if (((index * ok) > 0) && (ok < 0))
		get_sign1(stack_a, stack_b, index, ok);
	else if (((index * ok) > 0) && (ok > 0))
		get_sign2(stack_a, stack_b, index, ok);
	else if ((ok * index) < 0)
		get_sign3(stack_a, stack_b, index, ok);
	else if ((ok * index) == 0)
		get_sign4(stack_a, stack_b, index, ok);
	pa(stack_b, stack_a);
	free(all);
}

static void	get_sign41( t_list **stack_b, int index, int ok)
{
	int	t;

	if (ok == 0 && index < 0)
	{
		t = (index * -1);
		while (t)
		{
			rrb(stack_b);
			t--;
		}
	}
	else if (ok == 0 && index > 0)
	{
		while (index)
		{
			rb(stack_b);
			index--;
		}
	}
}

static void	get_sign42(t_list **stack_a, int index, int ok)
{
	int	t;

	if (index == 0 && ok < 0)
	{
		t = (ok * -1);
		while (t)
		{
			rra(stack_a);
			t--;
		}
	}
	else if (index == 0 && ok > 0)
	{
		while (ok)
		{
			ra(stack_a);
			ok--;
		}
	}
}

void	get_sign4(t_list **stack_a, t_list **stack_b, int index, int ok)
{
	get_sign41(stack_b, index, ok);
	get_sign42(stack_a, index, ok);
}
