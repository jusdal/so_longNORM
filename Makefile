# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdaly <jdaly@student.42bangkok.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 22:02:56 by jdaly             #+#    #+#              #
#    Updated: 2023/05/28 23:28:54 by jdaly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong
CC = cc
CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address #-framework OpenGL -framework AppKit


SRC = checkmap.c floodfill.c get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: clean all

 #put mlx in mlx folder
 #you need libmlx.dylib in the same directory as build target bc it's a dynamic library
