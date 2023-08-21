/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loude_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:49:17 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/18 18:08:09 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	loude_t_map(int j, int i)
{
	t_map	*p_map;

	p_map = map_data();
	if (p_map->map[j][i] == '0')
		flor_texture(i, j);
	else if (p_map->map[j][i] == '1')
		wall_texture(i, j);
	else if (p_map->map[j][i] == 'P')
	{
		play_texture(i, j);
		p_map->play_x = i;
		p_map->play_y = j;
	}
	else if (p_map->map[j][i] == 'E')
	{
		if (p_map->open_dor == 5)
			exit_texture(i, j);
		else
			flor_texture(i, j);
	}
	else if (p_map->map[j][i] == 'C')
	{
		++p_map->num_coins;
		coin_texture(i, j);
	}
}

void	loude_map(void)
{
	int		j;
	int		i;
	t_map	*p_map;

	j = 0;
	i = 0;
	p_map = map_data();
	while (p_map->map[j])
	{
		i = 0;
		while (p_map->map[j][i])
		{
			loude_t_map(j, i);
			i++;
		}
		j++;
	}
	if (p_map->num_coins == 0)
		p_map->open_dor = 5;
	p_map->num_coins = 0;
}

void	map_to_array(int fd, int *m_height, char ***map)
{
	int		j;
	char	*line;

	const int max_lines = 100; // Defina o número máximo de linhas
	*m_height = 0;
	*map = (char **)malloc(max_lines * sizeof(char *));
		// Aloca memória para o array de ponteiros
	j = 0;
	while (j < max_lines)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			(*map)[j] = NULL;
			break ; // Chegamos ao final do arquivo.
		}
		// Aloca memória para a linha e copia o conteúdo da próxima linha para o mapa.
		(*map)[j] = (char *)malloc((ft_strlen(line) + 1) * sizeof(char));
		ft_strlcpy((*map)[j], line, ft_strlen(line) + 1);
		free(line);
		j++;
	}
	*m_height = j;
}

// cria a janela de acordo com o tamanho do mapa
void	create_windo(int x, int y)
{
	t_wind	*p_wind;

	p_wind = window_data();
	p_wind->mlx = mlx_init();
	p_wind->mlx_win = mlx_new_window(p_wind->mlx, 32 * x, 32 * y,
			"PRAIRIE_KING");
}
