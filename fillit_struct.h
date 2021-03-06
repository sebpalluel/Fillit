/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 20:53:06 by psebasti          #+#    #+#             */
/*   Updated: 2017/02/08 01:41:09 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_STRUCT_H
# define FILLIT_STRUCT_H

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
	size_t			numtetri;
	size_t			*coord;
	char			*array;
}					t_map;

#endif
