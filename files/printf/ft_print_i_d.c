/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:38:50 by dagabrie          #+#    #+#             */
/*   Updated: 2022/03/29 13:56:14 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convertexa(unsigned long long n, int count, char *base)
{
	if (n > 9)
		count = convertexa(n / 10, count, base);
	return (count + write(1, &base[n % 10], 1));
}

int	ft_print_i_d(int argument)
{
	long long	signal;
	int			count;

	signal = 1;
	count = 0;
	if (argument < 0)
	{
		signal = -1;
		count += write(1, "-", 1);
	}
	return (count + convertexa((argument * signal), 0, "0123456789"));
}
