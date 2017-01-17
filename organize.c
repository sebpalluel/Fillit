/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:14:04 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/17 16:56:18 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	organize(t_tetri *tet)
{
	size_t	min[2];
	size_t	counter;

	counter = 0;
	while (tet != NULL)
	{
		min[0] = tet_min_xy(tet, 0);
		min[1] = tet_min_xy(tet, 1);
		mv_upleft(tet, min);
		tet = tet->next;
		counter++;
	}
	return (counter);
}

size_t	tet_min_xy(t_tetri *tet, size_t xy)
{
	size_t	array[4];
	size_t 	i;

	i = 0;
	while (i < 4)
	{
		array[i] = tet->coord[i][xy];
		i++;
	}
	return ((size_t)ft_intmin((int *)array));
}

void	mv_upleft(t_tetri *tet, size_t *min)
{
	int	i;
	int xy;

	i = 0;
	while (i < 4)
	{
		xy = 0;
		while (xy < 2)
		{
			tet->coord[i][xy] -= min[xy];
			xy++;
		}
		i++;
	}
}

size_t	calc_min_square(size_t numtetri)
{
	size_t numblocks;

	numblocks = numtetri * 4;
	return (ft_sqrt(numblocks));
}
