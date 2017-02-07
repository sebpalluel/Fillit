/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 20:09:13 by psebasti          #+#    #+#             */
/*   Updated: 2017/02/07 23:50:25 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	**ft_newtab(size_t height, size_t width)
{
	size_t	i;
	size_t	**tab;

	i = 0;
	tab = (size_t **)ft_memalloc(sizeof(size_t *) * (height + 1));
	while (tab && i < height)
	{
		tab[i] = (size_t *)ft_memalloc(sizeof(size_t) * width);
		i++;
	}
	tab[height] = NULL;
	return ((void **)tab);
}
