/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:04:30 by dagabrie          #+#    #+#             */
/*   Updated: 2021/12/28 16:36:51 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destiny, const void *source, size_t size)
{
	int	count;

	if (destiny > source)
	{
		count = (int)size - 1;
		while (count >= 0)
		{
			*(char *)(destiny + count) = *(char *)(source + count);
			count--;
		}
	}
	else
		ft_memcpy(destiny, source, size);
	return (destiny);
}
