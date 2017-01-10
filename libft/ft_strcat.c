/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srtcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:12:51 by psebasti          #+#    #+#             */
/*   Updated: 2016/11/11 17:53:40 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *src, const char *dest)
{
	size_t	i;
	size_t	length;

	length = ft_strlen(src);
	i = 0;
	while (dest[i])
	{
		src[length + i] = dest[i];
		i++;
	}
	src[length + i] = '\0';
	return (src);
}
