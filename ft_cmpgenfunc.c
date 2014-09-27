/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmpgenfunc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 23:37:15 by tseguier          #+#    #+#             */
/*   Updated: 2014/04/20 23:39:11 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_taskman.h"

int		buff3cmp(void *b1, void *b2)
{
	return (ft_strcmp(b1, b2));
}

int		namecmp(void *b1, void *b2)
{
	t_finfo	*i1;
	t_finfo	*i2;

	i1 = (t_finfo *)b1;
	i2 = (t_finfo *)b2;
	return (ft_strcmp(i1->name, i2->name));
}

int		inftimecmp(void *b1, void *b2)
{
	t_finfo	*i1;
	t_finfo	*i2;

	i1 = (t_finfo *)b1;
	i2 = (t_finfo *)b2;
	if (i1->ldm_sec == i2->ldm_sec)
	{
		return (ft_strcmp(i1->name, i2->name));
	}
	else
		return (i2->ldm_sec - i1->ldm_sec);
}
