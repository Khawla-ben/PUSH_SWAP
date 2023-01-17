/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:14:35 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/17 17:42:05 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, char c)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (ft_strlen(s2) == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!p)
		exit(1);
	while (s1[i])
		p[j++] = s1[i++];
	p[j++] = c;
	i = 0;
	while (s2[i])
		p[j++] = s2[i++];
	p[j] = '\0';
	free((void *)s1);
	return (p);
}
