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
#if 1

//guarda o mapa numa matriz
void **map_to_arrey(int fd,char **map)
{
	printf("in\n");
	int i = 0;
	int j = 0;
	char *line;
	while(*line != NULL) // erro nesta linha
	{
		i = 0;
		*line = (get_next_line(fd),1);
		while (line[i])
		{
			*map[j] = *line;
			printf("%c\n",line[i]);
			i++;
		}
		
		j++;
	}
		printf("out\n");
}

int	main(int argc, char **argv)
{
	char 	**map;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		x = 0;
	int		y;
	int 	j = 0;
	int 	fd = open(argv[1] ,O_RDWR);
	int 	lon = ft_strlen(get_next_line(fd));
	
	map_to_arrey(fd , map);

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 64*lon, 500, "SO_LONG");
	img = mlx_xpm_file_to_image(mlx, "textures/no_texture.xpm", &x, &y);
	printf("%d\n",lon);
	while(j++ <= lon)
	{
		printf("okfffff\n");
		mlx_put_image_to_window(mlx, mlx_win, img, x, 0);
		x = x + 64;
	}
	mlx_loop(mlx);

}
#else
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		x;
	int		y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "SO_LONG");
	img = mlx_xpm_file_to_image(mlx, "textures/no_texture.xpm", &x, &y);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 64);
	mlx_put_image_to_window(mlx, mlx_win, img, 64, 64);
	mlx_put_image_to_window(mlx, mlx_win, img, 128, 64);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, img, 64, 0);
	mlx_put_image_to_window(mlx, mlx_win, img, 128, 0);
	mlx_loop(mlx);
}
#endif