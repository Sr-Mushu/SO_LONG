/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:43:39 by dagabrie          #+#    #+#             */
/*   Updated: 2022/03/29 13:55:00 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "./libft-printf/libft.h"

# define LOWER_HEXBASE "0123456789abcdef" 
# define UPPER_HEXBASE "0123456789ABCDEF"

int	ft_printf(const char *string, ...);
//printf

int	ft_print_c(int argument);
//Prints a single character.

int	ft_print_p(unsigned long argument);
//Prints an integer in base 10.

int	ft_print_i_d(int argument);
//Prints a decimal (base 10) number.

int	ft_print_s(char *argument);
//Prints a string (as defined by the common C convention).

int	ft_print_u(unsigned int argument);
//Prints an unsigned decimal (base 10) number.

int	ft_print_x(unsigned int argument);
//Prints a number in hexadecimal (base 16) lowercase format.

int	ft_print_xx(unsigned int argument);
//Prints a number in hexadecimal (base 16) uppercase format.

#endif /*FT_PRINTF_H*/