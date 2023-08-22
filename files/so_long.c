/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:37:52 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/22 18:23:41 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// printa a matriz
void	paint_map(char **map, int m_height)
{
	int	i;

	i = 0;
	while (i < m_height)
	{
		ft_printf("%s", map[i]);
		i++;
	}
	ft_printf("\n");
}

// copia a printa
void	copy_matrix(void)
{
	t_map	*p_map;
	int		i;
	int		j;

	p_map = map_data();
	i = 0;
	while (i < p_map->m_height)
	{
		j = 0;
		while (j < p_map->m_length)
		{
			p_map->map[i][j] = p_map->map_orig[i][j];
			j++;
		}
		i++;
	}
}

// Initialize everything of the window and textures.
void	start_wind(void)
{
	t_map	*p_map;

	p_map = map_data();
	create_windo(ft_strlen(p_map->map[0]) - 1, p_map->m_height);
	loude_texture();
	start_texture(ft_strlen(p_map->map[0]) / 2 - 2, p_map->m_height / 2 - 2);
}

// Initialize everything of the map and matrix.
void	start_map(char *fd)
{
	t_map	*p_map;

	p_map = map_data();
	fd_is_vali(fd);
	map_to_array(open(fd, O_RDWR), &p_map->m_height, &p_map->map);
	map_to_array(open(fd, O_RDWR), &p_map->m_height, &p_map->map_orig);
	status_map();
	map_valid();
}

// main
int	main(int argc, char **argv)
{
	t_wind	*p_wind;

	p_wind = window_data();
	if (argc != 2)
		exit_game(30);
	start_map(argv[1]);
	start_wind();
	mlx_key_hook(p_wind->mlx_win, key_hooks, &p_wind);
	mlx_hook(p_wind->mlx_win, 17, 0, close_win, &p_wind);
	mlx_loop(p_wind->mlx);
}
