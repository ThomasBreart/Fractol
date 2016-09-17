# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/16 16:31:34 by tbreart           #+#    #+#              #
#    Updated: 2016/09/17 03:20:26 by tbreart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
SRC := $(filter %.c, $(shell find . -type f))
SRC_FILES := $(shell basename -a $(SRC))
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c -I includes/ $(SRC)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -I includes/ -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
