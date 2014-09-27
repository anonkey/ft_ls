/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcd_celldel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 02:04:24 by tseguier          #+#    #+#             */
/*   Updated: 2014/04/19 02:40:44 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_ldcd_celldel(t_ldcd_cell *cell, void (*del)(void **))
{
	if (!cell)
		return ;
	if (del)
		(*del)(&((*cell)->content));
	ft_memdel((void **)cell);
}
