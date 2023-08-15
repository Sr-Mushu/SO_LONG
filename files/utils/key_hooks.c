/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:39:26 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/15 17:03:15 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void p_move(int old_x,int old_y,int new_x,int new_y)
{
    t_map	   *p_map;
	static int cout;
	
	p_map = map_data();
	printf("player:  new_x[%d] new_y[%d]\n", new_x, new_y);
	printf("player:  old_x[%d],old_y[%d]\n", old_x, old_y);
	printf("player:  number %d\n", cout++);
    if(p_map->map[new_y][new_x] == 'C')
    {
        printf("coin !!\n");
    }
    if(p_map->map[new_y][new_x] != '1')
    {
		if (p_map->map_orig[old_y][old_x] == 'E')
			p_map->map[old_y][old_x] = 'E';
		else
     		p_map->map[old_y][old_x] = '0';
     	p_map->map[new_y][new_x] = 'P';
    }
	if(p_map->map_orig[new_y][new_x] == 'E' && p_map->open_dor == 5)
	{
		printf("#####WIN####\n");
		exit_game(0);
	}
    loude_map();
}

void pp_move(int keycode)
{
    t_map	*p_map;

	p_map = map_data();
    if(keycode == UP)
        p_move(p_map->play_x,p_map->play_y,p_map->play_x,--p_map->play_y);
    else if(keycode == DOWN)
        p_move(p_map->play_x,p_map->play_y,p_map->play_x,++p_map->play_y);
    else if(keycode == LEFT)
        p_move(p_map->play_x,p_map->play_y,--p_map->play_x,p_map->play_y);
    else if(keycode == RIGHT)
        p_move(p_map->play_x,p_map->play_y,++p_map->play_x,p_map->play_y);
    
}

int	key_hooks(int keycode, t_wind *p_wind)
{
    t_map	*p_map;
	
	p_map = map_data();
	if(p_map->strat_flag)
	{
		p_map->strat_flag = 0;
		if(keycode == 32)		
			loude_map();
		 return (0);
	}
	 else
	 {
		if(keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT )
				pp_move(keycode);
		if(keycode == 109)
		{
			paint_map(p_map->map, p_map->m_height);
			paint_map(p_map->map_orig, p_map->m_height);
		}
		else if(keycode == 65307)
			exit_game(1);
		return (0);
	 }
}