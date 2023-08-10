#include "../so_long.h"

#if 0
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
    if(keycode == UP)
	    p_move_up();
    else if(keycode == DOWN)
	    p_move_left();
    else if(keycode == LEFT)
	     p_move_down();
    else if(keycode == RIGHT)
	    p_move_right();
     else if(keycode == 32)
	    loude_map();
    else if(keycode == 65307)
	    exit(1);
    else
	    printf(" ? : %d\n", keycode);
	return (0);
}
#else
void move(int old_x,int old_y,int new_x,int new_y)
{
    t_map	*p_map;

	p_map = map_data();
    if(p_map->map[new_y][new_x] == 'C')
    {
        printf("coin !!");
    }
    if(p_map->map[new_y][new_x] =! '1')
    {
      p_map->map[old_y][old_x] = '0';
      p_map->map[new_y][new_x] = 'P';
      
    }
    loude_map();
}
//p_map->play_x,p_map->play_y

void p_move(int keycode)
{
    t_map	*p_map;

	p_map = map_data();
    if(keycode == UP)
        move(p_map->play_x,p_map->play_y,p_map->play_x,--p_map->play_y);
    else if(keycode == DOWN)
        move(p_map->play_x,p_map->play_y,p_map->play_x,++p_map->play_y);
    else if(keycode == LEFT)
        move(p_map->play_x,p_map->play_y,--p_map->play_x,p_map->play_y);
    else if(keycode == RIGHT)
        move(p_map->play_x,p_map->play_y,++p_map->play_x,p_map->play_y);
    
}

int	key_hooks(int keycode, t_wind *p_wind)
{

     t_map	*p_map;

	p_map = map_data();

    if(keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT )
            p_move(keycode);
    if(keycode == 32)
	    paint_map(p_map->map, p_map->m_height);
    else if(keycode == 65307)
	    exit(1);
    else
	    printf(" ? : %d\n", keycode);
	return (0);
}

#endif