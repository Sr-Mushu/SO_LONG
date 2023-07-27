/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:17:32 by dagabrie          #+#    #+#             */
/*   Updated: 2021/12/22 15:45:26 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*pointer;
	size_t	length;

	length = ft_strlen(string) + 1;
	pointer = malloc(sizeof(char) * length);
	if (!pointer)
		return (0);
	pointer = ft_memcpy(pointer, string, length);
	return (pointer);
}
