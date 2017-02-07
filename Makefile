#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/01/09 14:05:27 by psebasti          #+#    #+#             *#
#*   Updated: 2017/01/23 15:34:11 by psebasti         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME	=	fillit
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRC		=	main.c \
			draw.c \
			map.c \
			read.c \
			organize.c \
			solve.c \
			tetri.c

EXT		=	Makefile

OBJ		=	$(SRC:.c=.o)

LIB = -L libft/ -lft

all : lib $(NAME)

$(NAME) : $(OBJ) $(EXT)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIB)

lib :
	@echo "compiling libft..."
	@make -C libft --no-print-directory
	@echo "done."

clean :
	rm -rf $(OBJ)
	@echo "cleaning libft..."
	@make -C libft clean --no-print-directory
	@echo "done."

fclean : clean
	rm -rf $(NAME)
	@echo "full cleaning libft..."
	@make -C libft fclean --no-print-directory
	@echo "done."

re : fclean all
