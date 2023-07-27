/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:56:43 by dagabrie          #+#    #+#             */
/*   Updated: 2021/12/23 15:19:12 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *string, char (*funcion)(unsigned int, char))
{
	char	*ponter_string;
	size_t	count;

	ponter_string = ft_strdup(string);
	if (!ponter_string)
		return (NULL);
	count = 0;
	while (ponter_string[count])
	{
		ponter_string[count] = (*funcion)(count, ponter_string[count]);
		count++;
	}
	return (ponter_string);
}
