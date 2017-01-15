/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:50:26 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/15 20:00:34 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "fillit_struct.h"
# include "libft/libft.h"
# include <stdio.h> // temporary, to test function, don't forget to erase with all the printf !!


int			read_tetri(t_tetri **tetri, int fd);
int			check_format(char *str);
int			check_tetri(char *str);
int			check_valid(char *str);
int			check_four_blocks(char *str);
size_t		organize(t_tetri *tet);
size_t		tet_min_xy(t_tetri *tet, int xy);
void		mv_upleft(t_tetri *tet, size_t *min);
size_t		calc_min_square(size_t numtetri);
void		solve(t_tetri *tet, size_t numtetri);
void		initmap(char *map, size_t size, t_tetri *tet);
char		tet_value(size_t i, t_tetri *tet, size_t size, size_t num_coord);
int			backtracker(t_map *map, t_tetri *tet, int flag);
void		erase_tetri(char *array, t_tetri *tet);
int			put_tetri(t_map *map, t_tetri *tet, int pos);
int			test_end(char *tmp_map);
int			print_map(char *map);
void		free_tetri(t_tetri *tetri);
void		add_tetri(t_tetri **tetri, t_tetri *new);
t_tetri		*create_tetri(char *str, char carac);
#endif
