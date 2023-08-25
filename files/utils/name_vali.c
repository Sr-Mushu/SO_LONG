/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_vali.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:53:10 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/25 19:30:55 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*fd_get_name(char *fd_name)
{
	char	*filename;

	filename = ft_strrchr(fd_name, '/');
	if (filename == NULL)
	{
		filename = fd_name;
	}
	else
	{
		filename++;
	}
	return (filename);
}

void	fd_is_null(char *fd_name)
{
	if (ft_strlen(fd_name) <= 1)
		exit_game(25);
}

void	fd_is_ber(char *fd_name)
{
	int			len;
	const char	*extin;

	extin = ".ber";
	len = ft_strlen(fd_name);
	if (len <= 4)
		exit_game(25);
	if (len > 4 && ft_strncmp(fd_name + len - 4, extin, ft_strlen(extin)) != 0)
		exit_game(25);
}

void	fd_is_vali(char *fd_name)
{
	if (open(fd_name, O_RDWR) == -1)
		exit_game(24);
	fd_name = fd_get_name(fd_name);
	ft_printf("file name : %s \n", fd_name);
	fd_is_null(fd_name);
	fd_is_ber(fd_name);
}
