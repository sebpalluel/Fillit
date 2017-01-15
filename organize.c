/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:14:04 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/15 16:55:39 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	organize(t_tetri *tet)
{
	size_t	min[2];

	while (tet != NULL)
	{
		printf("organize %c\n",tet->value);
		min[0] = tet_min_xy(tet, 0);
		min[1] = tet_min_xy(tet, 1);
		printf("min x : %lu, min y : %lu\n",min[0],min[1]);
		mv_upleft(tet, min);
		tet = tet->next;
	}
}

size_t	tet_min_xy(t_tetri *tet, int xy)
{
	int	array[4];
	int i;

	i = 0;
	while (i < 4)
	{
		array[i] = tet->coord[i][xy];
		i++;
	}
	return ((size_t)ft_intmin(array));
}

void	mv_upleft(t_tetri *tet, size_t *min)
{
	int	i;
	int xy;

	i = 0;
	xy = 0;
	while (xy < 2)
	{
		while (i < 4)
		{
			tet->coord[i][xy] -= min[xy];
			i++;
		}
		xy++;
	}
}

int		calc_min_square(t_tetri *tet)
{
	int numtetri;
	int numblocks;

	numtetri = ft_lstlen((t_list *)tet);
	numblocks = numtetri * 4;
	return (ft_sqrt(numblocks));
}
