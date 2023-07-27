/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:10:16 by dagabrie          #+#    #+#             */
/*   Updated: 2021/12/23 15:23:19 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *string, unsigned int start, size_t length)
{
	char	*sub;
	size_t	count;
	size_t	sub_length;

	if (!string)
		return (NULL);
	if ((unsigned int)ft_strlen(string) <= start)
		sub_length = 0;
	else if ((size_t)ft_strlen(string) <= length)
		sub_length = ft_strlen(string) - start;
	else
		sub_length = length;
	sub = (char *)malloc(sizeof(char) * (sub_length + 1));
	if (!sub)
		return (NULL);
	count = -1;
	while (++count < sub_length)
		sub[count] = string[start + count];
	sub[count] = '\0';
	return (sub);
}
