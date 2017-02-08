/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:40:49 by psebasti          #+#    #+#             */
/*   Updated: 2017/02/08 15:49:51 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		solve(t_list **tet, t_map *map)
{
	size_t	size;
	size_t	unsolved;
	char	*result;
	t_list	*first;

	size = calc_min_square(map->numtetri) - 1;
	unsolved = -1;
	if (!init_t_map(map))
		return (0);
	while (unsolved != 0)
	{
		size++;
		initmap_result(map, size);
		result = ft_strnew(map->map_size);
		initmap(result, map->size, NULL);
		first = *tet;
		unsolved = backtracker(result, map, tet, unsolved);
		*tet = first;
		free(result);
	}
	return (1);
}

void		*indexto_2d(size_t *coord, size_t i, size_t width)
{
	coord[0] = i % width;
	coord[1] = i / (width + 1);
	return (coord);
}

size_t		evaluate_new_pos_tetri(t_map *map, t_list **tet, size_t pos)
{
	size_t			new_pos;
	size_t			width;
	size_t			height;
	size_t			size;

	new_pos = pos;
	size = map->size;
	indexto_2d(map->coord, new_pos, map->size);
	width = map->coord[0] + TET(tet)->width;
	height = map->coord[1] + TET(tet)->height;
	while ((width > size + 1 || height > size + 1) \
			&& new_pos < (map->map_size - NUMBLOCKS - 1))
	{
		new_pos++;
		indexto_2d(map->coord, new_pos, map->size);
		width = map->coord[0] + TET(tet)->width;
		height = map->coord[1] + TET(tet)->height;
	}
	return (new_pos);
}

int			backtracker(char *result, t_map *map, t_list **tet, int erase)
{
	size_t		pos;

	pos = 0;
	if (*tet == NULL)
		return (print_map(result));
	while (pos < map->map_size)
	{
		populate_tetri(map->array, tet);
		pos = evaluate_new_pos_tetri(map, tet, pos);
		erase_tetri(result, tet);
		if ((erase = put_tetri(result, map, tet, pos)) == 0)
		{
			if (backtracker(result, map, &(*tet)->next, erase) == 0)
				return (0);
		}
		pos++;
	}
	return (-1);
}

int			put_tetri(char *result, t_map *map, t_list **tet, size_t pos)
{
	int			i;
	size_t		j;

	i = 0;
	j = pos;
	while (map->array[i])
	{
		if (map->array[i] == TET(tet)->value)
		{
			if (result[j] == '.')
				result[j] = map->array[i];
			else
				return (-2);
		}
		if (map->array[i] == '\n')
		{
			j += (int)(map->size) - NUMBLOCKS;
			if (j >= map->map_size - 1)
				return (test_end(map->array + i));
		}
		i++;
		j++;
	}
	return (0);
}
