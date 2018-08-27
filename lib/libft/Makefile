# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enikel <enikel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 10:00:08 by enikel            #+#    #+#              #
#    Updated: 2018/08/13 11:32:35 by enikel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES = ft_atoi.c ft_isupper.c ft_memset.c ft_strcat.c ft_strncmp.c \
ft_bzero.c ft_itoa.c ft_putchar.c ft_strchr.c ft_strncpy.c \
ft_intlen.c	ft_memalloc.c ft_putchar_fd.c ft_strclr.c ft_strnew.c \
ft_isalnum.c ft_memccpy.c ft_putendl.c ft_strcmp.c ft_strnstr.c \
ft_isalpha.c ft_memchr.c ft_putendl_fd.c ft_strcpy.c ft_strrchr.c \
ft_isascii.c ft_memcmp.c ft_putnbr.c ft_strdel.c ft_strrev.c \
ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c ft_strdup.c ft_strstr.c \
ft_islower.c ft_memdel.c ft_putstr.c ft_strlen.c ft_tolower.c \
ft_isprint.c ft_memmove.c ft_putstr_fd.c ft_strncat.c ft_toupper.c \
ft_strlcat.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
ft_strsplit.c get_next_line.c ft_putnbr_base.c ft_itoa_base.c \
ft_str_capitalize.c

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(FILES)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ)

fclean:	clean
	@rm -rf $(NAME)

re:	fclean all
