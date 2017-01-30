/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:50:49 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/30 17:40:52 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		free_map_and_tetri(t_map *map, t_list **tet)
{
	free(map->array);
	free(map->coord);
	free(map);
	ft_lstfree(tet);
}

static void		quit(int error, t_map *map, t_list **tet, int fd)
{
	if (error)
		ft_putendl_fd("error", 1);
	if (map && tet)
		free_map_and_tetri(map, tet);
	if (fd > 0)
		close(fd);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_list	**tet;
	t_map 	*map;
	char	carac;

	tet = (t_list **)ft_memalloc(sizeof(t_list *));
	map = (t_map *)ft_memalloc(sizeof(t_map));
	if (!tet || !map)
		return (0);
	*tet = NULL;
	carac = 'A';
	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || read_tetri(tet, fd) || fd == -1)
	{
		quit(ERROR, map, tet, fd);
		return (1);
	}
	if (!(map->numtetri = organize(tet, carac)))
	{
		quit(NOERROR, map, tet, fd);
		return (0);
	}
	solve(tet, map);
	quit(NOERROR, map, tet, fd);
	return (0);
}

