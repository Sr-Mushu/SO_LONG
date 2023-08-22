/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:38:53 by dagabrie          #+#    #+#             */
/*   Updated: 2022/03/29 13:55:34 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convertexa(unsigned int n, int count, char *base)
{
	if (n > 9)
		count = convertexa(n / 10, count, base);
	return (count + write(1, &base[n % 10], 1));
}

int	ft_print_u(unsigned int argument)
{
	return (convertexa(argument, 0, "0123456789"));
}
