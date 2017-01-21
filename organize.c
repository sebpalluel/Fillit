/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:14:04 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/21 14:01:35 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	organize(t_list **tet)
{
	size_t	counter;
	int		*array;
	size_t  min[2];
	t_list	*first_tet;

	counter = 0;
	first_tet = *tet;
	if(!(array = (int *)ft_memalloc(NUMBLOCKS * sizeof(*array))))
		return (0);
	while (*tet)
	{
		printf("organize before, tet->coord %lu\n", TET->coord[0][0]);
		min[0] = tet_min_xy(tet, array, 0);
		printf("organize after\n");
		min[1] = tet_min_xy(tet, array, 1);
		tet->width = tet_max_xy(tet, array, 0) - min[0] + 1;
		tet->height = tet_max_xy(tet, array, 1) - min[1] + 1;
		mv_upleft(tet, min);
		tet = tet->next;
		counter++;
	}
	free(array);
	return (counter);
}

size_t	tet_min_xy(t_list **tet, int *array, size_t xy)
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

size_t	tet_max_xy(t_list **tet, int *array, size_t xy)
{
	size_t 	i;

	i = 0;
	while (i < NUMBLOCKS)
	{
		array[i] = tet->coord[i][xy];
		i++;
	}
	return (ft_intmax(array, NUMBLOCKS));
}

void	mv_upleft(t_tetri *tet, size_t min[2])
{
	int	i;

	i = 0;
	while (i < NUMBLOCKS)
	{
		tet->coord[i][0] -= min[0];
		tet->coord[i][1] -= min[1];
		i++;
	}
}

size_t	calc_min_square(size_t numtetri)
{
	size_t numblocks;

	numblocks = numtetri * NUMBLOCKS;
	return (ft_sqrt(numblocks));
}
