/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-fons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:50:49 by kda-fons          #+#    #+#             */
/*   Updated: 2017/01/09 12:53:35 by kda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib>
#include <unistd.h>
#include "libft.h"
#include "fillit.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_putstr("Usage: ./fillit 'fillit.map'");
	return (0);
}
