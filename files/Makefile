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

LIBFT_P = ./libft
GNL_P = ./gnl

CC		=	cc
CFLAGS	=	#-Wall -Werror -Wextra -Imlx_linux -g -fsanitize=address

MLX_L	=	-L ../mlx_linux -lmlx -lXext -lX11
LIBFT_L = $(LIBFT_P)/libft.a
GNL_L = $(GNL_P)/gnl.a

SRCS	=	so_long.c



all:	$(LIBFT_L) $(GNL_L) $(NAME)

$(LIBFT_L):
	make -C $(LIBFT_P)

$(GNL_L):
	make -C $(GNL_P)

$(NAME):
			make -C ../mlx_linux
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(MLX_L) $(LIBFT_L) $(GNL_L)


clean:
			make clean -C ../mlx_linux
			make clean -C $(LIBFT_P)
			make clean -C $(GNL_P)

fclean:		clean
			rm -rf $(NAME)
			make fclean -C $(LIBFT_P)
			make fclean -C $(GNL_P)

re:			fclean all