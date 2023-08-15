/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vali.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:08:30 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/15 18:16:59 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void fd_is_ber(char *fd_name)
{
    int len ;
    const char *extin;
	extin = ".ber";
	len= ft_strlen(fd_name);
    if (len >= 4 && ft_strncmp(fd_name + len - 4, extin, ft_strlen(extin)) != 0)
	{
		write(2,"nome no valido\n",16);
        exit_game(0);
    }
}

void valid_lvl_1(void)
{
	t_map	*p_map;

	p_map = map_data();
	
}
void valid_lvl_2(void)
{
	t_map	*p_map;

	p_map = map_data();
}

void	map_valid(void)
{
	valid_lvl_1();
	valid_lvl_2();
}

//1. ver se e quadrado
//2. ver quantidade de playes coletaveis exit. guardar em uma variavel para usar depois no flod

/*
void	flood_fill(start x, start y, tamanho x, tamanho y)
{
	if(condicoes que nao podem entrar por exemplo paredes ou
		lugares que o flood ja entrou)
	return ;
	
	if (achei um coletavel)
		adicionar 1 na coletavel;
	verificar a quantidade de saidas
	vericafar a qauntidade de coletaveis ++;
	

	start x = x diferent;
	start y = y diferent;
	flood_fill(start x + 1, start y, pos x, pos y);
	flood_fill(start x - 1, start y, pos x, pos y);
	flood_fill(start x, start y + 1, pos x, pos y);
	flood_fill(start x, start y - 1, pos x, pos y);
}*/
