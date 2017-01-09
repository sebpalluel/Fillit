/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:32:31 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/09 17:35:23 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intmax(int *array)
{
	size_t	i;
	size_t	size;
	int		maximum;

	size = ft_intlen(array);
	maximum = array[0];
	i = 1;
	while (i < size)
	{
		if (array[i] > maximum)
			maximum = array[i];
		i++;
	}
	return (maximum);
}
