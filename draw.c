/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:40:35 by psebasti          #+#    #+#             */
/*   Updated: 2017/02/08 01:40:22 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	erase_tetri(char *array, t_list **tet)
{
	while (*array)
	{
		if (*array == TET(tet)->value)
			*array = '.';
		array++;
	}
}

int		test_end(char *tmp_map)
{
	while (*tmp_map)
	{
		if (*tmp_map != '\n' && *tmp_map != '.')
			return (2);
		tmp_map++;
	}
	return (0);
}

int		print_map(char *map)
{
	ft_putstr_fd(map, 1);
	return(0);
}
