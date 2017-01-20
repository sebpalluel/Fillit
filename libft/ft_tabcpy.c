/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:57:00 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/20 15:57:32 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tabcpy(char **str)
{
	char	**tab;
	int		i;

	if (str)
	{
		tab = (char**)malloc(sizeof(char*) * (ft_tablen(str) + 1));
		if (!tab)
			return (NULL);
		i = 0;
		while (str[i])
		{
			tab[i] = ft_strdup(str[i]);
			i++;
		}
		tab[i] = 0;
		return (tab);
	}
	return (NULL);
}
