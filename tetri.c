/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:02:53 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/21 13:40:01 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*create_tetri(char *str, char carac)
{
	size_t		i;
	size_t		current;
	t_tetri		*new;

	if (!(new = malloc(sizeof(t_tetri))) ||\
			!(new->coord = (size_t **)ft_newtab(4, 2)))
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

void	add_tetri(t_list **tetri, char *buffer, char carac)
{
	t_tetri	*tet_tmp;

	tet_tmp = create_tetri(buffer, carac);
	ft_lstaddend(tetri, ft_lstnew(&tet_tmp, sizeof(t_tetri)));

}
void	free_tetri(t_tetri **tetri)
{
	if(*tetri != NULL)
	{
		if((*tetri)->next != NULL)
			free_tetri(&((*tetri)->next));
		free((*tetri)->coord);
		free(*tetri);
	}
}
