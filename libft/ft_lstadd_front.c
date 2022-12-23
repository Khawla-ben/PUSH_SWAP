/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:12:52 by kben-ham          #+#    #+#             */
/*   Updated: 2022/12/21 22:10:31 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{	
	if (lst && new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		new->next = *lst;
		(*lst)->prev = new;
		*lst = new;
	}
}
