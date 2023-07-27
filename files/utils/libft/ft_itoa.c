/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:51:29 by dagabrie          #+#    #+#             */
/*   Updated: 2021/12/23 12:01:29 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_length(int number)
{
	int	number_length;

	number_length = 0;
	if (number < 0)
		number_length++;
	while (number)
	{
		number /= 10;
		number_length++;
	}
	return (number_length);
}

static char	*convert_int(int number, int number_length, char *string)
{
	int	temp;
	int	signal;

	string[number_length--] = '\0';
	signal = 0;
	if (number < 0)
		signal = 1;
	while (number != 0)
	{
		if (number < 0)
			temp = (number % 10) * (-1);
		else
			temp = number % 10;
		string[number_length--] = temp + 48;
		number = number / 10;
	}
	if (signal == 1)
		string[number_length--] = '-';
	return (string);
}

char	*ft_itoa(int number)
{
	char	*string;
	int		number_length;

	if (number == 0)
	{
		string = (char *)malloc(sizeof(char) * 2);
		string[0] = '0';
		string[1] = 0;
		return (string);
	}
	number_length = count_length(number);
	string = (char *)malloc(sizeof(char) * (number_length + 1));
	if (string == NULL)
		return (NULL);
	string = convert_int(number, number_length, string);
	return (string);
}
