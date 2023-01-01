/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:59:11 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/01 05:23:01 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_c(t_list *stack_a, t_list *stack_b)
{
	while (stack_a)
	{
		printf("a = %d\n", stack_a->content);
		stack_a = stack_a->prev;
	}	
	while (stack_b)
	{
		printf("               b = %d\n", stack_b->content);
		stack_b = stack_b->next;
	}
}
