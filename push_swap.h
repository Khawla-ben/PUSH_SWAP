/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:45:53 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/16 22:25:11 by kben-ham         ###   ########.fr       */
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

//get_longest_list
int		*put_longest(t_list **stack_a, int c_index, int max);
void	put_new_index(t_list **stack);
void	check_send(t_list **stack_a, t_list **stack_b, int *p, int max);
void	function(t_list **stack_a, t_list **stack_b, t_list **tmp);

//get_result
void	get_position(t_list	**stack_a, t_list	**stack_b, int size_b);
void	get_best_move(int *sum, t_list	**stack_a, t_list **stack_b, int *all);
int		*get_sum(int	*p, t_list	**stack_b, int size_b);
void	put_index(t_list **lst);

//here_we_go_again
int		get_count(t_list **stack_a, t_list **tmp, int to_check);
void	check(t_list	**stack_a, t_list	**stack_b);
void	get_result(t_list **stack_a, t_list **stack_b);

//max_min
int		min_content(t_list **stack_a);
int		max_content(t_list **stack_a);
int		i_min_content(t_list **stack_a);
int		i_max_content(t_list **stack_a);
int		small_node(t_list *stack_a);

//ok
int		*cor_p(t_list **stack_a, t_list **stack_b, int size_b);
int		get_b_p(t_list **stack_a, t_list **stack_b, int max, int min);
int		position_in_a(t_list **stack_a, t_list **stack_b, int num, int a);
void	*free_table(char **tab, int j);

//sign
void	check_sign(t_list	**stack_a, t_list	**stack_b, int b_mv, int *all);
void	get_sign1(t_list **stack_a, t_list **stack_b, int index, int ok);
void	get_sign2(t_list **stack_a, t_list **stack_b, int index, int ok);
void	get_sign3(t_list **stack_a, t_list **stack_b, int index, int ok);
void	get_sign4(t_list **stack_a, t_list **stack_b, int index, int ok);

#endif
