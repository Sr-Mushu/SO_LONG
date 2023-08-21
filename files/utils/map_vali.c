/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vali.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:08:30 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/18 18:09:51 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fd_is_ber(char *fd_name)
{
	int			len;
	const char	*extin;

	extin = ".ber";
	len = ft_strlen(fd_name);
	if (len >= 4 && ft_strncmp(fd_name + len - 4, extin, ft_strlen(extin)) != 0)
		exit_game(3);
}

void	check_path(int x, int y)
{
	t_map	*p_map;

	p_map = map_data();
	if (p_map->map[x][y] == 'P' || p_map->map[x][y] == 'E'
		|| p_map->map[x][y] == 'C' || p_map->map[x][y] == '0')
	{
		if (p_map->map[x][y] == 'P')
			p_map->map[x][y] = 'o';
		else if (p_map->map[x][y] == 'E')
		{
			p_map->map[x][y] = 'o';
			p_map->flg_exit = 1;
		}
		else if (p_map->map[x][y] == 'C')
		{
			p_map->map[x][y] = 'o';
			p_map->flg_coins += 1;
		}
		else if (p_map->map[x][y] == '0')
			p_map->map[x][y] = 'o';
		check_path(x + 1, y);
		check_path(x, y + 1);
		check_path(x - 1, y);
		check_path(x, y - 1);
	}
}

void	valid_chars(void)
{
	t_map	*p_map;

	p_map = map_data();
	paint_map(p_map->map, p_map->m_height);
	check_path(p_map->play_x, p_map->play_x);
	if (p_map->num_exit != 1)
		exit_game(16);
	if (p_map->num_play != 1)
		exit_game(15);
	if (p_map->flg_exit != 1)
		exit_game(14);
	if (p_map->num_coins != p_map->flg_coins)
		exit_game(13);
	copy_matrix();
}

void	is_squer(void)
{
	t_map	*p_map;
	int		j;

	p_map = map_data();
	p_map->m_length = ft_strlen(p_map->map[0]);
	j = 0;
	while (j < p_map->m_height)
	{
		if (p_map->map[j][ft_strlen(p_map->map[j]) - 1] != '\n')
		{
			if (ft_strlen(p_map->map[j]) + 1 != p_map->m_length)
				exit_game(10);
		}
		else if (ft_strlen(p_map->map[j]) != p_map->m_length)
			exit_game(9);
		j++;
	}
}

void	is_valid(void)
{
	int		i;
	int		j;
	int		k;
	t_map	*p_map;

	p_map = map_data();
	i = -1;
	j = ft_strlen(p_map->map[0]);
	p_map->m_length = j - 1;
	while (p_map->map && p_map->map[++i])
	{
		k = j - 1;
		if (!p_map->map[i + 1])
			j--;
		if ((int)ft_strlen(p_map->map[i]) != j)
			exit_game(9);
		while (--k >= 0)
		{
			if ((i == 0 || !p_map->map[i + 1]) && p_map->map[i][k] != '1')
			{
				printf("1\n");
				exit_game(11);
			}
			if ((k == 0 || k == (j - 2)) && p_map->map[i][k] != '1')
			{
				printf("2\n");
				exit_game(11);
			}
		}
	}
}

void	map_valid(void)
{
	t_map	*p_map;

	p_map = map_data();
	status_map();
	is_squer();
	is_valid();
	valid_chars();
}
