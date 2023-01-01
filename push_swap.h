/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:45:53 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/01 07:29:42 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

//functions + functions2 + functions3
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list	**stack_a);
void	rb(t_list	**stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	pb(t_list	**stack_a, t_list **stack_b);
void	pa(t_list	**stack_b, t_list **stack_a);
void	rra(t_list	**stack_a);
void	rrb(t_list	**stack_b);
void	rrr(t_list	**stack_a, t_list **stack_b);
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	push(t_list	**stack_1, t_list **stack_2);
void	rotate_reverse(t_list	**stack_1);

//sort3
void	f1(t_list	*stack_a);
void	f2(t_list	*stack_a);
void	do_it_3(t_list *stack_a);

//lasttry
void	check(t_list	**stack_a, t_list	**stack_b);
int		*put_longest(t_list **stack_a, int c_index, int max);

//sort
int		small_node(t_list *stack_a);
void	put_index(t_list **lst);
void	check_send(t_list **stack_a, t_list **stack_b, int *p, int max);
void	function(t_list **stack_a, t_list **stack_b, t_list **tmp);

//printf
void	print_c(t_list *stack_a, t_list *stack_b);

#endif