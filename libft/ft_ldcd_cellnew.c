/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcd_cellnew.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 01:23:50 by tseguier          #+#    #+#             */
/*   Updated: 2014/04/19 02:40:45 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_ldcd_cell.h"

t_ldcd_cell		ft_ldcd_cellnew(void *elem, size_t elem_size)
{
	t_ldcd_cell		newcell;

	newcell = (t_ldcd_cell)malloc(sizeof(struct s_ldcd_cell));
	if (!newcell)
		return (NULL);
	if (!elem || elem_size == 0)
	{
		newcell->content = elem;
		newcell->content_size = 0;
	}
	else
	{
		newcell->content = ft_memdup(elem, elem_size);
		newcell->content_size = elem_size;
		newcell->next = NULL;
		newcell->prev = NULL;
	}
	return (newcell);
}
