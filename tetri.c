/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:02:53 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/21 12:39:08 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*create_tetri(char *str, char carac)
{
	size_t		i;
	size_t		current;
	t_tetri		*new;

	if (!(new = malloc(sizeof(t_tetri))))
		return (NULL);
	i = 0;
	current = 0;
	new->next = NULL;
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
	new->value = carac;
	return (new);
}

void	add_tetri(t_tetri **tetri, t_tetri *new)
{
	t_tetri *tmp;

	tmp = *tetri;
	if (tetri != NULL && *tetri == NULL)
		*tetri = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	free_tetri(t_tetri **tetri)
{
	if(*tetri != NULL)
	{
		if((*tetri)->next != NULL)
			free_tetri(&((*tetri)->next));
		//free((*tetri)->coord);
		free(*tetri);
	}
}
