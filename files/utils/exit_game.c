/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:13:34 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/15 18:29:10 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void destroy_wind(void)
{
	t_wind *p_wind;

	p_wind = window_data();
	mlx_destroy_display(p_wind->mlx);
	free(p_wind->mlx);
}

void destroy_img(void)
{
	t_wind *p_wind;

	p_wind = window_data();
	if(p_wind->t_coin)
		mlx_destroy_image(p_wind->mlx,p_wind->t_coin);
	if(p_wind->t_exit)
		mlx_destroy_image(p_wind->mlx,p_wind->t_exit);
	if(p_wind->t_flor)
		mlx_destroy_image(p_wind->mlx,p_wind->t_flor);
	if(p_wind->t_play)
		mlx_destroy_image(p_wind->mlx,p_wind->t_play);
	if(p_wind->t_start)
		mlx_destroy_image(p_wind->mlx,p_wind->t_start);
	if(p_wind->t_wall)
		mlx_destroy_image(p_wind->mlx,p_wind->t_wall);
}

void destroy_map(void)
{
  	t_map	*p_map;
	int i;
	
	i = 0;
	p_map = map_data();
    while (i < p_map->m_height) {
        free(p_map->map[i]);
        i++;
    }
    free(p_map->map);
}

void exit_game(int code)
{
	if(code == 10)
		write(2,"Mapa invalido contiudo fora do mapa\n",37);
	
	destroy_wind();
	destroy_img();
	destroy_map();
	exit(code);
}