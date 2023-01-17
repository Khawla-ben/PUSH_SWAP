/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:40:52 by kben-ham          #+#    #+#             */
/*   Updated: 2023/01/17 19:30:01 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include<unistd.h>
# include<stdio.h>
# include<stdio.h>
# include<fcntl.h>
# include<stddef.h>
# include<stdlib.h>
# include "push_swap.h"

char	*get_next_line(int fd);

#endif