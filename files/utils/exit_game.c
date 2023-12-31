/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:13:34 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/26 19:38:31 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_wind(void)
{
	t_wind	*p_wind;

	p_wind = window_data();
	mlx_destroy_window(p_wind->mlx,p_wind->mlx_win);
	mlx_destroy_display(p_wind->mlx);
	free(p_wind->mlx);
}

void	destroy_img(void)
{
	t_wind	*p_wind;

	p_wind = window_data();
	if (p_wind->t_coin)
		mlx_destroy_image(p_wind->mlx, p_wind->t_coin);
	if (p_wind->t_exit)
		mlx_destroy_image(p_wind->mlx, p_wind->t_exit);
	if (p_wind->t_flor)
		mlx_destroy_image(p_wind->mlx, p_wind->t_flor);
	if (p_wind->t_play)
		mlx_destroy_image(p_wind->mlx, p_wind->t_play);
	if (p_wind->t_start)
		mlx_destroy_image(p_wind->mlx, p_wind->t_start);
	if (p_wind->t_wall)
		mlx_destroy_image(p_wind->mlx, p_wind->t_wall);
}

int	close_win(int keycode)
{
	(void)(keycode);
	exit_game(4);
	return (1);
}

void	destroy_map(void)
{
	t_map	*p_map;

	p_map = map_data();
	while (p_map->m_height >= 0)
	{
		free(p_map->map[p_map->m_height]);
		free(p_map->map_orig[p_map->m_height]);
		p_map->m_height--;
	}
	free(p_map->map);
	free(p_map->map_orig);
}

void	exit_game(int code)
{
	char	*error;

	error = ft_itoa(code);
	if (code <= 7)
	{
		write(2, "code:", 6);
		write(2, "01x", 4);
		write(2, error, 2);
		write(2, "\n", 2);
		destroy_img();
		destroy_wind();
	}
	else
	{
		write(2, "Error\n code:", 13);
		write(2, "00x", 4);
		write(2, error, 3);
		write(2, "\n", 2);
	}
	destroy_map();
	free(error);
	write(2, "Confirm README.md to see the meaning of the code.\n", 51);
	exit(code);
}
