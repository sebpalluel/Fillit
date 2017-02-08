/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:51:11 by pciavald          #+#    #+#             */
/*   Updated: 2017/02/08 15:51:12 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_format(char *str)
{
	size_t		i;

	i = 0;
	while (i < MAPSIZE)
	{
		if ((i + 1) % 5 == 0)
		{
			if (str[i] != '\n')
				return (0);
		}
		else if (str[i] != '#' && str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

static int		check_tetri(char *str)
{
	size_t		i;
	size_t		contact;
	size_t		num_blocks;

	i = 0;
	contact = 0;
	num_blocks = 0;
	while (i < MAPSIZE)
	{
		if (str[i] == '#')
		{
			num_blocks++;
			if (i < MAPSIZE - 1 && str[i + 1] == '#')
				contact++;
			if (i < MAPSIZE - 5 && str[i + 5] == '#')
				contact++;
		}
		i++;
	}
	if ((contact == 3 || contact == 4) && num_blocks == NUMBLOCKS)
		return (1);
	return (0);
}

static int		check_valid(char *str)
{
	return (check_format(str) && check_tetri(str));
}

static size_t	read_tetri_error(char *buffer)
{
	free(buffer);
	return (1);
}

int				read_tetri(t_list **tetri, int fd)
{
	char		*buffer;
	size_t		last_tetri;
	size_t		ret;

	buffer = ft_strnew(MAPSIZE + 1);
	last_tetri = 0;
	while ((ret = read(fd, buffer, MAPSIZE + 1)))
	{
		if (ret == MAPSIZE)
			last_tetri++;
		if (!check_valid(buffer) || last_tetri > 1)
			return (read_tetri_error(buffer));
		if (ret == MAPSIZE + 1 && buffer[ret - 1] != '\n')
			return (read_tetri_error(buffer));
		if (!add_tetri(tetri, buffer))
			return (read_tetri_error(buffer));
	}
	ft_strdel(&buffer);
	return ((ret = last_tetri ? 0 : 1));
}
