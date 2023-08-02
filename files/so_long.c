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


void create_windo(int x, int y, void **mlx,void	**mlx_win, void **img)
{

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 64*x, 64*y, "SO_LONG");
	img = mlx_xpm_file_to_image(mlx, "textures/no_texture.xpm", &x, &y);

}

int	main(int argc, char **argv)
{
	char 	**map = NULL;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int 	num_lines;


	map_to_array(open(argv[1] ,O_RDWR) , &num_lines, &map);
	paint_map(map, num_lines);
	
	create_windo(ft_strlen(map[0]),num_lines, &mlx, &mlx_win, &img);

	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);

	mlx_loop(mlx);

}
