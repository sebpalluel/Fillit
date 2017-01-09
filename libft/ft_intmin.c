/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:20:22 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/09 17:36:03 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intmin(int *array)
{
	size_t	i;
	size_t	size;
	int		minimum;

	size = ft_intlen(array);
	minimum = array[0];
	i = 1;
	while (i < size)
	{
		if (array[i] < minimum)
			minimum = array[i];
		i++;
	}
	return (minimum);
}
