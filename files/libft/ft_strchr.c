/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:00:15 by dagabrie          #+#    #+#             */
/*   Updated: 2021/12/28 19:13:45 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int character)
{
	size_t	count;

	count = 0;
	while (count <= ft_strlen(string))
	{
		if (string[count] == (char) character)
			return ((char *)&string[count]);
		count++;
	}
	return (0);
}
