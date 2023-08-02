# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 11:52:57 by dagabrie          #+#    #+#              #
#    Updated: 2021/12/28 17:23:16 by dagabrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 	= 	gcc -Wall -Wextra -Werror
AR 	= 	ar rcs
rmO = 	rm *.o

bh 	= 	gnl.h
ft 	= 	gnl.c gnl_utils.c
		


NAME = $(bh:%.h=%.a) 
ft_o = $(ft:%.c=%.o)
	
$(NAME):  $(ft_o) 
	$(AR) $(NAME) $(ft_o)

$(ft_o): $(ft)
	$(CC) -c $(ft)

all: 
	$(NAME)

clean:
	rm -f $(ft_o)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)