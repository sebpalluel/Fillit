/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:02:53 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/23 18:55:01 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		create_tetri(t_tetri *new, char *str)
{
	size_t	i;
	size_t	current;

	i = 0;
	current = 0;
	new->next = NULL;
	if (!(new->coord = (size_t **)ft_newtab(4, 2)))
		return (0);
	while (str[i])
	{
		if (str[i] == '#')
		{
			new->coord[current][0] = i % 5;
			new->coord[current][1] = i / 5;
			current++;
		}
		i++;
	}
	return (1);
}

size_t		add_tetri(t_list **tet, char *buffer)
{
	t_tetri	*tetri_new;

	if (!(tetri_new = (t_tetri *)ft_memalloc(sizeof(t_tetri))) ||\
			!(create_tetri(tetri_new, buffer)))
		return (0);
	ft_lstaddend(tet, ft_lstnew(tetri_new, sizeof(tetri_new)));
	return (1);
}

