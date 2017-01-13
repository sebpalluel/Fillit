/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:02:53 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/13 17:44:23 by kda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_tetri		create_tetri(char *str, char carac)
{
	int			i;
	int			j;
	int			current;
	t_tetri		*new;

	if (!(new = malloc(sizeof(t_tetri))))
		return (NULL);
	i = 0;
	j = 0;
	current = 0;
	while (str[i])
	{
		if ((i % 5) == 0)
			j++;
		if (str[i] == '#')
		{
			new.coord[current].x = (i % 5);
			new.coord[current].y = j;
			current++;
		}
		i++;
	}
	tetri.value = carac;
	return (new);
}

void	add_tetri(t_tetri *tetri, t_tetri *new)
{
	t_tetri	*tmp;

	tmp = tetri;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	free_tetri(t_tetri *tetri)
{
	t_tetri	*tmp;
	tmp = tetri->next;
	free(tetri);
	free_tetri(tmp);
}
