/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:51:45 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/09 14:35:25 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_tetri(int fd)
{
	char	*buffer;
	int		count;

	buffer = ft_strnew(546);
	if (count = read(fd, buffer, 545))
		ft_putstr("error\n");
	return (count);
}
