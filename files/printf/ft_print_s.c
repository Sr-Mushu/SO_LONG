/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:13:49 by dagabrie          #+#    #+#             */
/*   Updated: 2022/03/29 13:55:38 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *argument)
{
	if (argument == NULL)
		argument = "(null)";
	ft_putstr_fd(argument, 1);
	return (ft_strlen(argument));
}
