/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 20:09:13 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/16 23:25:05 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_newtab(size_t height, size_t width)
{
	size_t	i;
	char	**tab;

	i = 0;
	tab = (char **)ft_memalloc(sizeof(char *) * height + 1);
	while (tab && i < height)
	{
		tab[i] = (char *)ft_memalloc(sizeof(char) * width);
		i++;
	}
	tab[height] = NULL;
	return ((void **)tab);
}
