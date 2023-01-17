/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:02:47 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/17 17:14:07 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (c == 0)
		return (((char *) s) + len);
	while (s[i])
	{
		if (((char *)s)[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
