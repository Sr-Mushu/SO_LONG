/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loude_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:49:17 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/15 18:30:43 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void loude_t_map(int j, int i)
{
	t_map	*p_map;

	p_map = map_data();
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
}

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
			loude_t_map(j,i);
			i++;
		}
		j++;
	}
	if(p_map->num_coins == 0)
		p_map->open_dor = 5;
	p_map->num_coins = 0;
}

#if 0
//Guarda o mapa numa matriz
void map_to_array(int fd, int *m_height, char ***map) 
{
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

#else
void map_to_array(int fd, int *m_height, char ***map) 
{
    *m_height = 0;
    *map = NULL;
    int j = 0;
    int encountered_empty_line = 0; // Flag to track if an empty line was encountered

    while (1) 
    {
        char *line = get_next_line(fd);
        if (line == NULL)
        {
            *map = (char**)realloc(*map, (j + 1) * sizeof(char*));
            (*map)[j] = NULL;
            break; // Reached the end of the file.
        }
        if (line[0] == '\n' && line[1] == '\0') 
        {
            encountered_empty_line = 1; // Set the flag
            free(line);
            continue;
        }
        if (encountered_empty_line && line[0] != '\n') 
        {
            exit_game(10); // Call the exit_game function with argument 10
        }

        *map = (char**)realloc(*map, (j + 1) * sizeof(char*));
        (*map)[j] = (char*)malloc((ft_strlen(line) + 1) * sizeof(char));
        ft_strlcpy((*map)[j], line, ft_strlen(line));
        j++;
        free(line);
    }
    *m_height = j;
}
#endif

//cria a janela de acordo com o tamanho do mapa
void create_windo(int x, int y)
{

	t_wind 	*p_wind;

	p_wind = window_data();
	p_wind->mlx = mlx_init();
	p_wind->mlx_win = mlx_new_window(p_wind->mlx, 32*x, 32*y, "PRAIRIE_KING");
}