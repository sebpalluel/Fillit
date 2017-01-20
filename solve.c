/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:40:49 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/20 22:44:37 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		solve(t_tetri *tet, size_t numtetri)
{
	t_map	**map = NULL;
	size_t	size;
	size_t	unsolved;
	unsigned int *pos_coord = NULL;
	size_t i;
	char	*result;

	i = 0;
	size = calc_min_square(numtetri) - 1;
	unsolved = -1;
	if (!(map = (t_map **)ft_memalloc(3 * sizeof(t_map *))) \
			|| !(pos_coord = (unsigned int *)ft_memalloc(2 * sizeof(*pos_coord))))
		return (0);
	while (map && i < 2)
	{
		map[i] = (t_map *)ft_memalloc(sizeof(t_map));
		i++;
	}
	map[i] = NULL;
	if(initmap_result(map[1], 4))
		return (0);
	while (unsolved != 0)
	{
		size++;
		if (initmap_result(map[0], size))
			return (0);
		result = ft_strnew(map[0]->map_size);
		initmap(result, map[0]->size, NULL);
		printf("\x1b[42;30mnewgrid size %lu\n",size);
		unsolved = backtracker(result, map, tet, pos_coord, unsolved);//here algo return 0 if solution not found, return 1 if solved it
		free(result);
		free(map[0]->array);
	}
	free(pos_coord);
	free(map);
	return (1);
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

size_t		initmap_result(t_map *map, size_t size)
{
	map->size = size;
	map->map_size = (map->size * map->size) + map->size;
	if (!(map->array = ft_strnew(map->map_size)))
		return (1);
	initmap(map->array, map->size, NULL);
	return (0);
}

size_t		int2Dto1D(unsigned int coord[4][2], size_t num_coord, size_t tab_width)
{
	size_t	index;

	index = (size_t)(coord[num_coord][1] * tab_width + coord[num_coord][0]);
	return (index);
}

char		tet_value(size_t i, t_tetri *tet, size_t size, size_t num_coord)
{
	size_t	match_block;

	match_block = int2Dto1D(tet->coord, num_coord, size);
	if (i == match_block && num_coord < NUMBLOCKS)
		return (tet->value);
	else 
		return ('.');
}

void	*indexto2D(unsigned int *coord, size_t i, size_t width)
{
	coord[0] = i % width;
	coord[1] = i / (width + 1);
	return (coord);
}

size_t		evaluate_new_pos_tetri(t_map **map, t_tetri *tet, unsigned int *pos_coord, size_t pos)
{
	size_t			new_pos;
	size_t			width;
	size_t			height;
	size_t			size;

	new_pos = pos;
	printf("\x1b[45;15mbacktrack pos %lu, tet->val %c, tet->width %lu, tet->height %lu\n",pos, tet->value, tet->width, tet->height);
	size = map[0]->size;
	indexto2D(pos_coord, new_pos, map[0]->size);
	width = pos_coord[0] += tet->width;
	height = pos_coord[1] += tet->height;
	while ((width > size || height > size) && new_pos < (map[0]->map_size - NUMBLOCKS))
	{
		new_pos++;
		indexto2D(pos_coord, new_pos, map[0]->size);
		width = pos_coord[0] += tet->width;
		height = pos_coord[1] += tet->height;
		printf("newpos %lu, pos_coord_x %d, pos_coord_y %d, width %lu, height %lu\n", new_pos, pos_coord[0], pos_coord[1], width, height);
	}
	return (new_pos);
}

void		populate_tetri(char *tet_map, t_tetri *tet)
{
	ft_bzero(tet_map, 16);
	initmap(tet_map, 4, tet);
}

int			backtracker(char *result, t_map **map, t_tetri *tet, unsigned int *coord, \
		int erase)
{
	size_t		pos;

	pos = 0;
	if (tet == NULL)
		return (print_map(result));
	printf("\x1b[41;30m length %lu figure\n%s", ft_strlen(result), map[1]->array);
	while (pos < ft_strlen(result))
	{
		populate_tetri(map[1]->array, tet);
		//pos = evaluate_new_pos_tetri(map, tet, coord, pos);
		//if (erase == -2 || erase == -3)
		//{
		printf("\x1b[41;30merase before\n%s",result);
		erase_tetri(result, tet);
		//	erase = -1;
		//}
		if ((erase = put_tetri(result, map, tet, pos)) == 0)
		{ 
			ft_putstr_fd("\x1b[mbacktracker\n", 1);
			if (backtracker(result, map, tet->next, coord, erase) == 0)
				return (0);
		}
		pos++;
	}
	return (-1);
}

int		put_tetri(char *result, t_map **map, t_tetri *tet, size_t pos)
{
	int		i;
	char	*tmp_map;

	i = 0;

	tmp_map = result;
	result = result + pos; // here -1 for debug
	while (map[1]->array[i])
	{
		ft_putstr_fd("\x1b[46;30m", 1);
		printf("while pos: %lu map[1]: %c tet: %c\n%s",pos,map[1]->array[i], tet->value, result);
		if (map[1]->array[i] == tet->value)
		{
			if (*result == '.')
			{
				printf("print %c\n",map[1]->array[i]);
				*result = map[1]->array[i];
				printf("print result\n%s",result);
			}
			else
			{
				ft_putstr_fd("\x1b[42;30m", 1);
				printf("not empty %c\npos %lu\n%s",*result,pos,tmp_map);
				return (-2);
			}
		}
		if (map[1]->array[i] == '\n')
		{
			result = result + (int)(map[0]->size) - NUMBLOCKS;
			printf("\x1b[41;30mgrid+%d:\n",(int)(map[0]->size) - NUMBLOCKS);
			if (result > (tmp_map + map[0]->map_size))
			{
				printf("start i %d:\n%s",i,tmp_map + map[0]->map_size);
				return (test_end(map[1]->array + i));
			}
		}
		i++;
		result++;
	}
	//map[0]->array = tmp_map;
	ft_putstr("\x1b[43;30m");
	printf("pos: %lu, size: %lu, tet: %c, put piece:\n%s",pos,map[0]->size,tet->value, tmp_map);
	return (0);
}
