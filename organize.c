/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:14:04 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/10 16:38:41 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	organize(t_tetri *tet)
{
	size_t	min[2];

	while (tet != NULL)
	{
		min[0] = tet_min_xy(tet->coord, 0);
		min[1] = tet_min_xy(tet->coord, 1);
		mv_upleft(tet->coord, min);
		tet = tet->next;
	}
}

size_t	tet_min_xy(t_point *coord, int xy)
{
	int	*array;
	int i;

	i = 0;
	while (coord[i])
	{
		array[i] = coord[i][xy];
		i++;
	}
	return ((size_t)ft_intmin(array));
}

void	mv_upleft(t_point *coord, size_t *min)
{
	int	i;
	int xy;
	i = 0;
	xy = 0;
	while (xy < 2)
	{
		while (coord[i][xy])
		{
			coord[i][xy] -= min[xy];
			i++;
		}
		xy++;
	}
}

int		calc_min_square(t_tetris *list)
{
	int numtetri;
	int numblocks;

	numtetri = ft_lstlen(list);
	numblocks = numtetri * 4;
	return (ft_sqrt(numblocks));
}
