# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 16:38:26 by dagabrie          #+#    #+#              #
#    Updated: 2023/07/27 17:00:41 by dagabrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -Imlx_linux -g -fsanitize=address

LIBS	=	-L ../mlx_linux -lmlx -lXext -lX11

SRCS	=	so_long.c

all:		$(NAME)

$(NAME):
			make -C ../mlx_linux
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBS)

clean:
			make clean -C ../mlx_linux

fclean:		clean
			rm -rf $(NAME)

re:			fclean all