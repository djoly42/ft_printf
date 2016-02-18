# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djoly <djoly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/23 18:51:39 by mdriay            #+#    #+#              #
#    Updated: 2016/01/29 16:52:41 by djoly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = #-Wall -Wextra -Werror

RM = rm -f

HEADERS = -I /

SRC=ft_printf.c fonct_c.c token.c ft_check_env.c\
ft_putchar.c ft_putnbr.c ft_putstr.c ft_atoi.c ft_strchr.c \
ft_nbrlen.c fonct_d.c\

OBJ = $(SRC:.c=.o)

$(NAME): ft_printf.h
	$(CC) $(CFLAGS) -c $(SRC) $(HEADERS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)


aclean: all clean

re: fclean all
