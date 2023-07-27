/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:26:10 by dagabrie          #+#    #+#             */
/*   Updated: 2021/12/27 14:31:52 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *string_01, char const *string_02)
{
	char	*string_1_and_2;
	size_t	string_01_length;
	size_t	string_02_length;
	size_t	count_01;
	size_t	count_02;

	if (!string_01 || !string_02)
		return (NULL);
	string_01_length = ft_strlen(string_01);
	string_02_length = ft_strlen(string_02);
	string_1_and_2 = (char *)malloc(sizeof(char)
			* (string_01_length + string_02_length + 1));
	if (!string_1_and_2)
		return (NULL);
	count_01 = -1;
	while (++count_01 < string_01_length)
		string_1_and_2[count_01] = string_01[count_01];
	count_02 = -1;
	while (++count_02 < string_02_length)
	{
		string_1_and_2[count_01] = string_02[count_02];
		count_01++;
	}
	string_1_and_2[count_01] = '\0';
	return (string_1_and_2);
}
