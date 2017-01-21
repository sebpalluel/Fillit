/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:50:49 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/21 16:57:08 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int	fd;
	int	error;
	t_list	**tet;
	size_t numtetri;

	numtetri = 0;
	if(!(tet = (t_list **)ft_memalloc(sizeof(t_list *))))
		return (0);
	*tet = NULL;
	fd = open(argv[1], O_RDONLY);
	error = read_tetri(tet, fd);
	if (argc != 2 || error || fd == -1)
	{
		ft_putstr_fd("error\n",1);
		ft_lstfree(tet);
		return (close(fd));
	}
	if (!(numtetri = organize(tet)))
		return (0);
	//solve(tetri, numtetri);
	ft_lstfree(tet);
	return (0);
}
