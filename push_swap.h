/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:45:53 by kben-ham          #+#    #+#             */
/*   Updated: 2022/12/23 15:07:26 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

//functions
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
// void print_c(t_list *stack_a, t_list *stack_b);

//sort3

void	f1(t_list	*stack_a);
void	f2(t_list	*stack_a);
void	do_it_3(t_list *stack_a);

// main_functions
// char **join_split_input(int ac,char **av);
// char	**check_input(char **table);
// char **check_input2(char **table);

// t_list
// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// 	struct s_list	*prev;
// }	t_list;

#endif