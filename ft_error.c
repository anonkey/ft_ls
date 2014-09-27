/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 05:34:37 by tseguier          #+#    #+#             */
/*   Updated: 2014/04/19 02:44:36 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <libft.h>
#include "ft_bool.h"
#include "ft_error.h"

void	ft_printerror(const char *s, t_bool syserror)
{
	ft_putstr_fd("ft_ls: ", 2);
	if (s)
	{
		ft_putstr_fd(s, 2);
		ft_putstr_fd(" :", 2);
	}
	if (syserror)
		ft_putendl_fd(strerror(errno), 2);
}
