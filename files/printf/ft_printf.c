/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:40:15 by dagabrie          #+#    #+#             */
/*   Updated: 2022/03/29 15:24:21 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_parameter_value(const char string_01, va_list arguments);

int	ft_printf(const char *string_01, ...)
{
	int			count;
	int			count_return;
	va_list		list;

	count = 0;
	count_return = 0;
	va_start(list, string_01);
	while (string_01[count] != '\0')
	{
		if (string_01[count] == '%')
		{
			count++;
			count_return += is_parameter_value(string_01[count], list);
		}
		else
			count_return += write(1, &string_01[count], 1);
		count++;
	}
	va_end(list);
	return (count_return);
}

int	is_parameter_value(const char string_01, va_list arguments)
{
	int		count;

	if (string_01 == 'c')
		count = ft_print_c(va_arg(arguments, int));
	if (string_01 == 'i')
		count = ft_print_i_d(va_arg(arguments, int));
	if (string_01 == 'd')
		count = ft_print_i_d(va_arg(arguments, unsigned long int));
	if (string_01 == 's')
		count = ft_print_s(va_arg(arguments, char *));
	if (string_01 == 'u')
		count = ft_print_u(va_arg(arguments, unsigned int));
	if (string_01 == 'x')
		count = ft_print_x(va_arg(arguments, unsigned int));
	if (string_01 == 'X')
		count = ft_print_xx(va_arg(arguments, unsigned int));
	if (string_01 == 'p')
		count = ft_print_p(va_arg(arguments, unsigned long));
	if (string_01 == '%')
		count = write(1, "%%", 1);
	return (count);
}
