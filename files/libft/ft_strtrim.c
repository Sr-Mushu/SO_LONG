/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:41:09 by dagabrie          #+#    #+#             */
/*   Updated: 2021/12/28 16:49:38 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char character, char const *set)
{
	size_t	count;

	count = 0;
	while (set[count])
	{
		if (set[count] == character)
			return (1);
		count++;
	}
	return (0);
}

char	*ft_strtrim(char const *string_1, char const *set)
{
	char	*ponter_string;
	size_t	count;
	size_t	start;
	size_t	end;

	start = 0;
	while (string_1[start] && ft_char_in_set(string_1[start], set))
		start++;
	end = ft_strlen(string_1);
	while (end > start && ft_char_in_set(string_1[end - 1], set))
		end--;
	ponter_string = (char *)malloc (sizeof (*string_1) * (end - start + 1));
	if (!ponter_string)
		return (NULL);
	count = 0;
	while (start < end)
		ponter_string[count++] = string_1[start++];
	ponter_string[count] = 0;
	return (ponter_string);
}
