/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int2Dto1D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 22:26:37 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/16 22:26:44 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_int2Dto1D(int **coord, size_t num_coord, size_t tab_width)
{
	size_t	index;

	index = (size_t)(coord[num_coord][1] * tab_width + coord[num_coord][0]);
	return (index);
}
