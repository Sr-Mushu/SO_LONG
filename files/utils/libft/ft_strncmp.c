/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:06:32 by dagabrie          #+#    #+#             */
/*   Updated: 2021/12/22 11:48:43 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	string_difrente(char character_01, char character_02)
{
	return (character_01 != character_02
		|| character_01 == 0
		|| character_02 == 0);
}

int	ft_strncmp(const char *string_01, const char *string_02, size_t size)
{
	size_t			count;

	count = 0;
	while (count < size)
	{
		if (string_difrente(string_01[count],
				string_02[count]) == 1)
			return (
				(unsigned char)string_01[count]
				- (unsigned char)string_02[count]
			);
		count++;
	}
	if (count < size)
		return (string_01[count] - string_02[count]);
	return (0);
}
