/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:01:27 by dagabrie          #+#    #+#             */
/*   Updated: 2021/12/28 15:01:48 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	character_difrente(char character_01, char character_02)
{
	return (character_01 != character_02);
}

int	ft_memcmp(const void *string_01, const void *string_02, size_t size)
{
	unsigned char	*ponter_string_01;
	unsigned char	*ponter_string_02;
	size_t			count;

	ponter_string_01 = (unsigned char *)string_01;
	ponter_string_02 = (unsigned char *)string_02;
	count = 0;
	while (count < size)
	{
		if (character_difrente(ponter_string_01[count],
				ponter_string_02[count]) == 1)
			return (ponter_string_01[count] - ponter_string_02[count]);
		count++;
	}
	return (0);
}
