/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:38:56 by dagabrie          #+#    #+#             */
/*   Updated: 2022/03/29 13:55:21 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convertexa(unsigned int n, int count, char *base)
{
	if (n > 15)
		count = convertexa(n / 16, count, base);
	return (count + write(1, &base[n % 16], 1));
}

int	ft_print_x(unsigned int argument)
{
	return (convertexa(argument, 0, "0123456789abcdef"));
}
