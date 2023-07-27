/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:45:50 by dagabrie          #+#    #+#             */
/*   Updated: 2021/12/28 15:58:24 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *string, int character, size_t size)
{	
	size_t			count;
	char			*ponter_str;

	ponter_str = (char *)string;
	count = 0;
	while (count < size)
	{
		ponter_str[count] = (char )character;
		count++;
	}
	return (string);
}
/*
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = s;
	while (i < n)
	{
		temp[i] = c;
		i++;
	}
	return (temp);
}
*/