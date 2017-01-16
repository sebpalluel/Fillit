/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:50:49 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/16 16:01:35 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int	fd;
	int	error;
	t_tetri	*tetri;
	size_t numtetri;

	numtetri = 0;
	if(!(tetri = ft_memalloc(sizeof(t_tetri))))
		return (0);
	ft_bzero(tetri, sizeof(t_tetri));
	fd = open(argv[1], O_RDONLY);
	error = read_tetri(&tetri, fd);
	if (argc != 2 || error)
	{
		ft_putstr_fd("error\n",1);
		return (0);
	}
	numtetri = organize(tetri);
	solve(tetri, numtetri);
	free_tetri(&tetri);
	return (0);
}
