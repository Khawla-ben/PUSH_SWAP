/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lasttry.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:41:44 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/01 07:37:59 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	check(t_list	**stack_a, t_list	**stack_b)
{
	t_list *tmp;
	t_list *tmp2;
	int		count;
	int 	max;
	int		to_check;
	int		c_index;
	int		*p;

	// c_index = 0; /// ....................
	tmp = *stack_a;
	*stack_b = NULL;
	max = 0;
	while (tmp)
	{
		count = 0;
		to_check = tmp->content;
		if (!tmp->next)
			tmp2= *stack_a;
		else		
			tmp2 = tmp->next;
		while (tmp->content != tmp2->content)
		{
			if (to_check < tmp2->content)
			{
				to_check = tmp2->content;
				count++;

			}
			if (tmp2->next == NULL)
				tmp2 = *stack_a;
			else
				tmp2 = tmp2->next;	
			// else if (to_check > tmp2->content)
			// {
			// 	if (tmp2->next == NULL)
			// 		tmp2 = *stack_a;
			// 	else
			// 		tmp2 = tmp2->next;
			// }
		}
		if (max < count)
		{
			max = count;
			c_index = tmp->content;
		}
		tmp = tmp->next;
	}
	// puts("done");
		// printf(">>>%d\n",count);
		// puts("--------another index-------------");
	// printf(".......%d\n",c_index);
	// 	printf(">>>%d\n",max);
	// puts("ok");
	p = put_longest(stack_a, c_index, max);
	// int i = 0;
	// while(i < max+1)
	// {
	// 	printf("--------------------------%d",p[i]);
	// 	i++;
	// }
	put_index(stack_a);
	check_send(stack_a, stack_b, p, max);
	print_c(*stack_a,*stack_b);
}

int	*put_longest(t_list **stack_a, int c_index, int max)
{
	t_list *tmp;
	t_list *tmp2;
	t_list *tmp3;
	int		to_check;
	int 	*p;
	int		i;

	tmp3 = (*stack_a);
	while (c_index != (*stack_a)->content)
		(*stack_a) = (*stack_a)->next;
	p = malloc (sizeof (int) *  max + 1);
	if (!p)
		exit(1);
	tmp = (*stack_a);
	to_check = tmp->content;
	if (!tmp->next)
		tmp2= tmp3;
	else
		tmp2 = tmp->next;
	i = 0;
	p[i] = to_check;
	while (tmp->content != tmp2->content)
	{
		if (to_check < tmp2->content)
		{
			to_check = tmp2->content;
			p[++i] = to_check;
		}
		if (tmp2->next == NULL)
			tmp2 = *stack_a;
		else
			tmp2 = tmp2->next;
		// else if (to_check > tmp2->content) //momkin t7ydi hadi o dik if likayna 9bl khrjiha bra l while
		// {
		// 	if (tmp2->next == NULL)
		// 		tmp2 = *stack_a;
		// 	else
		// 		tmp2 = tmp2->next;
		// }
	}
	(*stack_a) = tmp3;
	return (p);
}
