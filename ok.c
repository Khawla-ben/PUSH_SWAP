/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:59:11 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/17 19:29:07 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*cor_p(t_list **stack_a, t_list **stack_b, int size_b)
{
	int		min ;
	int		max;
	int		*c_p;
	int		i;
	t_list	*tmp2;

	max = max_content(stack_a);
	min = min_content(stack_a);
	i = 0;
	tmp2 = (*stack_b);
	c_p = malloc(sizeof(int) * size_b);
	if (!c_p)
		exit(1);
	while (size_b > 0)
	{
		c_p[i] = get_b_p(stack_a, stack_b, max, min);
		(*stack_b) = (*stack_b)->next;
		i++;
		size_b--;
	}
	(*stack_b) = tmp2;
	return (c_p);
}

int	get_b_p(t_list **stack_a, t_list **stack_b, int max, int min)
{
	int		num;
	int		i_max;
	int		i_min;
	int		a;
	t_list	*tmp;

	num = 0;
	tmp = *stack_a;
	i_max = i_max_content(stack_a);
	i_min = i_min_content(stack_a);
	a = tmp->index;
	if ((*stack_b)->content > max)
		num = i_max + 1;
	else if ((*stack_b)->content < min)
		num = i_min;
	else
		num = position_in_a(stack_a, stack_b, num, a);
	*stack_a = tmp;
	return (num);
}

int	position_in_a(t_list **stack_a, t_list **stack_b, int num, int a)
{
	while (*stack_a)
	{
		if ((*stack_a)->next == NULL
			&& (*stack_b)->content > (*stack_a)->content)
		{
			num = a;
			break ;
		}
		else if ((*stack_b)->content > (*stack_a)->content
			&& ((*stack_b)->content < (*stack_a)->next->content))
		{
			num = (*stack_a)->next->index;
			break ;
		}
		(*stack_a) = (*stack_a)->next;
	}
	return (num);
}

void	*free_table(char **tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free (tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

t_list	*check_ordre(t_list*stack_a)
{
	while (stack_a->next)
	{
		if ((stack_a->content) > (stack_a->next->content))
			return (0);
		stack_a = stack_a->next;
	}
	exit(0);
}
