/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:40:49 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/15 20:01:08 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		solve(t_tetri *tet, size_t numtetri)
{
	t_map	*map;
	size_t	size;
	size_t	unsolved;

	size = calc_min_square(numtetri) - 1;
	unsolved = 1;
	map = ft_memalloc(sizeof(t_map));
	while (unsolved)
	{
		size++;
		ft_bzero(map, sizeof(t_map));
		map->size = size;
		map->map_size = (map->size * map->size) + map->size;
		map->array = (char *)ft_memalloc(sizeof(map->map_size + 1));
		initmap(map->array, map->size, NULL);
		print_map(map->array);
		//printf("& : %p\n%s\n",map->array, map->array);
		unsolved = backtracker(map, tet, unsolved);//here algo return 0 if solution not found, return 1 if solved it
		ft_putstr("afterbacktack\n");
		free(map->array);
	}
}

void	initmap(char *map, size_t size, t_tetri *tet)
{
	size_t 	i;
	size_t	num_coord;

	i = 0;
	num_coord = 0;
	while (i < (size * size) + size)
	{
		if (((i + 1) % (size + 1)) == 0)
			map[i] = '\n';
		else
		{
			if (tet == NULL)
				map[i] = '.';
			else
				map[i] = tet_value(i, tet, size + 1, num_coord);
		}
		i++;
	}
	map[i] = '\0';
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

int			backtracker(t_map *map, t_tetri *tet, int erase)
{
	int		pos;

	pos = 0;
	if (tet == NULL)
		return (print_map(map->array));
	while (pos < (int)ft_strlen(map->array))
	{
		if (erase)
			erase_tetri(map->array, tet);
		if ((erase = put_tetri(map, tet, pos)) == 0)
		{
			ft_putstr_fd("\x1b[m", 2);
			if (backtracker(map, tet->next, erase) == 0)
				return (1);
		}
		pos++;
	}
	return (0);
}

int		put_tetri(t_map *map, t_tetri *tet, int pos)
{
	int		i;
	char	*tmp_map;

	i = 0;
	initmap(tmp_map, map->size, tet);
	ft_putstr("test\n");
	map->array = map->array + pos;
	while (tmp_map[i])
	{
		if (tmp_map[i] == tet->value)
		{
			if (*map->array == '.')
				*map->array = tmp_map[i];
			else
			{
				ft_putstr_fd("\x1b[42;30m", 2);
				ft_putstr_fd("not empty\n", 2);
				return (1);
			}
			if (tmp_map[i] == '\n')

				map->array = map->array + map->size - 4;
			if (map->array > (tmp_map + map->map_size))
				return (test_end(tmp_map + i));
		}
		i++;
		map->array++;
	}
	ft_putstr("\x1b[43;30m");
	printf("pos : %d, size : %lu, put piece :\n%s\n",pos,map->size,tmp_map);
	return (0);
}
