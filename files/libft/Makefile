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

bh 	= 	libft.h
ft 	= 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_strdup.c ft_strmapi.c ft_strtrim.c ft_strjoin.c \
			ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
			ft_bzero.c ft_toupper.c ft_tolower.c ft_atoi.c ft_calloc.c ft_itoa.c ft_substr.c \
			ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_split.c ft_striteri.c
		


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