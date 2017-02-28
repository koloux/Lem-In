#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/03/07 09:32:29 by nhuber            #+#    #+#             *#
#*   Updated: 2017/02/24 10:34:48 by nhuber           ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = lem-in
H_DIR = header
F_DIR = srcs
L_DIR = libft
V_DIR = libvector
FILES = $(F_DIR)/lem_in.c \
		$(F_DIR)/get.c \
		$(F_DIR)/map.c \
		$(F_DIR)/print.c \
		$(F_DIR)/room.c \
		$(F_DIR)/utility.c \
		$(F_DIR)/utility2.c \
		$(F_DIR)/utility3.c \
		$(F_DIR)/get_next_line.c \
		$(F_DIR)/error.c \
		$(F_DIR)/params.c
TMP = Makefile~ $(NAME)~ $(FILES:.c=.c~)
OBJ = $(FILES:.c=.o)

all : $(NAME)

$(NAME) :
	@cd $(L_DIR) && $(MAKE)
	@cd $(V_DIR) && $(MAKE)
	@echo Project : $(NAME)
	@echo "\t"- Compiler : $(CC)
	@echo "\t"- Flags : $(FLAGS)
	@$(CC) -o $(NAME) $(FLAGS) $(FILES) -L $(V_DIR) -L $(L_DIR) -lft -lvector -I $(H_DIR) 

clean :
	@echo clean :"\n\tTemporary and binary files deleted"
	@rm -f $(TMP) $(OBJ)
	@cd $(L_DIR) && $(MAKE) $@
	@cd $(V_DIR) && $(MAKE) $@

fclean : clean
	@echo fclean :"\n\t"$(NAME) deleted
	@rm -f $(NAME)
	@cd $(L_DIR) && $(MAKE) $@
	@cd $(V_DIR) && $(MAKE) $@

norme :
	@echo "\t\tNORME ERROR\n----------------------------------------------"
	@norminette > checking
	@cat checking

re : fclean all

.PHONY : all clean fclean re
