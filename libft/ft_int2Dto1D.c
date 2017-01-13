/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int2Dto1D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:59:53 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/13 19:21:41 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		*ft_int2Dto1D(int **coord, size_t num_coord, size_t tab_width)
{
	size_t	count;
	size_t	*tab;

	count = 0;
	tab = (size_t *)ft_memalloc(num_coord);
	while (count < num_coord)
	{
		tab[count] = coord[count][1] * tab_width + coord[count][0];
		count++;
	}
	return (tab);
}
