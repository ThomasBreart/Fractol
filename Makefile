
NAME = fractol
CC = cc
FLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/
LMLX = -lmlx -framework OpenGL -framework AppKit -L/usr/X11/lib
IDIR = includes/
SRC := $(filter %.c, $(shell find src -type f))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "-> Building libft"
	@make -C $(LIBFT)
	@echo "-> Linkin"
	@$(CC) -o $@ $(OBJ) $(FLAGS) $(LIBFT)libft.a $(LMLX) -I $(IDIR)
	@echo "-> Perfect !"

%.o: %.c
	@echo "-> Compiling $<"
	@$(CC) $(FLAGS) -I inc/ -o $@ -c $<

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
