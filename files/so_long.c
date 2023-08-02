/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:08:21 by dagabrie          #+#    #+#             */
/*   Updated: 2023/07/28 18:33:34 by dagabrie         ###   ########.fr       */
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
void map_to_array(int fd, int *num_lines, char ***map) {
    *num_lines = 0;
    *map = NULL;
    int j = 0;

    while (1) {
        char *line = get_next_line(fd);
        if (line == NULL)
		{
            break; // Chegamos ao final do arquivo.
        }
        // Aloca memória para a linha e copia o conteúdo da próxima linha para o mapa.
        *map = (char**)realloc(*map, (j + 1) * sizeof(char*));
        (*map)[j] = (char*)malloc((ft_strlen(line) + 1) * sizeof(char));
        ft_strlcpy((*map)[j], line,ft_strlen(line));

        j++;
		
    }
   		*num_lines = j;
}

//printa a matriz
void paint_map(char **map, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", map[i]);
    }
}

//cria a janela de acordo com o tamanho do mapa
void create_windo(int x, int y)
{

	t_wind 	*p_wind;

	p_wind = window_data();
	p_wind->mlx = mlx_init();
	p_wind->mlx_win = mlx_new_window(p_wind->mlx, 64*x, 64*y, "PRAIRIE_KING");
}

void no_textures(int x, int y)
{
	t_wind 	*p_wind;

	p_wind = window_data();
	p_wind->img = mlx_xpm_file_to_image(p_wind->mlx, NO_TEXTURES, &p_wind->x, &p_wind->y);
	mlx_put_image_to_window(p_wind->mlx, p_wind->mlx_win, p_wind->img, 64*x, 64*y);
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
			printf("%d ,%d \n",j,i);
			if(p_map->map[j][i] == '1')		
				no_textures(i,j);
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
	map_to_array(open(argv[1] ,O_RDWR) , &p_map->num_lines, &p_map->map);
	paint_map(p_map->map, p_map->num_lines);
	create_windo(ft_strlen(p_map->map[0]),p_map->num_lines);
	loude_map();
	mlx_loop(p_wind->mlx);

}
