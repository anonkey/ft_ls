# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/18 01:29:33 by tseguier          #+#    #+#              #
#    Updated: 2014/09/25 19:18:34 by tseguier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
NAME = ft_ls 
SRC = main.c \
	  ft_cmpgenfunc.c \
	  ft_ls.c \
	  ft_taskman.c \
	  ft_bf.c \
	  ft_error.c \
	  ft_params.c 
OBJ = $(SRC:.c=.o)
LIBDIR = ./libft/
LIBNAME = libft
LIB = -lft

all: $(LIB) $(NAME)

$(LIB):
	make -C $(LIBDIR)

$(LIBNAME)_fclean:
	make -C $(LIBDIR) fclean

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -L$(LIBDIR) $(LIB) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -I$(LIBDIR) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: $(LIBNAME)_fclean clean
	rm -rf $(NAME)

re: $(LIBNAME)_fclean fclean all

debug: fclean $(NAME) clean


.PHONY: clean fclean all re
