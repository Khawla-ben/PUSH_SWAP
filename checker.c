/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:04:27 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/17 19:43:51 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"bonus.h"

static void	check_line_1(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strcmp(line, "rra\n"))
		rotate_reverse(stack_a);
	else if (!ft_strcmp(line, "rrb\n"))
		rotate_reverse(stack_b);
	else if (!ft_strcmp(line, "rrr\n"))
	{
		rotate_reverse(stack_b);
		rotate_reverse(stack_a);
	}
	else if (!ft_strcmp(line, "pa\n"))
		push(stack_b, stack_a);
	else if (!ft_strcmp(line, "pb\n"))
		push(stack_a, stack_b);
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

static void	check_line(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strcmp(line, "sa\n"))
		swap(stack_a);
	else if (!ft_strcmp(line, "sb\n"))
		swap(stack_b);
	else if (!ft_strcmp(line, "ss\n"))
	{
		swap(stack_b);
		swap(stack_a);
	}
	else if (!ft_strcmp(line, "ra\n"))
		rotate(stack_a);
	else if (!ft_strcmp(line, "rb\n"))
		rotate(stack_b);
	else if (!ft_strcmp(line, "rr\n"))
	{
		rotate(stack_b);
		rotate(stack_a);
	}
	else
		check_line_1(line, stack_a, stack_b);
}

static int	check_ordre_b(t_list *stack_a)
{
	while (stack_a->next)
	{
		if ((stack_a->content) > (stack_a->next->content))
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

static void	terminate(t_list *stack_a, t_list *stack_b)
{
	if (check_ordre_b(stack_a) && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	int		*tout;
	int		count;
	char	*line;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		tout = join_split_input(ac, av, &count);
		stack_a = check_create(stack_a, tout, &count);
		while (1)
		{
			line = get_next_line(0);
			if (line == NULL)
				break ;
			check_line(line, &stack_a, &stack_b);
			free(line);
		}
		terminate(stack_a, stack_b);
	}
	exit(1);
}
