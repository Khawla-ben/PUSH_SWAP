/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:59:11 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/17 01:34:24 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_position(t_list	**stack_a, t_list	**stack_b, int size_b)
{
	int	*p;
	int	*all;
	int	i;
	int	*sum;

	all = cor_p(stack_a, stack_b, size_b);
	p = malloc (sizeof(int) * size_b);
	if (!p)
		exit(1);
	i = 0;
	while (i < size_b)
	{
		if (all[i] < 0)
			p[i] = (all[i] * (-1));
		else
			p[i] = all[i];
		i++;
	}
	sum = get_sum(p, stack_b, size_b);
	free(p);
	get_best_move(sum, stack_a, stack_b, all);
}

void	get_best_move(int *sum, t_list	**stack_a, t_list **stack_b, int *all)
{
	int	b_mv;
	int	i_b_mv;
	int	i;
	int	size_b;

	size_b = (ft_lstsize(*stack_b));
	b_mv = 0;
	i_b_mv = 0;
	b_mv = sum[0];
	i = 0;
	while (size_b - 1 > 0)
	{
		if (b_mv > sum[i])
		{
			b_mv = sum[i];
			i_b_mv = i;
		}
		i++;
		size_b--;
	}
	free(sum);
	check_sign(stack_a, stack_b, i_b_mv, all);
}

int	*get_sum(int	*p, t_list	**stack_b, int size_b)
{
	int		*sum;
	int		a;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = (*stack_b);
	sum = malloc (sizeof(int) * size_b);
	if (!sum)
		exit (1);
	while (*stack_b)
	{
		a = (*stack_b)->index;
		if (((*stack_b)->index) < 0)
			a = ((*stack_b)->index) * (-1);
		sum[i] = a + p[i];
		i++;
		(*stack_b) = (*stack_b)->next;
	}
	(*stack_b) = tmp;
	return (sum);
}

void	put_index(t_list **stack_a)
{
	t_list	*tmp;

	tmp = (*stack_a);
	while ((*stack_a)->next)
	{
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->index = (*stack_a)->prev->index + 1;
	}
	(*stack_a)->index = (*stack_a)->prev->index + 1;
	(*stack_a) = tmp;
}
