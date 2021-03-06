/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcdpush_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 01:58:05 by tseguier          #+#    #+#             */
/*   Updated: 2014/04/19 02:40:58 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ldcd_cell.h"

int		ft_ldcdpush_back(t_ldcd ldcd, void *elem, size_t elem_size)
{
	t_ldcd_cell		temp;

	if (!ldcd)
		return (-1);
	temp = ft_ldcd_cellnew(elem, elem_size);
	if (!temp)
		return (-1);
	temp->prev = ldcd->tail;
	ldcd->tail = temp;
	if (!temp->prev)
		ldcd->head = temp;
	else
		temp->prev->next = temp;
	++(ldcd->size);
	return (0);
}
