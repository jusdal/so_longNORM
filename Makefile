# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 22:02:56 by jdaly             #+#    #+#              #
#    Updated: 2023/05/30 21:49:05 by jdaly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra


SRC = main.c 1checkmap.c floodfill.c 3renderwindow.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
OBJ = $(SRC:.c=.o)

MLX_DIR	:= ./mlx
MINILIBX	:= $(MLX_DIR)/libmlx.a

FRAME_W := -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJ) $(MINILIBX) -Lmlx -lmlx $(FRAME_W) -o $@

$(MINILIBX):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

 #put mlx in mlx folder
 #you need libmlx.dylib in the same directory as build target bc it's a dynamic library
