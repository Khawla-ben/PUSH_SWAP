/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:29:36 by kben-ham          #+#    #+#             */
/*   Updated: 2022/12/23 15:07:36 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*join_split_input(int ac, char **av, int *count)
{
	char	*table;
	char	**all;
	int		*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	table = NULL;
	while (++i < ac)
		table = ft_strjoin(table, av[i], ' ');
	all = ft_split(table, ' ');
	i = 0;
	while (all[i++])
	*count = i;
	new = malloc (sizeof(int) * i);
	if (!new)
		return (NULL);
	while (all[j])
	{
		new[j] = ft_atoi(all[j]);
		j++;
	}
	return (new);
}

t_list	*check_create(t_list *stack_a, int *tout, int *count)
{
	int	i;
	int	j;

	j = 0;
	i = j;
	stack_a = ft_lstnew(tout[j]);
	j++;
	while (j < *count)
	{
		i = 0;
		while (i < j)
		{
			if (tout[j] == tout [i])
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			i++;
		}
		ft_lstadd_back(&stack_a, ft_lstnew(tout[j]));
		j++;
	}
	return (stack_a);
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

int	small_node(t_list *stack_a)
{
	int	count;
	int	min;
	int	index_min;

	index_min = 0;
	min = stack_a->content;
	count = 0;
	while (stack_a->next)
	{
		if (min > (stack_a->next->content))
		{
			min = stack_a->next->content;
			index_min = count + 1;
		}
		count++;
		stack_a = stack_a->next;
	}
	return (index_min);
}

void	put_top(t_list *stack_a, t_list *stack_b)
{
	int	middle;
	int	i;

	middle = ((ft_lstsize(stack_a) + 1) / 2);
	while (ft_lstsize(stack_a) > 3)
	{
		if (small_node(stack_a) == 0)
			pb (&stack_a, &stack_b);
		else if (small_node(stack_a) <= middle && (ft_lstsize(stack_a) > 3))
			ra(&stack_a);
		else
			rra(&stack_a);
	}
	do_it_3(stack_a);
	i = ft_lstsize(stack_a);
	while ((i - 2) >= 0)
	{
		pa(&stack_b, &stack_a);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		*tout;
	int		count;
	int		size;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		tout = join_split_input(ac, av, &count);
		stack_a = check_create(stack_a, tout, &count);
		size = ft_lstsize(stack_a);
		check_ordre(stack_a);
		if (size == 3)
			do_it_3(stack_a);
		if (size == 2)
			sa(&stack_a);
		if (size == 4)
			put_top(stack_a, stack_b);
		if (size == 5)
			put_top(stack_a, stack_b);
	}
	exit(1);
}
