# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/16 16:31:34 by tbreart           #+#    #+#              #
#    Updated: 2016/09/18 02:04:06 by tbreart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

## Sources
SRC = $(filter %.c, $(shell find . -type f))
SRC_FILES = $(shell basename $(SRC))
INC = -I includes

## Commands
CC = cc

## Options
CFLAGS = -Wall -Werror -Wextra

## Obj
OBJ = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(INC) $(SRC)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
