/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:29:36 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/17 01:57:57 by kben-ham         ###   ########.fr       */
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
	// system ("leaks push_swap");
	while (++i < ac)
	{
		// if (table)
		// 	free(table);
		table = ft_strjoin(table, av[i], ' ');
	}
	// system ("leaks push_swap");
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
	free_table(all, j);
	free(table);
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

void	put_top(t_list *stack_a, t_list *stack_b)
{
	int	middle;

	middle = ((ft_lstsize(stack_a) + 1) / 2);
	while (ft_lstsize(stack_a) > 3)
	{
		if (small_node(stack_a) == 0)
			pb (&stack_a, &stack_b);
		else if (small_node(stack_a) <= middle)
			ra(&stack_a);
		else
			rra(&stack_a);
	}
	do_it_3(stack_a);
	while (stack_b)
		pa(&stack_b, &stack_a);
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
		if (size == 2)
			sa(&stack_a);
		else if (size == 3)
			do_it_3(stack_a);
		else if ((size == 4) || (size == 5))
			put_top(stack_a, stack_b);
		else if (size > 5)
			check(&stack_a, &stack_b);
	}
	// system ("leaks push_swap");
	exit(1);
}
