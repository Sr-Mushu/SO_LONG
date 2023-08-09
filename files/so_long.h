/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:08:24 by dagabrie          #+#    #+#             */
/*   Updated: 2023/07/28 18:32:28 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include "gnl/gnl.h"
# define FLOR "textures/flor.xpm"
# define WALL "textures/wall.xpm"
# define EMPT "textures/empt.xpm"
# define TEST "textures/test.xpm"
# define PLAY "textures/play.xpm"
# define COIN "textures/coin.xpm"
# define START "textures/Start.xpm"

typedef struct s_map
{
	char 	**map;
	int 	m_length;
	int		m_height;
	int     play_x;
	int		play_y;

}			t_map;

typedef struct s_wind
{
	int		x;
	int		y;
	void	*mlx;
	void	*mlx_win;
	void	*t_flor;
	void	*t_wall;
	void	*t_empt;
	void	*t_test;
	void	*t_play;
	void	*t_coin;
	void	*t_start

}			t_wind;

// decalação


t_map *map_data(void);

t_wind *window_data(void);

//t_loude.c

void loude_texture(void);
void flor_texture(int x, int y);
void wall_texture(int x, int y);
void coin_texture(int x, int y);
void play_texture(int x, int y);
void empt_texture(int x, int y);
void test_texture(int x, int y);
void start_texture(int x, int y);

//key_hooks.c

int	key_hooks(int keycode, t_wind *p_wind);

#endif