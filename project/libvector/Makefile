# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/30 17:55:34 by nhuber            #+#    #+#              #
#    Updated: 2017/03/01 14:23:31 by nhuber           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libvector.a
AR = ar rc
FILES = vector_construct.c \
		vector_resize.c \
		vector_add.c \
		vector_delone.c \
		items_cpy.c \
		vector_destruct.c
TMP = Makefile~ libvetor.h~ $(FILES:.c=.c~)
OBJ = $(FILES:.c=.o)

all : $(NAME)

$(NAME) :
	@echo Library $(NAME) compiled
	@$(CC) $(FLAGS) -c $(FILES) && ar rc $(NAME) $(OBJ)

clean :
	@rm -f $(OBJ) $(TMP)

fclean : clean
	@rm -f $(NAME)
	@echo "\t"$(NAME) deleted

re : all clean

.PHONY : all clean fclean re
