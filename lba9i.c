/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lba9i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:30:58 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/04 16:30:59 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// void	get_best_move(int *sum, int size,int	*p, t_list	**stack_a, t_list **stack_b)
// {
	// int	mv;
	// int	i;
	// int count;
	
	// i = 0;
	// count = 0;
	// mv = sum [i];
	// while ((size - 1) > ++i)
	// {
	// 	puts("ttt");
	// 	if (mv > sum[i])
	// 	{
	// 		mv = sum[i];
	// 		count = i;
	// 	}
		
	// }
	
// 	//donc best mvt is mv and count is the number of time that stack_b will incrementer
// 	// i = 0;
// 	// while(i < 2)
// 	// {
// 	// 	printf(">>>>>>>.....<<<<<%d\n", sum[i]);
// 	// 	i++;
// 	// }
// 	// printf(">>>>>>><<<<<%d\n", count);
// 	printf("%d\n",count);
// 	do_it(stack_a, stack_b, sum, p, count);

	
// }

// void do_it(t_list	**stack_a, t_list	**stack_b, int *sum, int *p, int count)
// {
// 	int middle;
// 	int	size;
// 	int	i;
// 	int j;
// 	t_list *tmp;

	
// 	size = ft_lstsize(*stack_a);
// 	middle = (size / 2);
// 	if ((size % 2) != 0)
// 		middle +=1;

// 	tmp = (*stack_b);
		
// 		printf("count = %d\n",count);
// 		// printf("%d-------",middle);
// 	// printf("....%d....\n",sum[count]);
// 	// puts("hhh");
// 	// printf("....%d....\n",sum[0]);
// 	// printf("....%d....\n",sum[1]);
// 	// i = sum[count];
// 	i = 0;
// 	j = sum[count] -1 ;
	
// 	/////again//////
// 	if (count > 0)
// 	{
// 		(*stack_b) = (*stack_b)->next;
// 		count--;
// 	}
// 	// printf("%d", (*stack_b)->next->index );
// 	i = (*stack_b)->index;
// 	(*stack_b )= tmp;
// 	printf("--+--+-+-+%d",i);
// 	// if (i != 0)
// 	// {
// 		while (i <= 0)
// 		{
// 			rrb(stack_b);
// 			i++;
// 		}
// 		while (i > 0)
// 		{
// 			rb(stack_b);
// 			i--;
// 		}
// 	// put_right(stack_a, stack_b, count);
// 	// }
	
// 	puts("again");
// 	print_c(*stack_a,*stack_b);
	
// 	if (p[i] < middle ) // i ghalaaaaaat ola khassni nzid chi7aja bach maydkhlch lhna
// 	{
// 			puts("lll");
// 		while (j > 0)
// 		{
// 			ra(stack_a);
// 			j--;
// 		}
// 		// pa(stack_b,stack_a); //hna 
// 	}
// 	else if (p[i] > middle)
// 	{
// 			puts("ldcjdsc");
// 		while (j > 0)
// 		{
// 			rra(stack_a);
// 			j--;
// 		}
// 		// pa(stack_b,stack_a); //hna
// 	} 								//////again///////
// 		pa(stack_b,stack_a);
	
	// print_c(*stack_a,*stack_b);
// }
// void put_right(t_list	**stack_a, t_list	**stack_b, int count)
// {
// 	puts("right");
// 	int middle2;
// 	int	size2;
	
// 	size2 = ft_lstsize(*stack_b);
// 	middle2 = (size2 / 2);
// 	if ((size2 % 2) != 0)
// 		middle2 +=1;
		
// 	if(count < middle2)
// 	{
// 		while((*stack_b)->index != count)
// 		{
// 			rb(stack_b);
// 			count--;
// 		}
// 	}
// 	else if (count > middle2)
// 	{
// 		while ((*stack_b)->index != count)
// 		{
// 			rrb(stack_b);
// 			count--;
// 		}
// 	}
// 	pa(stack_b,stack_a);
// }
