/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:08:24 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/18 18:11:33 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "gnl/gnl.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# define FLOR "textures/flor.xpm"
# define WALL "textures/wall.xpm"
# define PLAY "textures/play.xpm"
# define COIN "textures/coin.xpm"
# define ENAM "textures/enam.xpm"
# define EXIT "textures/exit.xpm"
# define START "textures/Start.xpm"

# define CODE_TEST 0
# define MAX_STRING_LENGTH 1000

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

typedef struct s_map
{
	char	**map;
	char	**map_orig;
	int		m_length;
	int		m_height;
	int		play_x;
	int		play_y;
	int		num_coins;
	int		flg_coins;
	int		num_play;
	int		num_exit;
	int		flg_exit;
	int		open_dor;
	int		exit_flag;
	int		strat_flag;
}			t_map;

typedef struct s_wind
{
	int		x;
	int		y;
	void	*mlx;
	void	*mlx_win;
	void	*t_flor;
	void	*t_wall;
	void	*t_play;
	void	*t_coin;
	void	*t_exit;
	void	*t_start;
}			t_wind;

// static_data.c
t_map		*map_data(void);
t_wind		*window_data(void);

// t_loude.c
void		loude_texture(void);
void		flor_texture(int x, int y);
void		wall_texture(int x, int y);
void		coin_texture(int x, int y);
void		play_texture(int x, int y);
void		start_texture(int x, int y);
void		exit_texture(int x, int y);

// key_hooks.c
int			key_hooks(int keycode, t_wind *p_wind);

// so_long.c
void		loude_map(void);
void		paint_map(char **map, int m_height);
void		copy_matrix(void);

// exit_game.c
void		exit_game(int code);
int			close_win(int keycode);

// loude_map.c
void		loude_map(void);
void		map_to_array(int fd, int *m_height, char ***map);
void		create_windo(int x, int y);

// map_vali.c
void		map_valid(void);
void		fd_is_ber(char *fd_name);

// map_status
void		status_map(void);

#endif