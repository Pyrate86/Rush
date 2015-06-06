# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 15:35:12 by ghilbert          #+#    #+#              #
#    Updated: 2015/05/03 23:43:27 by ghilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= arkanoid

BIN_PATH	= bin/
SRC_PATH	= ./
OBJ_PATH	= obj/
INC_PATH	= includes/
INCLUDES	= -I $(INC_PATH) -I libft/includes -I glfw/include

SRC_NAME	=	main.c \
				brick.c \
				draw_circle.c \
				draw_square.c \
				colliboule.c \
				init.c \
				get_info.c \
				structs.c \
				callback_error.c \
				collisions.c \
				funcs.c
				
HEADER 		=	$(INC_PATH)arkanoid.h

LIBFT_PATH	= libft
LIBFT_NAME	= -lft
LIBFT		= -L$(LIBFT_PATH) $(LIBFT_NAME)

LIBGL	= -L glfw/src/ -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

OTHER_LIB = -lm

LIBS		= $(LIBFT) $(LIBGL) $(OTHER_LIB)

CC			= gcc
CFLAGS		+= -Wall -Werror -Wextra

SRC			= $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJS 		= $(addprefix $(OBJ_PATH),$(subst .c,.o,$(SRC_NAME)))
BIN			= $(addprefix $(BIN_PATH),$(NAME))


.PHONY: all clean fclean re proper debug debugall

all:	$(NAME)

$(NAME): $(BIN)

$(BIN): glfw/src/libglfw3.a libft/libft.a $(OBJS) $(HEADER) | $(BIN_PATH)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(BIN) $(LIBS)

glfw/src/libglfw3.a:
	git submodule init
	git submodule update
	cd glfw; cmake . ;make

libft/libft.a:
	make -C libft

$(OBJS): | $(OBJ_PATH)

$(OBJ_PATH)%.o : %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@ $(INCLUDES)

$(OBJ_PATH):
	@if [ ! -d "$(OBJ_PATH)" ]; then \
		mkdir $(OBJ_PATH);\
		fi

$(BIN_PATH):
	@if [ ! -d "$(BIN_PATH)" ]; then \
		mkdir $(BIN_PATH);\
		fi

clean:
	@make clean -C libft
	rm -rf $(OBJS)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf libft/libft.a
	rm -rf $(BIN_PATH)

proper: all clean

re:	fclean all

debug:
	CFLAGS="-g" make

debugall:
	CFLAGS="-g" make re
