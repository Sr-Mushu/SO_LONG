#include "../so_long.h"

int p_move_up(void)
{
    t_map	*p_map;

	p_map = map_data();
    printf(" up \n");
    flor_texture(p_map->play_x,p_map->play_y);
    play_texture(p_map->play_x,p_map->play_y--);
}

int p_move_down(void)
{
    t_map	*p_map;

	p_map = map_data();
    printf(" down \n");
    flor_texture(p_map->play_x,p_map->play_y);
    play_texture(p_map->play_x,p_map->play_y++);
}

int p_move_left(void)
{
    t_map	*p_map;

	p_map = map_data();
    printf(" left \n");
    flor_texture(p_map->play_x,p_map->play_y);
    play_texture(p_map->play_x--,p_map->play_y);
}
int p_move_right(void)
{
    t_map	*p_map;

	p_map = map_data();
    printf(" right \n");
    flor_texture(p_map->play_x,p_map->play_y);
    play_texture(p_map->play_x++,p_map->play_y);
}
int	key_hooks(int keycode, t_wind *p_wind)
{
    if(keycode == 119)
	    p_move_up();
    else if(keycode == 97)
	    p_move_left();
    else if(keycode == 115)
	     p_move_down();
    else if(keycode == 100)
	    p_move_right();
     else if(keycode == 32)
	    loude_map();
    else if(keycode == 65307)
	    exit(1);
    else
	    printf(" ? : %d\n", keycode);
	return (0);
}