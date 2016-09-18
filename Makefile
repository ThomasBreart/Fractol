# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbreart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/18 02:14:47 by tbreart           #+#    #+#              #
#    Updated: 2016/09/18 23:05:33 by tbreart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
FLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/
LMLX = -lmlx
FRAMEWORK = -framework OpenGL -framework AppKit -framework opencl
IDIR = -I includes
SRC := $(filter %.c, $(shell find src -type f))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ./includes/fractol.h ./Makefile
	@echo "-> Building libft"
	@make -C $(LIBFT)
	@echo "-> Linkin"
	@$(CC) -o $@ $(OBJ) $(FLAGS) $(LIBFT)libft.a $(LMLX) $(FRAMEWORK) $(IDIR)
	@echo "-> Perfect !"

%.o: %.c
	@echo "-> Compiling $<"
	@$(CC) $(FLAGS) -I includes/ -o $@ -c $<

clean:
	@echo "Removing obj files"
	@rm -f $(OBJ)
	@make -C $(LIBFT) clean

fclean: clean
	@echo "Removing binary"
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
