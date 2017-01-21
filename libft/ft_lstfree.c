/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:20:24 by psebasti          #+#    #+#             */
/*   Updated: 2017/01/21 13:21:24 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstfree(t_list **lst)
{
	t_list	*ptr;

	ptr = *lst;
	while (*lst)
	{
		ptr = ptr->next;
		free(*lst);
		*lst = ptr;
	}
	free(lst);
}
