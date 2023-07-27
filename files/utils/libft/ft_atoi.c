/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:10:06 by dagabrie          #+#    #+#             */
/*   Updated: 2021/12/22 15:44:29 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	is_positive(char character)
{
	return (character == '+');
}

char	is_negative(char character)
{
	return (character == '-');
}

char	is_space(char character)
{
	return (character == '\t' || character == '\n'
		|| character == '\v' || character == '\f'
		|| character == '\r' || character == ' ');
}

int	ft_atoi(const char *string)
{
	int	nunber;
	int	count;
	int	negative;

	nunber = 0;
	count = 0;
	while (is_space(string[count]) == 1)
		count++;
	if (is_negative(string[count]) == 1 || is_positive(string[count]) == 1)
	{
		negative = is_negative(string[count]);
		count++;
	}
	while (ft_isdigit(string[count]) == 1)
	{
		nunber = nunber * 10 + string[count] - 48;
		count++;
	}
	if (negative == 1)
		return (nunber * -1);
	return (nunber);
}
