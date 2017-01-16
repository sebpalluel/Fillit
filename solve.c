/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:40:49 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/16 15:45:30 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		initmap_result(t_map *map, size_t size)
{
	map->size = size;
	map->map_size = (map->size * map->size) + map->size;
	map->array = ft_strnew(map->map_size + 1);
	initmap(map->array, map->size, NULL);
}

void		solve(t_tetri *tet, size_t numtetri)
{
	t_map	*map;
	size_t	size;
	size_t	unsolved;

	size = calc_min_square(numtetri) - 1;
	unsolved = -1;
	map = ft_memalloc( 2 * sizeof(t_map));
	map[1].array = ft_strnew(4 * 4 + 1);
	while (unsolved != 0)
	{
		size++;
		initmap_result(&map[0], size);
		ft_putstr("\x1b[42;30m newgrid\n");
		unsolved = backtracker(map, tet, unsolved);//here algo return 0 if solution not found, return 1 if solved it
		ft_putstr("afterbacktack\n");
		unsolved = 0; // stop debug
		free(map[0].array); // error here
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
	size_t		pos;

	pos = 0;
	if (tet == NULL)
	{
		return (print_map(map[0].array));
	}
	while (pos < ft_strlen(map[0].array))
	{
		/*		if (erase == -2)
				erase_tetri(map[0].array, tet);
				if ((erase = put_tetri(map[0], tet, pos)) == 0)
				{ */
		ft_putstr_fd("\x1b[m", 2);
		if (backtracker(map, tet->next, erase) == 0)
		{
			return (0);
		}
		//		}
		pos++;
	}
	return (-1);
}

int		put_tetri(t_map map, t_tetri *tet, size_t pos)
{
	int		i;
	char	*tmp_map;

	i = 0;
	tmp_map = map.array;
	//initmap(tmp_map, map->size, tet);
	map.array = map.array + pos;
	/*while (tmp_map[i])
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
	 {
	 map->array = map->array + map->size - 4;
	 if (map->array > (tmp_map + map->map_size))
	 return (test_end(tmp_map + i));
	 }
	 }
	 i++;
	 map->array++;
	 }*/
	ft_putstr("\x1b[43;30m");
	printf("pos: %lu, size: %lu, tet: %c, put piece:\n%s",pos,map.size,tet->value,map.array);
	return (0);
}
