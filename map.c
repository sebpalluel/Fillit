/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:58:58 by psebasti          #+#    #+#             */
/*   Updated: 2017/02/08 15:27:26 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		init_t_map(t_map *map)
{
	map->coord = (size_t *)ft_memalloc(2 * sizeof(size_t));
	map->array = ft_strnew(MAPSIZE);
	if (map->coord == NULL || map->array == NULL)
		return (0);
	return (1);
}

void		initmap_result(t_map *map, size_t size)
{
	map->size = size;
	map->map_size = (map->size * map->size) + map->size;
}

void		initmap(char *map, size_t size, t_list **tet)
{
	size_t	i;
	size_t	num_coord;

	i = 0;
	num_coord = 0;
	while (i < (size * size) + size)
	{
		if ((i + 1) % (size + 1) == 0)
			map[i] = '\n';
		else
		{
			if (tet == NULL)
				map[i] = '.';
			else
			{
				map[i] = tet_value(i, tet, size + 1, num_coord);
				if (map[i] != '.')
					num_coord++;
			}
		}
		i++;
	}
	map[i] = '\0';
}

char		tet_value(size_t i, t_list **tet, size_t size, size_t num_coord)
{
	size_t	match_block;

	match_block = 666;
	if (num_coord < NUMBLOCKS)
	{
		match_block = TET(tet)->coord[num_coord][1] * size;
		match_block += TET(tet)->coord[num_coord][0];
	}
	if (i == match_block)
		return (TET(tet)->value);
	else
		return ('.');
}

void		populate_tetri(char *tet_map, t_list **tet)
{
	ft_bzero(tet_map, 16);
	initmap(tet_map, 4, tet);
}
