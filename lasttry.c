/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lasttry.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:41:44 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/07 10:53:31 by kben-ham         ###   ########.fr       */
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
	p = put_longest(stack_a, c_index, max); // db wlat s7i7a
	
	// int i = 0;
	// while(i < max+1)
	// {
	// 	printf("--------------------------%d",p[i]);
	// 	i++;
	// }
// print_c(*stack_a,*stack_b);
	put_index(stack_a);
	// print_c(*stack_a,*stack_b);
	check_send(stack_a, stack_b, p, max); // s7i7a 100
	
	get_result(stack_a, stack_b);
	// puts("hvdhsvs");
	// print_c(*stack_a,*stack_b);
}

void get_result(t_list **stack_a, t_list **stack_b)
{
	int	middle;
	int size;
	
	while(*stack_b)
	{
		put_new_index(stack_a); // s7I7a 100
		put_new_index(stack_b); // s7I7a 100
		// puts("hvdsv");
		get_position(stack_a,stack_b);
	}
	// print_c(*stack_a,*stack_b);

	size = 0;
	middle = ((ft_lstsize(*stack_a)) / 2);
	if ((size % 2) != 0)
		middle +=1;

	while (small_node(*stack_a) != 0)
	{
		if (small_node(*stack_a) <= middle)
			ra(stack_a);
		else
			rra(stack_a);
	}
	// print_c(*stack_a,*stack_b);

}

void get_position(t_list	**stack_a, t_list	**stack_b)
{
	int	*p;
	int size;
	int	i;
	t_list *tmp;
	
	tmp = (*stack_b);
	i = 0;
	size = (ft_lstsize(*stack_b)); 
	p = malloc (sizeof(int) * size); 
	// if (!p)
	// 	return (0);
	// puts("mmm");
	// print_c(*stack_a,*stack_b); ///khawla

	// printf("size = %d\n", size);
	// puts("hdvbsivddfv");
	while(size > 0) //////////////////////trrrrrt
	{
		// puts("g");
		p[i] = get_position_small(stack_a,stack_b); //
		// puts("gh");
		
		(*stack_b) = (*stack_b)->next;
		if ((*stack_b) == NULL)
			break ;
		// printf("st=%d\n",(*stack_b)->content);
		i++;
		size--;
	}
	(*stack_b) = tmp;
	// print_c(*stack_a,*stack_b);
	// 	i = 0;
	// while(i < 3)
	// {
	// 	printf("p>>>>>>>%d<<<<<", p[i]);
	// 	i++;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
	// }
	
	get_sum(p, stack_b,stack_a); // hadi s7I7a 100
}

void	get_sum(int	*p, t_list	**stack_b, t_list **stack_a)
{
	int *sum;
	int i;
	int	size;
	t_list	*tmp;

	tmp = (*stack_b);
	size = (ft_lstsize(*stack_b));
	sum = malloc (sizeof(int) * size);
	// if (!sum)
	// 	return (0);
	
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
		// (void)(*stack_a);
		// i = 0;
	// while(i < 3)
	// {
	// 	printf(">>>>>>>%d<<<<<", sum[i]);
	// 	i++;
	// }

	get_best_move(sum, size, stack_a, stack_b, p); // mn hna....
	
}

void get_best_move(int *sum, int size_b, t_list	**stack_a, t_list **stack_b, int *p)
{
	// print_c(*stack_a,*stack_b);
	int b_mv;
	int i_b_mv;
	
	int i;
	
	int b_mv_g;
	int i_b_mv_g;

	b_mv = 0;
	i_b_mv = 0;
	
	b_mv_g = b_mv;
	i_b_mv_g = i_b_mv;
	i = 0;
	b_mv = sum [i];
	while (i < (size_b - 1))
	{
		i++;
		if (b_mv > sum[i])
		{
			b_mv = sum[i];
			i_b_mv = p[i];
		}
	}
	// puts("pff");
	        // print_c(*stack_a,*stack_b);                                                                                                                                                                                                                                    
	// do_it_for_stack_b(stack_b, b_mv, i_b_mv, size_b); // hnaaaaaaa
	do_it_for_stack_a(stack_a, stack_b, sum, i_b_mv_g, size_b, b_mv); //hnaaaaaaaa
}

void	do_it_for_stack_a(t_list	**stack_a, t_list	**stack_b, int *sum, int i_b_mv, int size_b, int b_mv)
{
	int i;
	int j;
	int middle;
	int	size;
	int *all;
	(void)b_mv;
	
	// print_c(*stack_a,*stack_b);
	i = 0;
	size = ft_lstsize(*stack_a);
	middle = (size / 2);
	if ((size % 2) != 0)
		middle +=1;
	i = 0;
	j = sum[i_b_mv] - 1;
	// put_index(stack_a);
	all = get_po(stack_a,stack_b);

		if (all[i_b_mv] < middle && all[i_b_mv] >= 0  )
		{
				// puts("lll");
			while (j > 0)
			{
				ra(stack_a);
				j--;
			}
		}
		else if (all[i_b_mv] < middle && all[i_b_mv] < 0  )
		{
				// puts("tss");
			while (j > 0)
			{
				rra(stack_a);
				j--;
			}
		}
		else if (all[i_b_mv] > middle)
		{
				// puts("ldcjdsc");
			while (j > 0)
			{
				rra(stack_a);
				j--;
			}
		}
		// puts("hhjdsvs");
		// print_c(*stack_a,*stack_b);
		do_it_for_stack_b(stack_b, b_mv, i_b_mv, size_b); 
		pa(stack_b,stack_a);
}
// }

void	do_it_for_stack_b( t_list	**stack_b, int b_mv, int i_b_mv, int size_b)
{
	t_list *tmp;
	int		middle_b;
	int		j;
	int res;
	
	(void)b_mv;
	res = i_b_mv;
	middle_b = size_b / 2;
	tmp = (*stack_b);
	while (res > 0)
	{
		tmp = tmp->next;
		res--;
	}

	if (tmp->index != 0)
	{
		j = size_b - i_b_mv;
		if (i_b_mv < middle_b)
		{
			while (j >=0)
			{
				rb(stack_b);
				j--;
			}
		}
		if (i_b_mv >= middle_b)
		{
			while (j >=0)
			{
				rrb(stack_b);
				j--;
			}
		}
	}
}