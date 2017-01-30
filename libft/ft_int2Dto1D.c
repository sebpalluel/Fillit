/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int2Dto1D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 22:26:37 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/21 20:34:32 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t		ft_int2Dto1D(int **coord, size_t num_coord, size_t tab_width)
{
	size_t	index;

	index = (size_t)(coord[num_coord][1] * tab_width + coord[num_coord][0]);
	printf("coordx: %d coordy: %d numcoord: %lu matchcoord %lu\n",coord[num_coord][0], coord[num_coord][1], num_coord, index);
	return (index);
}
