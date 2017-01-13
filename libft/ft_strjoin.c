/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srtjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:15:57 by psebasti          #+#    #+#             */
/*   Updated: 2016/11/22 17:57:21 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*str;

	l1 = 0;
	l2 = 0;
	str = NULL;
	if (s1)
		l1 = ft_strlen(s1);
	if (s2)
		l2 = ft_strlen(s2);
	if (!(str = (char*)malloc((l1 + l2) * sizeof(*str))))
		return (NULL);
	if (s1)
		ft_strcpy(str, s1);
	if (s2)
		ft_strcpy(str + l1, s2);
	return (str);
}
