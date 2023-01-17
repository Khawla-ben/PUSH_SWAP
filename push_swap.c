/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:29:36 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/17 15:59:45 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	exit(1);
}
