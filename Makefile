# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 20:56:43 by kben-ham          #+#    #+#              #
#    Updated: 2022/12/30 21:19:23 by kben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# B_OBJECT = $(BONUS_SRC:.c=.o)

CC = cc -g

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

MY_FILES = push_swap.c functions.c functions2.c functions3.c sort3.c sort.c printf.c lasttry.c 

OBJECT = $(MY_FILES:.c=.o)
# BONUS_SRC =
NAME = push_swap

all: $(NAME)

%.o: %.c push_swap.h
	$(CC)  $(CFLAGS) -o $@ -c  $<

$(NAME): $(OBJECT)
	make all -C libft
	$(CC)  $(CFLAGS) $^ $(LIBFT) -o $(NAME)

# bonus: $(B_OBJECT)
# 	$(AR) $(NAME) $^

clean:
	make clean -C libft
	rm -f $(OBJECT) 
	
fclean: clean
	rm -rf $(NAME) libft/libft.a

re: fclean all

PHONY : all clean fclean re