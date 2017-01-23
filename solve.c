/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:40:49 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/23 14:03:37 by psebasti         ###   ########.fr       */
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
		size++;
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

int			backtracker(char *result, t_map *map, t_list **tet, int erase)
{
	size_t		pos;

	pos = 0;
	if (*tet == NULL)
		return (print_map(result));
	printf("\x1b[41;30mlength %lu figure\n%s", ft_strlen(result), map->array);
	while (pos < ft_strlen(result))
	{
		populate_tetri(map->array, tet);
		printf("\x1b[47;10mmap->array\n%s",map->array);
		pos = evaluate_new_pos_tetri(map, tet, pos);
		//if (erase == -2 || erase == -3)
		//{
		printf("\x1b[41;30merase before\n%s",result);
		erase_tetri(result, tet);
		//	erase = -1;
		//}
		if ((erase = put_tetri(result, map, tet, pos)) == 0)
		{ 
			ft_putstr_fd("\x1b[mbacktracker\n", 1);
			if (backtracker(result, map, &(*tet)->next, erase) == 0)
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
	result = result + pos;
	while (map->array[i])
	{
		ft_putstr_fd("\x1b[46;30m", 1);
		printf("while pos: %lu i: %d map: %c tet: %c\n%s", pos, i, map->array[i], TET->value, result);
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
