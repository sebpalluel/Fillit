#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/01/09 14:05:27 by psebasti          #+#    #+#             *#
#*   Updated: 2017/01/21 12:19:51 by psebasti         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = fillit

SRC = main.c \
	  draw.c \
	  read2.c \
	  organize.c \
	  solve.c \
	  tetri.c

OBJ		=	$(SRC:.c=.o)

CMP		=	gcc

FLAGS	=	-Wall -Wextra -Werror

DEBUG	=	-g

LIB = -L libft/ -lft

all : lib $(NAME)

$(NAME) : 
	$(CMP) $(DEBUG) $(FLAGS) -o $(NAME) $(SRC) $(LIB)

lib :
	make re -C libft

clean :
	rm -rf $(OBJ)
	make -C libft clean

fclean : clean
	rm -rf $(NAME)
	make -C libft fclean

re : fclean all
