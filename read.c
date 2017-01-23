/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:51:27 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/21 18:39:33 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_format(char *str)
{
	int	i;

	i = 0;
	while (i < MAPSIZE)
	{
		if (((i + 1) % 5) == 0)
		{
			if (str[i] != '\n')
				return (0);
		}
		else
			if (str[i] != '#' && str[i] != '.')
				return (0);
		i++;
	}
	return (1);
}

int		check_tetri(char *str)
{
	int		i;
	int		contact;
	int		num_blocks;

	i = 0;
	contact = 0;
	num_blocks = 0;
	while (i < MAPSIZE)
	{
		if (str[i] == '#')
		{
			num_blocks++;
			if (str[i + 1] == '#')
				contact++;
			if(str[i + 5] == '#')
				contact++;
		}
		i++;
	}
	if ((contact == 3 || contact == 4) && (num_blocks == NUMBLOCKS))
		return (1);
	return (0);
}

int		check_valid(char *str)
{
	return (check_format(str) && check_tetri(str));
}

size_t read_tetri_error(char *buffer)
{
	free(buffer);
	return (1);
}

int 	read_tetri(t_list **tetri, int fd)
{
	char		*buffer;
	size_t		last_tetri;
	size_t		ret;

	buffer = ft_strnew(21);
	last_tetri = 0;
	while ((ret = read(fd, buffer, 21)))
	{
		printf("%s",buffer);
		if (ret == 20)
			last_tetri++;
		if (!check_valid(buffer) || last_tetri > 1 || \
				(ret == 21 && buffer[ret - 1] != '\n'))
			return (read_tetri_error(buffer));
		if (!add_tetri(tetri, buffer))
			return (read_tetri_error(buffer));
	}
	return (last_tetri ? 0 : 1);
}
