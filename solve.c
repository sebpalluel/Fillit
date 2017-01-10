/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:40:49 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/10 19:00:46 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
void		solve(t_tetri *tet)
{
	size_t	size;
	size_t	flag;
	char	*map;

	size = calc_min_square(tet) - 1;
	flag = 0;
	while (flag != 1)
	{
		size++;
		initmap(&map, size);
		flag = backtracker(map, tet, size);//here algo return 0 if solution not found, return 1 if solved it
		free(map);
	}
}

void		initmap(char *map, size_t size)
{
	size_t mapsize;
	size_t i;

	i = 0;
	mapsize = (size * size) + size;
	map = (char *)ft_memalloc(mapsize + 1);
	while (i < mapsize)
	{
		if ((i % size) == 0)
			map[i] = '\n';
		else
			map[i] = '.';
		i++;
	}
	map[i] = '\0';
}

int			backtracker(char *map, t_tetri *tet, size_t size)
{
}
