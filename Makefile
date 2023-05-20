# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdaly <jdaly@student.42bangkok.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 22:02:56 by jdaly             #+#    #+#              #
#    Updated: 2023/05/18 22:06:56 by jdaly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

 #put mlx in mlx folder
 #you need libmlx.dylib in the same directory as build target bc it's a dynamic library
