/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_loude_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:39:22 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/22 15:36:37 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	play_texture(int x, int y)
{
	t_wind	*p_wind;

	p_wind = window_data();
	mlx_put_image_to_window(p_wind->mlx, p_wind->mlx_win, p_wind->t_play, 32
		* x, 32 * y);
}

void	coin_texture(int x, int y)
{
	t_wind	*p_wind;

	p_wind = window_data();
	mlx_put_image_to_window(p_wind->mlx, p_wind->mlx_win, p_wind->t_coin, 32
		* x, 32 * y);
}

void	start_texture(int x, int y)
{
	t_wind	*p_wind;

	p_wind = window_data();
	mlx_put_image_to_window(p_wind->mlx, p_wind->mlx_win, p_wind->t_start, 32
		* x, 32 * y);
}

void	exit_texture(int x, int y)
{
	t_wind	*p_wind;

	p_wind = window_data();
	mlx_put_image_to_window(p_wind->mlx, p_wind->mlx_win, p_wind->t_exit, 32
		* x, 32 * y);
}
