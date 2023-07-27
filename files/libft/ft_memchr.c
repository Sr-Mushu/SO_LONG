/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:28:51 by dagabrie          #+#    #+#             */
/*   Updated: 2021/12/21 14:52:27 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *string, int character, size_t number)
{
	const char	*ponter_string;
	size_t		count;

	ponter_string = (const char *)string;
	count = -1;
	while (++count < number)
	{
		if (*(ponter_string + count) == (char)character)
			return ((void *)ponter_string + count);
	}
	return (0);
}
