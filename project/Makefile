#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/03/07 09:32:29 by nhuber            #+#    #+#             *#
#*   Updated: 2017/03/01 22:38:01 by nhuber           ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CC = gcc
FLAGS = -Wall -Wextra -Werror
LEMIN = lem-in
FILES = lem_in.c set.c map.c print.c read.c room.c error.c solve.c \
			params.c utility.c utility2.c utility3.c get.c get2.c \
			get_next_line.c option.c

F_DIR = srcs
SRCS = $(addprefix $(F_DIR)/, $(FILES))

O_DIR = objs
OBJS = $(addprefix $(O_DIR)/, $(FILES:.c=.o))

HEADER = lem_in.h get_next_line.h
H_DIR = header
INC = $(addprefix $(H_DIR)/, $(HEADER))
INCLUDE = -I $(L_DIR) -I $(V_DIR) -I $(H_DIR) 

L_DIR = libft
V_DIR = libvector
LIBFT = $(L_DIR)/libft.a
LIBVEC = $(V_DIR)/libvector.a
LIBLINK = -L ./$(V_DIR) -L ./$(L_DIR) -lft -lvector

all: libft libvector $(LEMIN)

$(LEMIN): $(OBJS) $(LIBFT) $(LIBVEC)
	@echo Project : $(LEMIN)
	@echo "\t"- Compiler : $(CC)
	@echo "\t"- Flags : $(FLAGS)
	@$(CC) $(FLAGS) -o $@ $(OBJS) $(LIBLINK)

$(O_DIR)/%.o: $(F_DIR)/%.c $(INC)
	@mkdir -p $(O_DIR)
	@$(CC) $(FLAGS) $(INCLUDE) -c -o $@ $<
	@echo "Creation de "$<" OK"

libft:
	@make -C $(L_DIR)

libvector:
	@make -C $(V_DIR)

clean:
	@echo clean :"\n\tTemporary and binary files deleted"
	@rm -rf $(O_DIR)
	@make -C $(V_DIR) clean
	@make -C $(V_DIR) clean

fclean: clean
	@rm -f $(LEMIN)
	@rm -f $(LIBFT)
	@rm -f $(LIBVEC)
	@echo fclean :"\n\t"$(LEMIN) deleted
	@echo "\t"$(LIBVEC) "\n""\t"$(LIBFT) deleted

norme:
	@echo "\t\tNORME ERROR\n----------------------------------------------"
	@norminette > checking
	@cat checking

re : fclean all

.PHONY : all clean fclean re libft libvector
