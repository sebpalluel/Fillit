/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:50:49 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/21 19:33:06 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		fd;
	t_list	**tet;
	t_map 	*map;
	char	carac;

	carac = 'A';
	if(!(tet = (t_list **)ft_memalloc(sizeof(t_list *))) ||\
			!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (0);
	*tet = NULL;
	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || read_tetri(tet, fd) || fd == -1)
	{
		ft_putstr_fd("error\n",1);
		ft_lstfree(tet);
		return (close(fd));
	}
	if (!(map->numtetri = organize(tet, carac)))
		return (0);
	solve(tet, map);
	ft_lstfree(tet);
	free_map(map);
	return (0);
}

void		free_map(t_map *map)
{
	free(map->array);
	free(map->coord);
	free(map);
}
