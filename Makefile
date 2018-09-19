# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enikel <enikel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 11:24:40 by enikel            #+#    #+#              #
#    Updated: 2018/09/19 11:41:18 by enikel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_ls

INC_DIR := inc

SRC_DIR := src

OBJ_DIR := obj

LIB_DIR := lib

SRC := ft_ls.c ft_ls_finit.c ft_ls_exit.c ft_ls_tolist.c ft_ls_l.c ft_ls_sort.c \
ft_ls_recursive.c ft_isflag.c ft_ls_direct.c ft_ls_blocksize.c ft_ls_isdir.c \
ft_ls_sort_switch.c ft_ls_checkpath.c ft_ls_file.c ft_print_list.c \
ft_ls_specific.c ft_ls_freelist.c ft_ls_sort_name.c ft_add_new.c

OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

LIBFT_DIR := $(LIB_DIR)/libft

CFLAGS := -Wall -Werror -Wextra

CC := @gcc $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	@make all -C $(LIBFT_DIR)/
	@ar rcs $(NAME).a $(OBJ) $(LIBFT_DIR)/*.o
	@$(CC) $(NAME).a -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -I $(INC_DIR) -o $@ -c $<

clean: cleanlib
	@rm -rf $(OBJ_DIR)

cleanlib:
	@make clean -C $(LIBFT_DIR)/

fclean: clean fcleanlib
	@rm -f $(NAME).a
	@rm -f $(NAME)

fcleanlib:
	@make fclean -C $(LIBFT_DIR)/

re: fclean all

.PHONEY := all clean fclean re

.PRECIOUS := author
