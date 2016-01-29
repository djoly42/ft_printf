
NAME = printf

FLAGS = -Wall -Wextra -Werror

SRC = main.c ft_printf.c token.c  fonct_c.c ft_check_env.c

LIB = -L libft -lft

OBJ = $(SRC:.c=.o)


$(NAME) :
	gcc  -c $(SRC) $(FLAGS)
	gcc -o $(NAME) $(OBJ) $(LIB)

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

aclean: all clean

.PHONY: all clean fclean re
