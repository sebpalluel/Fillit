/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:40:49 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/13 21:00:35 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
void		solve(t_tetri *tet)
{
	t_map	map;
	size_t	size;
	size_t	unsolved;

	size = calc_min_size(tet) - 1;
	unsolved = 1;
	while (unsolved)
	{
		size++;
		ft_bzero(&map, sizeof(t_map));
		map.size = size;
		map.map_size = (map.size * map.size) + map.size;
		map.array = (char *)ft_memalloc(map.map_size + 1);
		initmap(&map, size, NULL);
		unsolved = backtracker(map, tet, unsolved);//here algo return 0 if solution not found, return 1 if solved it
		free(map.array);
	}
}

void	initmap(t_map *map, size_t size, t_tetri *tet)
{
	size_t 	i;
	size_t	num_coord;

	i = 0;
	num_coord = 0;
	while (i < map->map_size)
	{
		if ((i % map->size) == 0)
			map->array[i] = '\n';
		else
		{
			if (tet == NULL)
				map->array[i] = '.';
			else
				map->array[i] = tet_value(i, tet, map->size + 1, num_coord);
		}
		i++;
	}
	map->array[i] = '\0';
}

char		tet_value(size_t i, t_tetri *tet, size_t size, size_t num_coord)
{
	size_t	match_block;

	match_block = ft_int2Dto1D((int **)tet->coord, num_coord, size + 1);
	if (i == match_block && num_coord < 4)
	{
		num_coord++;
		return (tet->value);
	}
	else 
		return ('.');
}

int			backtracker(t_map *map, t_tetri *tet, int flag)
{
	int		pos;

	pos = 0;
	if (tet == NULL)
		return (print_result(tet));
	while (pos < (int)ft_strlen(map->array))
	{
		if (flag)
		{
			erase_tetri(map->array, tet);
			flag = 0;
		}
		if ((flag = put_tetri(map, tet, pos)) == 0)
		{
			ft_putstr("\x1b[m");
			if (backtracker(map, tet->next, flag) == 0)
				return (1);
		}
		pos++;
	}
	return (0);
}

void	erase_tetri(char *array, t_tetri *tet)
{
	while (*array)
	{
		if (*array == tet->value)
		{
			*array = '.';
		}
		array++;
	}
	ft_putstr("\x1b[41;30m erase\n");
}

int		put_tetri(t_map map, t_tetri *tet, int pos)
{
	int		i;
	t_map	tmp_map;

	i = 0;
	initmap(&tmp_map, map.size, tet);
	map.array = map.array + pos;
	while (tmp_map.array[i])
	{
		if (tmp_map.array[i] == tet->value)
		{
			if (*map.array != '.')
				return (-1);
			*map.array = tmp_map.array[i];
		}
		if (tmp_map.array[i] == '\n')
		{
			map.array = map.array + map.size - 4;
			if (map.array > (tmp_map.array + map.map_size))
				return (test_end(tmp_map.array + i));
		}
		i++;
		map.array++;
	}
	ft_putstr("\x1b[43;30m");
	printf("pos : %d, size : %lu, put piece :\n%s\n",pos,map.size,tmp_map.array);
	return (0);
}

int		test_end(char *tmp_map)
{
	while (*tmp_map)
	{
		if (*tmp_map != '\n' && *tmp_map != '.')
			return (-1);
		tmp_map++;
	}
	return (0);
}
