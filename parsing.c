/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:59:33 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/17 19:40:18 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bonus.h"

int	*join_split_input(int ac, char **av, int *count)
{
	char	*table;
	char	**all;
	int		*new;
	int		i;
	int		j;

	i = 0;
	j = -1;
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
	while (all[++j])
		new[j] = ft_atoi(all[j]);
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
				write(2, "Error\n", 6);
				exit(1);
			}
			i++;
		}
		ft_lstadd_back(&stack_a, ft_lstnew(tout[j]));
		j++;
	}
	return (stack_a);
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

char	*ft_strjoin1(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!(s2))
		return (NULL);
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (NULL);
	while (s1[i])
		p[j++] = s1[i++];
	i = 0;
	while (s2[i])
		p[j++] = s2[i++];
	p[j] = '\0';
	free((void *)s1);
	return (p);
}
