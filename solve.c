/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:40:49 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/13 18:27:38 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
void		solve(t_tetri *tet)
{
	t_map	map;
	size_t	size;
	size_t	flag;

	size = calc_min_size(tet) - 1;
	flag = 1;
	while (flag)
	{
		size++;
		map = initmap(size, NULL);
		flag = backtracker(map, tet, flag);//here algo return 0 if solution not found, return 1 if solved it
		free(map.array);
	}
}

t_map		initmap(size_t size, t_tetri *tet)
{
	size_t 	i;
	t_map	map;

	i = 0;
	map.size = size;
	map.map_size = (map.size * map.size) + map.size;
	map.array = (char *)ft_memalloc(map.map_size + 1);
	while (i < map.map_size)
	{
		if ((i % map.size) == 0)
			map.array[i] = '\n';
		else
		{
			if (tet == NULL)
				map.array[i] = '.';
		}
		i++;
	}
	map.array[i] = '\0';
	return (map);
}

char		tet_value(size_t i, t_tetri *tet)
{
}

int			backtracker(t_map map, t_tetri *tet, int flag)
{
	int		pos;

	pos = 0;
	if (tet == NULL)
		return (print_result(tet));
	while (pos < (int)ft_strlen(map.array))
	{
		if (flag)
		{
			erase_tetri(map.array, tet);
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
	tmp_map = initmap(map.size);
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
	printf("pos : %d, size : %lu, put piece :\n%s\n",pos,map.size,tmp_map);
	return (0);
}
