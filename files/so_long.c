/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/17 16:56:59 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//printa a matriz
void paint_map(char **map, int m_height) 
{
	for (int i = 0; i < m_height; i++) 
		printf("%s\n", map[i]);
}


void start_wind(void)
{
	t_map	*p_map;

	p_map = map_data(); 
	create_windo(ft_strlen(p_map->map[0])-1,p_map->m_height);
	loude_texture();
	start_texture(ft_strlen(p_map->map[0])/2-2,p_map->m_height/2-2);
}

void start_map(char *fd)
{
	t_map	*p_map;

	p_map = map_data();
	p_map->strat_flag = 1;
	fd_is_ber(fd);
	map_to_array(open(fd ,O_RDWR) , &p_map->m_height, &p_map->map);
	map_to_array(open(fd ,O_RDWR) , &p_map->m_height, &p_map->map_orig);
	paint_map(p_map->map, p_map->m_height);
	status_map();
	//map_valid();
}

//main
int	main(int argc, char **argv)
{
	t_wind 	*p_wind;

	p_wind = window_data();
	start_map(argv[1]);
	start_wind();
	mlx_key_hook(p_wind->mlx_win, key_hooks, &p_wind);
	mlx_loop(p_wind->mlx);

}
