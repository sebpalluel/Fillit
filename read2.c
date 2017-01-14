/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:51:27 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/14 19:10:26 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_format(char *str)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (((i % 5) == 0 && str[i] != '\n')
				|| ((i % 5) != 0 && str[i] != '#' && str[i] != '.'))
			return (0);
		i++;
	}
	return (1);
}

int		check_tetri(char *str)
{
	int		i;
	int		contact;

	i = 0;
	contact = 0;
	while (i < 20)
	{
		if (str[i] == '#')
			if (str[i + 1] == '#' || str[i + 5] == '#')
				contact++;
		i++;
	}
	return (contact == 3 || contact == 4);
}

int	check_valid(char *str)
{
	return (check_format(str) && check_tetri(str));
}

t_tetri *read_tetri(int fd)
{
	char		*buffer;
	char		carac;
	t_tetri		**tetri;

	buffer = ft_strnew(21);
	carac = 'A';
	*tetri = NULL;
	while (read(fd, buffer, 21))
	{
		if (!check_valid(buffer))
		{
			free(buffer);
			free_tetri(*tetri);
		}
		add_tetri(create_tetri(buffer, carac), *tetri);
		carac++;
	}
	return  (tetri);
}
