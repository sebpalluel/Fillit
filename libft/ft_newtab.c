/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 20:09:13 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/16 20:11:44 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_newtab(size_t height, size_t width)
{
	size_t	i;
	char	**tab;

	i = 0;
	tab = (char **)ft_memalloc(sizeof(char *) * height);
	while (tab && i < height)
	{
		tab[i] = (char *)ft_memalloc(sizeof(char) * width);
		i++;
	}
	return ((void **)tab);
}
