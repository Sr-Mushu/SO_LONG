#include "../so_long.h"

void loude_texture(void)
{
	t_wind 	*p_wind;

	p_wind = window_data();
	p_wind->t_flor = mlx_xpm_file_to_image(p_wind->mlx, FLOR, &p_wind->x, &p_wind->y);
	p_wind->t_wall = mlx_xpm_file_to_image(p_wind->mlx, WALL, &p_wind->x, &p_wind->y);
	p_wind->t_empt = mlx_xpm_file_to_image(p_wind->mlx, EMPT, &p_wind->x, &p_wind->y);
	p_wind->t_play = mlx_xpm_file_to_image(p_wind->mlx, PLAY, &p_wind->x, &p_wind->y);
	p_wind->t_coin = mlx_xpm_file_to_image(p_wind->mlx, COIN, &p_wind->x, &p_wind->y);
	p_wind->t_test = mlx_xpm_file_to_image(p_wind->mlx, TEST, &p_wind->x, &p_wind->y);
	p_wind->t_start = mlx_xpm_file_to_image(p_wind->mlx, START, &p_wind->x, &p_wind->y);
}
void flor_texture(int x, int y)
{
	t_wind 	*p_wind;

	p_wind = window_data();
	mlx_put_image_to_window(p_wind->mlx, p_wind->mlx_win, p_wind->t_flor, 32*x, 32*y);
}

void empt_texture(int x, int y)
{
	t_wind 	*p_wind;

	p_wind = window_data();
	mlx_put_image_to_window(p_wind->mlx, p_wind->mlx_win, p_wind->t_empt, 32*x, 32*y);
}

void wall_texture(int x, int y)
{
	t_wind 	*p_wind;

	p_wind = window_data();
	mlx_put_image_to_window(p_wind->mlx, p_wind->mlx_win, p_wind->t_wall, 32*x, 32*y);
}

void play_texture(int x, int y)
{
	t_wind 	*p_wind;

	p_wind = window_data();
	mlx_put_image_to_window(p_wind->mlx, p_wind->mlx_win, p_wind->t_play, 32*x, 32*y);
}

void coin_texture(int x, int y)
{
	t_wind 	*p_wind;

	p_wind = window_data();
	mlx_put_image_to_window(p_wind->mlx, p_wind->mlx_win, p_wind->t_coin, 32*x, 32*y);
}

void test_texture(int x, int y)
{
	t_wind 	*p_wind;

	p_wind = window_data();
	mlx_put_image_to_window(p_wind->mlx, p_wind->mlx_win, p_wind->t_test, 32*x, 32*y);
}

void start_texture(int x, int y)
{
	t_wind 	*p_wind;

	p_wind = window_data();
	mlx_put_image_to_window(p_wind->mlx, p_wind->mlx_win, p_wind->t_start, 32*x, 32*y);
}