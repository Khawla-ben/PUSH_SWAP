# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 20:56:43 by kben-ham          #+#    #+#              #
#    Updated: 2023/01/17 16:49:19 by kben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


B_OBJECT = $(BONUS_SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT = libft/libft.a

MY_FILES = push_swap.c functions.c functions2.c functions3.c sort3.c ok.c sign.c \
here_we_go_again.c get_longest_list.c max_min.c get_result.c sign1.c sign2.c sign3.c parsing.c

BONUS_SRC = get_next_line.c checker.c functions.c functions2.c functions3.c parsing.c sort3.c \
ok.c max_min.c

OBJECT = $(MY_FILES:.c=.o)

B_OBJECT = $(BONUS_SRC:.c=.o)

NAME = push_swap

NAME_B = checker

all: $(NAME)

%.o: %.c push_swap.h
	$(CC)  $(CFLAGS) -o $@ -c  $<

$(NAME): $(OBJECT) 
	make all -C libft
	$(CC)  $(CFLAGS) $^ $(LIBFT) -o $(NAME)

bonus: $(B_OBJECT)
	make all -C libft
	$(CC)  $(CFLAGS) $^ $(LIBFT) -o $(NAME_B)

clean:
	make clean -C libft
	rm -f $(OBJECT) $(B_OBJECT)

fclean: clean
	rm -rf $(NAME) $(NAME_B) libft/libft.a

re: fclean all

.PHONY : all clean fclean re
