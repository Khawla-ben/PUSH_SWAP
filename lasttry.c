/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lasttry.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:41:44 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/02 14:58:09 by kben-ham         ###   ########.fr       */
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
	put_new_index(stack_a);
	put_new_index(stack_b);
	// print_c(*stack_a,*stack_b);
	get_result(stack_a, stack_b);
}

void get_result(t_list **stack_a, t_list **stack_b)
{
	get_position(stack_a,stack_b);
}

int get_position(t_list	**stack_a, t_list	**stack_b)
{
	int	*p;
	int size;
	int	i;
	t_list *tmp;
	
	tmp = (*stack_b);
	i = 0;
	size = (ft_lstsize(*stack_b));
	p = malloc (sizeof(int) * size);
	if (!p)
		return (0);

	while(size > 0)
	{
		p[i] = get_position_small(stack_a,stack_b);
		(*stack_b) = (*stack_b)->next;
		i++;
		size--;
	}
	(*stack_b) = tmp;
		// print_c(*stack_a,*stack_b);

	get_sum(p, stack_b);
	
	// i = 0;
	// while(i < 2)
	// {
	// 	printf(">>>>>>><<<<<%d", p[i]);
	// 	i++;
	// }
	return (0);
}

int	get_sum(int	*p, t_list	**stack_b)
{
	int *sum;
	int i;
	int	size;
	t_list	*tmp;

	tmp = (*stack_b);
	size = (ft_lstsize(*stack_b));
	sum = malloc (sizeof(int) * size);
	if (!sum)
		return (0);
	
	i = 0;
	while(*stack_b)
	{
		if (((*stack_b)->index) < 0)
			((*stack_b)->index) = ((*stack_b)->index) * (-1);
		
		sum[i] = ((*stack_b)->index) + p[i] + 1;
		i++;
		(*stack_b) = (*stack_b)->next;
	}
	(*stack_b) = tmp; // new function
		i = 0;
	// while(i < 2)
	// {
	// 	printf(">>>>>>>%d<<<<<", sum[i]);
	// 	i++;
	// }
	get_best_move(sum, size);
	return(0);
	
}

int	get_best_move(int *sum, int size)
{
	int	mv;
	int	i;
	int	count;
	
	i = 0;
	count = 1;
	mv = sum [i];
	while (size > ++i)
	{
		if(mv > sum[i])
		{
			mv = sum[i];
			count = i;
		}
	}//donc best mvt is mv and count is the number of time that stack_b will incrementer
	// i = 0;
	// while(i < 2)
	// {
	// 	printf(">>>>>>>.....<<<<<%d\n", sum[i]);
	// 	i++;
	// }
	// printf(">>>>>>><<<<<%d\n", count);
	
	

	return(0);
}


int get_position_small(t_list	**stack_a, t_list	**stack_b)
{
	int	num;
	int max;
	int	min;
	t_list	*tmp;

	tmp = (*stack_a);
	num = 0;
	max = max_content(stack_a);
	min = min_content(stack_a);
	(*stack_a) = (*stack_a)->next;
	while (*stack_a)
	{
		if (((*stack_b)->content < (*stack_a)->content) && ((*stack_b)->content > (*stack_a)->prev->content))
		{
			num = (*stack_a)->index;
			if (num < 0)
				num = (num * (-1));
			break ;
		}
		else if (((*stack_b)->content < min) && ((*stack_a)->content = min) && ((*stack_a)->prev->content = max))
		{
			num = (*stack_a)->index;
			if (num < 0)
				num = (num * (-1));
			break ;
		}
		(*stack_a) = (*stack_a )->next;
	}
	(*stack_a)= tmp;
	return (num);
}

