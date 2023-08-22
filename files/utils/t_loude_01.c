/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_loude_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:34:39 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/22 15:36:27 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	loude_texture(void)
{
	t_wind	*p_wind;

	p_wind = window_data();
	p_wind->t_flor = mlx_xpm_file_to_image(p_wind->mlx, FLOR, &p_wind->x,
			&p_wind->y);
	p_wind->t_wall = mlx_xpm_file_to_image(p_wind->mlx, WALL, &p_wind->x,
			&p_wind->y);
	p_wind->t_play = mlx_xpm_file_to_image(p_wind->mlx, PLAY, &p_wind->x,
			&p_wind->y);
	p_wind->t_coin = mlx_xpm_file_to_image(p_wind->mlx, COIN, &p_wind->x,
			&p_wind->y);
	p_wind->t_exit = mlx_xpm_file_to_image(p_wind->mlx, EXIT, &p_wind->x,
			&p_wind->y);
	p_wind->t_start = mlx_xpm_file_to_image(p_wind->mlx, START, &p_wind->x,
			&p_wind->y);
}

void	flor_texture(int x, int y)
{
	t_wind	*p_wind;

	p_wind = window_data();
	mlx_put_image_to_window(p_wind->mlx, p_wind->mlx_win, p_wind->t_flor, 32
		* x, 32 * y);
}

void	wall_texture(int x, int y)
{
	t_wind	*p_wind;

	p_wind = window_data();
	mlx_put_image_to_window(p_wind->mlx, p_wind->mlx_win, p_wind->t_wall, 32
		* x, 32 * y);
}
