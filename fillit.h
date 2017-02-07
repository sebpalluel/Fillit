/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:50:26 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/30 19:53:19 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "fillit_struct.h"
# include "fillit_define.h"
# include "libft/libft.h"
# include <stdio.h> // TODO remove dat shit

int			read_tetri(t_list **tetri, int fd);
size_t		organize(t_list **tet, char carac);
size_t		calc_min_square(size_t numtetri);
size_t		solve(t_list **tet, t_map *map);
void		initmap(char *map, size_t size, t_list **tet);
size_t		init_t_map(t_map *map);
void		initmap_result(t_map *map, size_t size);
char		tet_value(size_t i, t_list **tet, size_t size, size_t num_coord);
int			backtracker(char *result, t_map *map, t_list **tet, int erase);
//size_t		evaluate_new_pos_tetri(t_map *map, t_tetri *tet,
//	unsigned int **coord, size_t pos);
void		populate_tetri(char *tet_map, t_list **tet);
void		erase_tetri(char *array, t_list **tet);
int			put_tetri(char *result, t_map *map, t_list **tet, size_t pos);
int			test_end(char *tmp_map);
int			print_map(char *map);
size_t		add_tetri(t_list **tet, char *buffer);

#endif
