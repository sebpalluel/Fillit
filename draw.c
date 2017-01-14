/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:40:35 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/14 15:29:48 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	erase_tetri(char *array, t_tetri *tet)
{
	while (*array)
	{
		if (*array == tet->value)
			*array = '.';
		array++;
	}
	ft_putstr("\x1b[41;30m erase\n");
}

int		test_end(char *tmp_map)
{
	while (*tmp_map)
	{
		if (*tmp_map != '\n' && *tmp_map != '.')
		{
			ft_putstr("\x1b[46;30m");
			ft_putstr("test_end_fail\n");
			return (-1);
		}
		tmp_map++;
	}
	ft_putstr("\x1b[45;30m");
	ft_putstr("test_end_succeed\n");
	return (0);
}

int		print_map(char *map)
{
	ft_putstr_fd(map, 1);
	return(1);
}
