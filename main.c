/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:50:49 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/21 18:40:50 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int	fd;
	t_list	**tet;
	size_t numtetri;
	char	carac;

	numtetri = 0;
	carac = 'A';
	if(!(tet = (t_list **)ft_memalloc(sizeof(t_list *))))
		return (0);
	*tet = NULL;
	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || read_tetri(tet, fd) || fd == -1)
	{
		ft_putstr_fd("error\n",1);
		ft_lstfree(tet);
		return (close(fd));
	}
	if (!(numtetri = organize(tet, carac)))
		return (0);
	solve(tet, numtetri);
	ft_lstfree(tet);
	return (0);
}
