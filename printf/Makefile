# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faozturk <faozturk@42kocaeli.tr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 12:57:10 by faozturk          #+#    #+#              #
#    Updated: 2022/03/04 14:03:03 by faozturk         ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCLUDE = include
LIBFT = libft
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar -rcs

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ)

clean:
			@$(RM) $(OBJ)
			@make clean -C $(LIBFT)

fclean:	clean
			@$(RM) $(NAME)
			@$(RM) $(LIBFT)/libft.a

re:	fclean all

.PHONY:	all clean fclean re



