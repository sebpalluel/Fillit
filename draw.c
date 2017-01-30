/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:40:35 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/24 22:47:42 by psebasti         ###   ########.fr       */
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
	ft_putstr_fd("\x1b[41;30m erase\n", 2);
}

int		test_end(char *tmp_map)
{
	while (*tmp_map)
	{
		if (*tmp_map != '\n' && *tmp_map != '.')
		{
			ft_putstr_fd("\x1b[46;30m", 2);
			ft_putstr_fd("test_end_fail\n", 2);
			return (2);
		}
		tmp_map++;
	}
	ft_putstr_fd("\x1b[45;30m", 2);
	ft_putstr_fd("test_end_succeed\n", 2);
	return (0);
}

int		print_map(char *map)
{
	printf("printmap\n");
	ft_putstr_fd(map, 1);
	return(0);
}
