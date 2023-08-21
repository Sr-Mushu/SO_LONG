/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:13:34 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/18 18:06:47 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_wind(void)
{
	t_wind	*p_wind;

	p_wind = window_data();
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
	return (100000);
}

void	exit_game(int code)
{
	if (code == 16)
		write(2, "Mapa invalido mais ou sem de uma exit\n", 39);
	if (code == 15)
		write(2, "Mapa invalido mais ou sem de um player\n", 40);
	if (code == 14)
		write(2, "Mapa invalido o player nao chega a exit\n", 41);
	if (code == 13)
		write(2, "Mapa invalido o player nao chega aos coins\n", 44);
	if (code == 12)
		write(2, "Mapa invalido outros char no meio\n", 35);
	if (code == 11)
		write(2, "Mapa invalido nao esta reodiado por walls\n", 43);
	if (code == 10)
		write(2, "Mapa invalido contiudo fora do mapa\n", 37);
	if (code == 9)
		write(2, "Mapa invalido nao e retangular\n", 30);
	if (code == 8)
		write(2, "Mapa invalido vazio\n", 21);
	if (code == 4)
		write(2, "You cose the wind\n", 19);
	if (code == 3)
		write(2, "Nome do Mapa nao valido\n", 30);
	if (code == 1)
		write(2, "You exit the game\n", 19);
	if (code <= 7)
	{
		destroy_img();
		destroy_wind();
	}
	exit(code);
}
