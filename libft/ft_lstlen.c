/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:36:33 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/10 14:43:43 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *lst)
{
	t_list	*tmp_list;
	int		counter;

	tmp_list = lst;
	counter = 0;
	if (tmp_list == NULL)
		return (0);
	while (tmp_list->next != NULL)
	{
		tmp_list = tmp_list->next;
		counter++;
	}
	return (counter + 1);
}
