/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_we_go_again.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:59:11 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/17 02:14:36 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_count(t_list **stack_a, t_list **tmp, int to_check)
{
	int		count;
	t_list	*tmp2;

	tmp2 = NULL;
	count = 0;
	if (!(*tmp)->next)
		tmp2 = *stack_a;
	else
		tmp2 = (*tmp)->next;
	while ((*tmp)->content != (tmp2)->content)
	{
		if (to_check < (tmp2)->content)
		{
			to_check = (tmp2)->content;
			count++;
		}
		if ((tmp2)->next == NULL)
			(tmp2) = *stack_a;
		else
			(tmp2) = (tmp2)->next;
	}
	return (count);
}

void	check(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*tmp;
	int		count;
	int		max;
	int		c_index;
	int		*p;

	tmp = *stack_a;
	*stack_b = NULL;
	max = 0;
	while (tmp)
	{
		count = 0;
		count = get_count(stack_a, &tmp, tmp->content);
		if (max < count)
		{
			max = count;
			c_index = tmp->content;
		}
		tmp = tmp->next;
	}
	p = put_longest(stack_a, c_index, max);
	put_index(stack_a);
	check_send(stack_a, stack_b, p, max);
	free(p);
	get_result(stack_a, stack_b);
}

void	get_result(t_list **stack_a, t_list **stack_b)
{
	int	middle;
	int	size_a;
	int	size_b;
	int	size;
	int	i;

	i = 0;
	size_a = (ft_lstsize(*stack_a));
	size_b = (ft_lstsize(*stack_b));
	size = size_b;
	while (size_b > 0)
	{
		put_new_index(stack_a);
		put_new_index(stack_b);
		get_position(stack_a, stack_b, size_b);
		size_b--;
	}
	middle = (size_a / 2);
	while (small_node(*stack_a) != 0)
	{
		if (small_node(*stack_a) <= middle)
			ra(stack_a);
		else
			rra(stack_a);
	}
}
