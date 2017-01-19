/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:14:04 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/19 14:39:21 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	organize(t_tetri *tet)
{
	size_t	min[2];
	size_t	counter;
	int		*array;

	counter = 0;
	if(!(array = (int *)ft_memalloc(NUMBLOCKS * sizeof(*array))))
		return (0);
	while (tet != NULL)
	{
		min[0] = tet_min_xy(tet, array, 0);
		min[1] = tet_min_xy(tet, array, 1);
		mv_upleft(tet, min);
		tet = tet->next;
		counter++;
	}
	free(array);
	return (counter);
}

size_t	tet_min_xy(t_tetri *tet, int *array, size_t xy)
{
	size_t 	i;

	i = 0;
	while (i < NUMBLOCKS)
	{
		array[i] = tet->coord[i][xy];
		i++;
	}
	return (ft_intmin(array, NUMBLOCKS));
}

void	mv_upleft(t_tetri *tet, size_t *min)
{
	int	i;
	int xy;

	i = 0;
	while (i < NUMBLOCKS)
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

	numblocks = numtetri * NUMBLOCKS;
	return (ft_sqrt(numblocks));
}
