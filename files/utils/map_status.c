/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:39:15 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/18 18:09:22 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	status_cout(int j, int i)
{
	t_map	*p_map;

	p_map = map_data();
	if (p_map->map[j][i] == 'P')
	{
		++p_map->num_play;
		p_map->play_x = i;
		p_map->play_y = j;
	}
	else if (p_map->map[j][i] == 'E')
		++p_map->num_exit;
	else if (p_map->map[j][i] == 'C')
		++p_map->num_coins;
	else if (p_map->map[j][i] != '1' && p_map->map[j][i] != '0'
		&& p_map->map[j][i] != '\n')
		exit_game(12);
}

void	status_map(void)
{
	int		j;
	int		i;
	t_map	*p_map;

	i = 0;
	j = 0;
	p_map = map_data();
	p_map->num_play = 0;
	p_map->num_exit = 0;
	p_map->num_coins = 0;
	while (p_map->map[j])
	{
		i = 0;
		while (p_map->map[j][i])
		{
			status_cout(j, i);
			i++;
		}
		j++;
	}
}
