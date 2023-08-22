# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 16:38:26 by dagabrie          #+#    #+#              #
#    Updated: 2023/08/22 22:08:29 by dagabrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

PRINTF_P = ./printf
LIBFT_P = ./libft
GNL_P = ./gnl

CC		=	cc
CFLAGS	=	-Imlx_linux -g -fsanitize=address #-Wall -Werror -Wextra
MLX_L	=	-L ../mlx_linux -lmlx -lXext -lX11
LIBFT_L = $(LIBFT_P)/libft.a
GNL_L = $(GNL_P)/gnl.a
PRINTF_L = $(PRINTF_P)/ft_printf.a

SRCS	=	so_long.c	\
./utils/t_loude_01.c	\
./utils/t_loude_02.c	\
./utils/key_hooks.c		\
./utils/exit_game.c		\
./utils/static_data.c	\
./utils/loude_map.c		\
./utils/map_vali.c		\
./utils/name_vali.c		\
./utils/map_status.c

all:	$(PRINTF_L) $(LIBFT_L) $(GNL_L) $(NAME)

$(PRINTF_L):
	make -C $(PRINTF_P)

$(LIBFT_L):
	make -C $(LIBFT_P)

$(GNL_L):
	make -C $(GNL_P)

$(NAME): $(SRCS)
			make -C ../mlx_linux
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(MLX_L) $(PRINTF_L) $(LIBFT_L) $(GNL_L)


clean:
			make clean -C ../mlx_linux
			make clean -C $(PRINTF_P)
			make clean -C $(LIBFT_P)
			make clean -C $(GNL_P)

fclean:		clean
			rm -rf $(NAME)
			make fclean -C $(PRINTF_P)
			make fclean -C $(LIBFT_P)
			make fclean -C $(GNL_P)

re:			fclean all