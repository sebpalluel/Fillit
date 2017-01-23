/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:50:49 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/23 14:20:10 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		fd;
	t_list	**tet;
	t_map 	*map;
	char	carac;

	if(!(tet = (t_list **)ft_memalloc(sizeof(t_list *))) ||\
			!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (0);
	*tet = NULL;
	carac = 'A';
	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || read_tetri(tet, fd) || fd == -1)
	{
		ft_putendl_fd("error",1);
		free_map_and_tetri(map, tet);
		return (close(fd));
	}
	if (!(map->numtetri = organize(tet, carac)))
		return (0);
	solve(tet, map);
	free_map_and_tetri(map, tet);
	return (close(fd));
}

void		free_map_and_tetri(t_map *map, t_list **tet)
{
	free(map->array);
	free(map->coord);
	free(map);
	ft_lstfree(tet);
}
