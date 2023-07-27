/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:28:39 by dagabrie          #+#    #+#             */
/*   Updated: 2021/12/22 10:49:08 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *destiny, const char *sources, size_t size)
{
	size_t	count;
	size_t	size_sources;

	count = 0;
	size_sources = 0;
	while (sources[size_sources] != '\0')
	{
		size_sources++;
	}
	if (size != 0)
	{
		while ((sources[count] != '\0') && (count < size - 1))
		{
			destiny[count] = sources[count];
			count++;
		}
		destiny[count] = '\0';
	}
	return (size_sources);
}
