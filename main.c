/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:50:49 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/21 13:46:27 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int	fd;
	int	error;
	t_list	**tetri;
	size_t numtetri;

	numtetri = 0;
	if(!(tetri = (t_list **)ft_memalloc(sizeof(t_list *))))
		return (0);
	*tetri = NULL;
	fd = open(argv[1], O_RDONLY);
	error = read_tetri(tetri, fd);
	if (argc != 2 || error)
	{
		ft_putstr_fd("error\n",1);
		ft_lstfree(tetri);
		return (0);
	}
	if (!(numtetri = organize(tetri)))
		return (0);
	printf("after organize\n");
	solve(tetri, numtetri);
	free_tetri(&tetri);
	return (0);
}
