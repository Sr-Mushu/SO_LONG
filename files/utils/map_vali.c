/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vali.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:08:30 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/10 17:13:48 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

1. ver se e quadrado
2. ver quantidade de playes coletaveis exit. guardar em uma variavel para usar depois no flod


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
}
