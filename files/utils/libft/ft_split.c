/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:13:36 by dagabrie          #+#    #+#             */
/*   Updated: 2021/12/28 19:19:43 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verify_if_is_c(char str, char c)
{
	return (str == c);
}

static int	count_words(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && verify_if_is_c(*str, c))
			str++;
		if (*str && !verify_if_is_c(*str, c))
		{
			count++;
			while (*str && !verify_if_is_c(*str, c))
				str++;
		}
	}
	return (count);
}

static char	*malloc_word(char *str, char c)
{
	char	*word;
	int		x;

	x = 0;
	while (str[x] && !verify_if_is_c(str[x], c))
		x++;
	word = (char *)malloc(sizeof(char) * x + 1);
	x = 0;
	while (str[x] && !verify_if_is_c(str[x], c))
	{
		word[x] = str[x];
		x++;
	}
	word[x] = '\0';
	return (word);
}

char	**ft_split(char const *str, char c)
{
	int		x;
	char	**result;

	if (!str)
		return (NULL);
	x = 0;
	result = (char **)malloc(sizeof(char *)
			* (count_words((char *)str, c) + 1));
	if (!result)
		return (NULL);
	while (*str)
	{
		while (*str && verify_if_is_c(*str, c))
			str++;
		if (*str && !verify_if_is_c(*str, c))
		{
			result[x] = malloc_word((char *)str, c);
			x++;
			while (*str && !verify_if_is_c(*str, c))
				str++;
		}
	}
	result[x] = NULL;
	return (result);
}
