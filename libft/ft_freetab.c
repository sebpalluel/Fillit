/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:44:35 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/16 18:56:45 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freetab(void **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_memdel((void *)&tab[i++]);
	ft_memdel((void *)&tab);
}
