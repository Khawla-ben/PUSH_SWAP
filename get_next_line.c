/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:41:19 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/17 19:44:02 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && ((unsigned char)s1[i]) == ((unsigned char)s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static char	*ft_read_file(int fd, char **tmp)
{
	char		*p;
	int			nb;

	p = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!p)
		return (NULL);
	nb = 1;
	while (nb && !ft_strchr(*tmp, '\n'))
	{
		nb = read(fd, p, BUFFER_SIZE);
		if (nb < 0)
		{
			free(p);
			free(*tmp);
			return (NULL);
		}
		p[nb] = '\0';
		*tmp = ft_strjoin1(*tmp, p);
	}
	free(p);
	return (*tmp);
}

static char	*stop_line(char **tmp)
{
	int			i;
	char		*p1;
	char		*x;

	if (**tmp == 0)
		return (free(*tmp),*tmp = NULL, NULL);
	i = 0;
	if (ft_strchr(*tmp, '\n'))
	{
		while (tmp[0][i] != '\n')
			i++;
		if (tmp[0][i] == '\n')
			i++;
		p1 = (char *)malloc(sizeof(char) *(i + 1));
		if (!p1)
			return (NULL);
		p1[i] = '\0';
		while (i--)
			p1[i] = tmp[0][i];
		x = *tmp;
		*tmp = ft_strdup(ft_strchr(*tmp, '\n') + 1);
		return (free(x), p1);
	}
	else
		return (p1 = ft_strdup(*tmp), free(*tmp), *tmp = NULL, p1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_file(fd, &tmp);
	if (tmp == NULL)
		return (NULL);
	line = stop_line(&tmp);
	return (line);
}
