/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:50:26 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/09 14:37:35 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef	struct	s_point
{
	int	x;
	int	y;
}		t_point;

typedef	struct	s_tetri
{
	t_point	coord[4];
	char	value;
}		t_tetri;

typedef	struct	s_map
{
	int	size;
	char	**array;
}		t_map;

char	*read_tetri(int fd);
int		check_format(char *str);
int		check_tetri(char *str);
int		check_valid(char *str);
t_tetri	*read_tetri(int fd);

#endif
