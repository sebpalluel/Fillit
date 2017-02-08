/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:51:21 by pciavald          #+#    #+#             */
/*   Updated: 2017/02/08 15:51:22 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	create_tetri(t_tetri *new, char *str)
{
	size_t		i;
	size_t		current;

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

size_t			add_tetri(t_list **tet, char *buffer)
{
	t_tetri		*tetri_new;

	tetri_new = (t_tetri *)ft_memalloc(sizeof(t_tetri));
	if (tetri_new == NULL || create_tetri(tetri_new, buffer) == 0)
		return (0);
	ft_lstaddend(tet, ft_lstnew(tetri_new, sizeof(tetri_new)));
	free(tetri_new);
	return (1);
}
