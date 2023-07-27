/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:53:00 by dagabrie          #+#    #+#             */
/*   Updated: 2021/12/28 16:32:32 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destiny, const void *source, size_t size)
{
	size_t			count;
	char			*ponter_destiny;
	char			*ponter_source;

	count = 0;
	ponter_destiny = (char *)destiny;
	ponter_source = (char *)source;
	if (ponter_source == 0 && ponter_destiny == 0)
		return (NULL);
	while (count < size)
	{
		ponter_destiny[count] = ponter_source[count];
		count++;
	}
	return (destiny);
}
