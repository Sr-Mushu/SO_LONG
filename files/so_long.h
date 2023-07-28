/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:08:24 by dagabrie          #+#    #+#             */
/*   Updated: 2023/07/28 18:32:28 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include "gnl/gnl.h"

typedef struct s_img
{
	void	*player;
	void	*wall;
	void	*floor;
}			t_img;

#endif