/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:02:53 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/15 15:43:36 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*create_tetri(char *str, char carac)
{
	size_t		i;
	size_t		j;
	size_t		current;
	t_tetri		*new;

	if (!(new = malloc(sizeof(t_tetri))))
		return (NULL);
	i = 0;
	j = 0;
	current = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			j++;
		if (str[i] == '#')
		{
			new->coord[current][0] = (i % 5);
			new->coord[current][1] = j;
			current++;
		}
		i++;
	}
	new->value = carac;
	return (new);
}

void	add_tetri(t_tetri **tetri, t_tetri *new)
{
	if (new)
	{
		new->next = *tetri;
		*tetri = new;
	}
}

void	free_tetri(t_tetri *tetri)
{
	t_tetri	*tmp;

	tmp = tetri;
	while (tmp)
	{
		tetri = tmp;
		tmp = tmp->next;
		free(tetri->coord);
		free_tetri(tetri);
	}
}
