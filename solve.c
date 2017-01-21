/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:40:49 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/21 19:37:28 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		solve(t_list **tet, t_map *map)
{
	size_t	size;
	size_t	unsolved;
	char	*result;
	t_list *first = NULL;

	size = calc_min_square(map->numtetri) - 1;
	unsolved = -1;
	if(init_t_map(map))
		return (0);
	while (unsolved != 0)
	{
		initmap_result(map, size);
		result = ft_strnew(map->map_size);
		initmap(result, map->size, NULL);
		printf("\x1b[42;30mnewgrid size %lu\n",size);
		first = *tet;
		unsolved = backtracker(result, map, tet, unsolved);//here algo return 0 if solution not found, return 1 if solved it
		*tet = first;
		free(result);
	}
	return (1);
}

size_t		init_t_map(t_map *map)
{
	if (!(map->coord = (size_t *)ft_memalloc(2 * sizeof(size_t))) ||\
			!(map->array = ft_strnew(20)))
		return (1);
	else
		return (0);
}

void		initmap_result(t_map *map, size_t size)
{
	map->size = size;
	map->map_size = (map->size * map->size) + map->size;
}

void	initmap(char *map, size_t size, t_list **tet)
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

size_t		int2Dto1D(unsigned int coord[4][2], size_t num_coord, size_t tab_width)
{
	size_t	index;

	index = (size_t)(coord[num_coord][1] * tab_width + coord[num_coord][0]);
	return (index);
}

char		tet_value(size_t i, t_list **tet, size_t size, size_t num_coord)
{
	size_t	match_block;

	match_block = 666;
	if (num_coord < NUMBLOCKS)
		match_block = ft_int2Dto1D((int **)TET->coord, num_coord, size);
	if (i == match_block)
		return (TET->value);
	else 
		return ('.');
}

void	*indexto2D(size_t *coord, size_t i, size_t width)
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
	printf("\x1b[45;15mbacktrack pos %lu, TET->val %c, TET->width %lu, TET->height %lu\n",pos, TET->value, TET->width, TET->height);
	size = map->size;
	indexto2D(map->coord, new_pos, map->size);
	width = map->coord[0] += TET->width;
	height = map->coord[1] += TET->height;
	while ((width > size || height > size) && new_pos < (map->map_size - NUMBLOCKS))
	{
		new_pos++;
		indexto2D(map->coord, new_pos, map->size);
		width = map->coord[0] += TET->width;
		height = map->coord[1] += TET->height;
		printf("newpos %lu, pos_coord_x %lu, pos_coord_y %lu, width %lu, height %lu\n", new_pos, map->coord[0], map->coord[1], width, height);
	}
	return (new_pos);
}

void		populate_tetri(char *tet_map, t_list **tet)
{
	ft_bzero(tet_map, 16);
	initmap(tet_map, 4, tet);
}

int			backtracker(char *result, t_map *map, t_list **tet, int erase)
{
	size_t		pos;

	pos = 0;
	if (tet == NULL)
		return (print_map(result));
	printf("\x1b[41;30mlength %lu figure\n%s", ft_strlen(result), map->array);
	while (pos < ft_strlen(result))
	{
		populate_tetri(map->array, tet);
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
			*tet = (*tet)->next;
			if (backtracker(result, map, tet, erase) == 0)
				return (0);
		}
		pos++;
	}
	return (-1);
}

int		put_tetri(char *result, t_map *map, t_list **tet, size_t pos)
{
	int		i;
	char	*tmp_map;

	i = 0;

	tmp_map = result;
	result = result + pos; // here -1 for debug
	while (map->array[i])
	{
		ft_putstr_fd("\x1b[46;30m", 1);
		printf("while pos: %lu map: %c tet: %c\n%s",pos,map->array[i], TET->value, result);
		if (map->array[i] == TET->value)
		{
			if (*result == '.')
			{
				printf("print %c\n",map->array[i]);
				*result = map->array[i];
				printf("print result\n%s",result);
			}
			else
			{
				ft_putstr_fd("\x1b[42;30m", 1);
				printf("not empty %c\npos %lu\n%s",*result,pos,tmp_map);
				return (-2);
			}
		}
		if (map->array[i] == '\n')
		{
			result = result + (int)(map->size) - NUMBLOCKS;
			printf("\x1b[41;30mgrid+%d:\n",(int)(map->size) - NUMBLOCKS);
			if (result > (tmp_map + map->map_size))
			{
				printf("start i %d:\n%s",i,tmp_map + map->map_size);
				return (test_end(map->array + i));
			}
		}
		i++;
		result++;
	}
	//map->array = tmp_map;
	ft_putstr("\x1b[43;30m");
	printf("pos: %lu, size: %lu, tet: %c, put piece:\n%s",pos,map->size,TET->value, tmp_map);
	return (0);
}
