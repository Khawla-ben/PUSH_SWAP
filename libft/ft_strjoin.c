/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:14:35 by kben-ham          #+#    #+#             */
/*   Updated: 2022/12/18 20:32:39 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, char c)
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
		write(1, "Error\n", 6);
		exit(1);
	}
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!p)
		return (NULL);
	while (s1[i])
		p[j++] = s1[i++];
	p[j++] = c;
	i = 0;
	while (s2[i])
		p[j++] = s2[i++];
	p[j] = '\0';
	return (p);
}
