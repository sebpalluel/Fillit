/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:50:26 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/24 22:35:49 by psebasti         ###   ########.fr       */
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
# define NUMBLOCKS 4
# define MAPSIZE 20

int			read_tetri(t_list **tetri, int fd);
int			check_format(char *str);
int			check_tetri(char *str);
int			check_valid(char *str);
size_t		organize(t_list **tet, char carac);
size_t		tet_min_xy(t_list **tet, int *array,  size_t xy);
size_t		tet_max_xy(t_list **tet, int *array, size_t xy);
void		mv_upleft(t_list **tet, size_t min[2]);
size_t		calc_min_square(size_t numtetri);
size_t		solve(t_list **tet, t_map *map);
void		initmap(char *map, size_t size, t_list **tet);
size_t		init_t_map(t_map *map);
void		initmap_result(t_map *map, size_t size);
char		tet_value(size_t i, t_list **tet, size_t size, size_t num_coord);
int			backtracker(char *result, t_map *map, t_list **tet, int erase);
//size_t		evaluate_new_pos_tetri(t_map *map, t_tetri *tet, \
//	unsigned int **coord, size_t pos);
void		populate_tetri(char *tet_map, t_list **tet);
void		erase_tetri(char *array, t_list **tet);
int			put_tetri(char *result, t_map *map, t_list **tet, size_t pos);
int			test_end(char *tmp_map);
int			print_map(char *map);
size_t		add_tetri(t_list **tet, char *buffer);
size_t		create_tetri(t_tetri *new, char *str);

#endif
