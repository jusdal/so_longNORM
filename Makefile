# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdaly <jdaly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 22:02:56 by jdaly             #+#    #+#              #
#    Updated: 2023/05/31 20:49:17 by jdaly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g


SRC = main.c 0_errors.c 0_so_long_utils.c 1_openmap.c 2_checkmap.c 3_floodfill.c \
	4_renderwindow.c 5_movekeyhandlers.c ./gnl/get_next_line.c \
	./gnl/get_next_line_utils.c

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

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re