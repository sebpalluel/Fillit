/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 20:53:06 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/21 13:56:38 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_STRUCT_H
# define FILLIT_STRUCT_H
# define TET ((t_tetri*)(*tet))

typedef	struct		s_tetri
{
	size_t			**coord;
	size_t			width;
	size_t			height;
	char			value;
	struct s_tetri	*next;
}					t_tetri;

typedef	struct		s_map
{
	size_t			size;
	size_t			map_size;
	char			*array;
}					t_map;

#endif
