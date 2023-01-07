/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:34:11 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/07 10:53:42 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	small_node(t_list *stack_a)
{
	int	count;
	int	min;
	int	index_min;

	index_min = 0;
	min = stack_a->content;
	count = 0;
	while (stack_a->next)
	{
		if (min > (stack_a->next->content))
		{
			min = stack_a->next->content;
			index_min = count + 1;
		}
		count++;
		stack_a = stack_a->next;
	}
	return (index_min);
}

void	put_index(t_list **stack_a)
{
	t_list	*tmp;

	tmp = (*stack_a);
	while ((*stack_a)->next)
	{
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->index = (*stack_a)->prev->index + 1 ;
	}
	(*stack_a)->index = (*stack_a)->prev->index + 1 ;
	(*stack_a) = tmp;
}

void	check_send(t_list **stack_a, t_list **stack_b, int *p, int max)
{
	int		i;
	t_list	*tmp;

	tmp = (*stack_a);
	while ((*stack_a)->next)
	{
		i = -1;
		while (++i < (max + 1))
		{
			if ((*stack_a)->content == p[i])
			{
				(*stack_a) = (*stack_a)->next;
				break ;
			}
		}
		if (i == (max + 1))
			function(stack_a, stack_b, &tmp);
	}
	while ((*stack_a)->prev)
		(*stack_a) = (*stack_a)->prev;
}

void	function(t_list **stack_a, t_list **stack_b, t_list **tmp)
{
	int	middle;
	int	a;

	middle = ((ft_lstsize(*tmp)) / 2);
	a = ((*stack_a)->content);
	while ((*stack_a)->index != 0 && (*tmp)->content != a)
	{
		if ((*stack_a)->index <= middle)
			ra(tmp);
		else
			rra(tmp);
	}
	pb (tmp, stack_b);
	(*stack_a) = *tmp;
}

int get_position_small(t_list	**stack_a, t_list	**stack_b)
{
	// puts("a");
	// print_c(*stack_a,*stack_b);
	int	num;
	int max;
	int	min;
	t_list	*tmp;
	tmp = (*stack_a);
	// printf("tmp look %d\n",tmp->content);
	num = 0;
	max = max_content(stack_a);
	min = min_content(stack_a);
	while (*stack_a)
	{
		(*stack_a) = (*stack_a)->next;
		// printf("look %d",(*stack_a)->content);
		// puts("oooooook");
		if (((*stack_b)->content < (*stack_a)->content) && ((*stack_b)->content > (*stack_a)->prev->content))
		{
				// puts("trr");
			num = (*stack_a)->index; // momkin nkhtazlo had str f lfo9 7it kayn f 2 blays hna
			if (num < 0)
				num = (num * (-1));
			break ;
		}
		// else if (((*stack_a)->content = max) && ((*stack_b)->content < (*stack_a)->next->content))
		// {
		// 	puts("ddd");
		// 	num = (*stack_a)->index; // ohna
		// 	if (num < 0)
		// 		num = (num * (-1));
		// 	break ;
		
		else if (((*stack_b)->content < min) && ((*stack_a)->content == min) && ((*stack_a)->prev->content == max))
		{
			// print_c(*stack_a,*stack_b);
			// puts("f");
			num = (*stack_a)->index; // ohna
			if (num < 0)
				num = (num * (-1));
			break ;
		}
		if (((*stack_a)->next) == NULL)
			break;
	}
	// aslan makhassoch ydkhl lhna 
	(*stack_a) = tmp;
	// puts("b");
	// print_c(*stack_a,*stack_b);
	return (num);
}

int get_p(t_list	**stack_a, t_list	**stack_b)
{
	int	num;
	int max;
	int	min;
	t_list	*tmp;
	tmp = (*stack_a);
	num = 0;
	max = max_content(stack_a);
	min = min_content(stack_a);
	while (*stack_a)
	{
		(*stack_a) = (*stack_a)->next;
		if (((*stack_b)->content < (*stack_a)->content) && ((*stack_b)->content > (*stack_a)->prev->content))
		{
				// puts("trr");
			num = (*stack_a)->index; // momkin nkhtazlo had str f lfo9 7it kayn f 2 blays hna
			// if (num < 0)
			// 	num = (num * (-1));
			break ;
		}

		else if (((*stack_b)->content < min) && ((*stack_a)->content == min) && ((*stack_a)->prev->content == max))
		{
			// puts("f");
			num = (*stack_a)->index; // ohna
			// if (num < 0)
			// 	num = (num * (-1));
			break ;
		}
		else if (((*stack_a)->next) == NULL) 
			break;
	}
	return (((*stack_a)= tmp), num);
}

int *get_po(t_list	**stack_a, t_list	**stack_b)
{
	int	*all;
	int size;
	int	i;
	t_list *tmp;
	
	tmp = (*stack_b);
	i = 0;
	size = (ft_lstsize(*stack_b)); //3
	all = malloc (sizeof(int) * size); //3
	// if (!p)
	// 	return (0);
	while(size > 0)
	{
		all[i] = get_p(stack_a,stack_b); // 
		// puts("gh");
		
		(*stack_b) = (*stack_b)->next;
		if ((*stack_b) == NULL)
			break ;
		i++;
		size--;
	}
	(*stack_b) = tmp;
	return(all);
}