/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/14 14:55:53 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


t_wind *window_data(void)
{
	static t_wind wind;

	return(&wind);
}

t_map *map_data(void)
{
	static t_map map;

	return(&map);
}


//guarda o mapa numa matriz
void map_to_array(int fd, int *m_height, char ***map) {
    *m_height = 0;
    *map = NULL;
    int j = 0;

    while (1) 
	{
        char *line = get_next_line(fd);
        if (line == NULL)
		{
			*map = (char**)realloc(*map, (j + 1) * sizeof(char*));
			(*map)[j] = NULL;
            break; // Chegamos ao final do arquivo.
        }
        // Aloca memória para a linha e copia o conteúdo da próxima linha para o mapa.
        *map = (char**)realloc(*map, (j + 1) * sizeof(char*));
        (*map)[j] = (char*)malloc((ft_strlen(line) + 1) * sizeof(char));
        ft_strlcpy((*map)[j], line,ft_strlen(line));
		
        j++;
		
    }
   		*m_height = j;
}

//printa a matriz
void paint_map(char **map, int m_height) {
    for (int i = 0; i < m_height; i++) {
        printf("%s\n", map[i]);
    }
}

//cria a janela de acordo com o tamanho do mapa
void create_windo(int x, int y)
{

	t_wind 	*p_wind;

	p_wind = window_data();
	p_wind->mlx = mlx_init();
	p_wind->mlx_win = mlx_new_window(p_wind->mlx, 32*x, 32*y, "PRAIRIE_KING");
}


//vai carregar o mapa com no_testure por enuanto
void loude_map(void)
{
	int j = 0;
	int i = 0;
	t_map	*p_map;

	p_map = map_data();
	while(p_map->map[j])
	{
		i = 0;
		while(p_map->map[j][i])
		{
			if (p_map->map[j][i] == '0')		
				flor_texture(i,j);
			else if (p_map->map[j][i] == '1')		
				wall_texture(i,j);
			else if (p_map->map[j][i] == 'P')
				{
					play_texture(i,j);
					p_map->play_x = i;
					p_map->play_y = j;
				}
			else if (p_map->map[j][i] == 'E')		
				{
					if(p_map->open_dor == 5)
						exit_texture(i,j);
					else
						flor_texture(i,j);
				}
			else if (p_map->map[j][i] == 'C')
				{	
					++p_map->num_coins;
					coin_texture(i,j);
				}
			else
				empt_texture(i,j);
			i++;
		}
		j++;
	}
	if(p_map->num_coins == 0)
		p_map->open_dor = 5;
	p_map->num_coins = 0;
}

//p_cordes
void map_status(void)
{
	int j = 0;
	int i = 0;
	t_map	*p_map;

	p_map = map_data();
	while(p_map->map[j])
	{
		i = 0;
		while(p_map->map[j][i])
		{
			if (p_map->map[j][i] == 'P')
				{
					p_map->play_x = i;
					p_map->play_y = j;
				}
			i++;
		}
		j++;
	}
}

//main
int	main(int argc, char **argv)
{
	t_wind 	*p_wind;
	t_map	*p_map;

	p_map = map_data(); 
	p_wind = window_data();
	p_map->strat_flag = 1;
	map_to_array(open(argv[1] ,O_RDWR) , &p_map->m_height, &p_map->map);
	map_to_array(open(argv[1] ,O_RDWR) , &p_map->m_height, &p_map->map_orig);
	paint_map(p_map->map, p_map->m_height);
	create_windo(ft_strlen(p_map->map[0]),p_map->m_height);
	loude_texture();
	map_status();
	start_texture(ft_strlen(p_map->map[0])/2-2,p_map->m_height/2-2);
	mlx_key_hook(p_wind->mlx_win, key_hooks, &p_wind);
	mlx_loop(p_wind->mlx);

}

//a falta de loude no inicio d'a erro: