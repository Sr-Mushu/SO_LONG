/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:12:05 by dagabrie          #+#    #+#             */
/*   Updated: 2021/12/20 15:20:51 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int character)
{
	int	count;

	count = ft_strlen(string);
	while (count >= 0)
	{
		if (string[count] == (char) character)
			return ((char *)&string[count]);
		count--;
	}
	return (0);
}
