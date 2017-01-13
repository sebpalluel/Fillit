/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:50:26 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/13 17:15:23 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h> // temporary, to test function, don't forget to erase with all the printf !!

typedef	struct		s_tetri
{
	unsigned int	coord[4][2];
	char			value;
	struct s_tetri	*next;
}					t_tetri;

typedef	struct		s_map
{
	size_t			size;
	size_t			map_size;
	char			*array;
}					t_map;

char				*read_tetri(int fd);
int					check_format(char *str);
int					check_tetri(char *str);
int					check_valid(char *str);
t_list				*read_tetri(int fd);
void				organize(t_tetri *tet);
size_t				tet_min_xy(t_tetri *tet, int xy);
void				mv_upleft(t_tetri *tet, size_t *min);
int					calc_min_size(t_tetri *tet);
void				solve(t_tetri *tet);
t_map				initmap(size_t	size);
int					backtracker(t_map map, t_tetri *tet, int flag);
void				erase_tetri(char *array, t_tetri *tet);
int					put_tetri(t_map map, t_tetri *tet, int pos);
#endif
