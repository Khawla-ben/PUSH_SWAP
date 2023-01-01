/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:17:19 by kben-ham          #+#    #+#             */
/*   Updated: 2022/12/30 17:46:24 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	long	n;

	i = 0;
	s = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32 && str[i]))
		i++;
	if ((str[i] == '-' && str[i + 1]) || (str[i] == '+' && str[i + 1]))
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while (str[i] && (ft_isdigit(str[i]) == 1))
		n = (n * 10 + (str[i++] - 48));
	if (((s * n) > 2147483647) || ((s * n) < -2147483648)
		|| (ft_isdigit(str[i]) == 0 && str[i]))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	return (s * n);
}
