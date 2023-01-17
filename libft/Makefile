
NAME = libft.a

OBJECT = $(MY_FILES:.c=.o)

B_OBJECT = $(BONUS_SRC:.c=.o)

CC = cc  -g -Wall -Wextra -Werror

AR = ar rc

MY_FILES =	ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c\
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strlen.c \
			ft_strchr.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_putstr_fd.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_striteri.c \
			ft_itoa.c \
			ft_split.c \


BONUS_SRC = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstclear.c \

all: $(NAME)

%.o: %.c libft.h
	$(CC) -o $@ -c  $<

$(NAME): $(OBJECT) $(B_OBJECT)
	$(AR) $@ $^

clean:
	rm -f $(OBJECT) $(B_OBJECT)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
