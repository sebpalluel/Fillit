/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:51:27 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/16 16:08:24 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_format(char *str)
{
	int	i;

	i = 0;
	while (i < 20)
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

int		check_four_blocks(char *str)
{
	int		blocks;
	int		i;

	blocks = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
			blocks++;
		i++;
	}
	if (blocks == 4)
		return (1);
	return (0);
}

int		check_valid(char *str)
{
	return (check_format(str) && check_tetri(str) && check_four_blocks
			(str));
}

int 	read_tetri(t_tetri **tetri, int fd)
{
	char		*buffer;
	char		carac;
	size_t		last_tetri;
	size_t		ret;

	buffer = ft_strnew(21);
	carac = 'A';
	last_tetri = 0;
	*tetri = NULL;
	while ((ret = read(fd, buffer, 21)))
	{
		printf("%s",buffer);
		if (ret == 20)
			last_tetri++;
		if (!check_valid(buffer) && last_tetri > 1)
		{
			free(buffer);
			free_tetri(tetri);
			return (1);
		}
		add_tetri(tetri, create_tetri(buffer, carac));
		carac++;
	}
	if (last_tetri)
		return (0);
	else
		return (1);
}
