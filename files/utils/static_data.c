/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:49:44 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/22 15:33:48 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_wind	*window_data(void)
{
	static t_wind	wind;

	return (&wind);
}

t_map	*map_data(void)
{
	static t_map	map;

	return (&map);
}
