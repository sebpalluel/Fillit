/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:50:49 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/30 18:39:18 by pciavald         ###   ########.fr       */
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

static int		quit(int error, t_map *map, t_list **tet, int fd)
{
	if (map && tet)
		free_map_and_tetri(map, tet);
	if (fd > 0)
		close(fd);
	if (error)
	{
		ft_putendl_fd("error", 1);
		return (ERROR);
	}
	return (SUCCESS);
}

static int		usage(void)
{
	ft_putendl("usage: ./fillit mapname");
	return (ERROR);
}

int				main(int argc, char **argv)
{
	int			fd;
	t_list		**tet;
	t_map 		*map;
	char		carac;

	if (argc != 2)
		return (usage());
	tet = (t_list **)ft_memalloc(sizeof(t_list *));
	map = (t_map *)ft_memalloc(sizeof(t_map));
	if (!tet || !map)
		return (ERROR);
	*tet = NULL;
	carac = 'A';
	fd = open(argv[1], O_RDONLY);
	if (read_tetri(tet, fd) || fd == -1)
		return (quit(ERROR, map, tet, fd));
	if ((map->numtetri = organize(tet, carac)) == 0)
		return (quit(ERROR, map, tet, fd));
	solve(tet, map);
	return (quit(SUCCESS, map, tet, fd));
}
