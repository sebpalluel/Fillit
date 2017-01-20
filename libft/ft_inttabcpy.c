/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttabcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:55:15 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/20 17:43:16 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

int			*ft_intdup(int *array, size_t width)
{
	int		*dest;
	size_t	i;

	i = 0;
	if (!(dest = (int *)ft_memalloc(width * sizeof(int))))
		return (NULL);
	while (i < width)
	{
		dest[i] = array[i];
		i++;
	}
	return (dest);
}

int			**ft_inttabcpy(int **array, size_t width)
{
	int		**tab;
	size_t	i;

	if (array)
	{
		if (!(tab = (int **)malloc(sizeof(int *) * \
						(ft_tablen((char **)array) + 1))))
			return (NULL);
		i = 0;
		while (array[i])
		{
			tab[i] = ft_intdup(array[i], width);
			printf("test 1 %d\n",tab[i][1]);
			i++;
		}
		tab[i] = 0;
		return (tab);
	}
	return (NULL);
}
