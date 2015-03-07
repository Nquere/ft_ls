# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nquere <nquere@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/05 16:27:07 by nquere            #+#    #+#              #
#    Updated: 2015/03/05 16:32:09 by nquere           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c

OBJ = $(SRC:.c=.o)

CC = gcc

all : $(NAME)

$(NAME) : $(OBJ)
	@($(CC) $(CFLAGS) -c $(SRC))
	@($(CC) -o $(NAME) $(OBJ) -L /usr/bin -ltermcap)
	@echo "\033[35m$(NAME) created !\033[0m"

%.o:%.c
	@($(CC) -c $(SRC) $(CFLAGS))

clean :
	@(rm -f $(OBJ))
	@echo "\033[31mObject files deleted !\033[0m"

fclean : clean
	@(rm -f $(NAME))
	@echo "\033[31m$(NAME) deleted !\033[0m"

re : fclean all
