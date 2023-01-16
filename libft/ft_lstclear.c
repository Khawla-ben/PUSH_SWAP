/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:12:54 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/16 21:46:33 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		(*del)(&(*lst)->content);
		p = (*lst)->next;
		p->prev = NULL;
		free(*lst);
		(*lst) = p;
	}
	*lst = NULL;
}
