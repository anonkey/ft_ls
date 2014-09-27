/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 20:25:13 by tseguier          #+#    #+#             */
/*   Updated: 2014/04/19 02:15:32 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bf.h"
#include "libft.h"

t_bf		ft_bfnew(void)
{
	t_bf	newbf;

	newbf = (t_bf)ft_memalloc(sizeof(unsigned int));
	return (newbf);
}

void		ft_bfsetbit(t_bf bf, unsigned int i)
{
	*bf |= (1 << i);
}

t_bool		ft_bftstbit(t_bf bf, unsigned int i)
{
	return (((*bf & (1 << i)) >> i) != 0);
}

void		ft_bfclrbit(t_bf bf, unsigned int i)
{
	*bf &= ~(1 << i);
}
