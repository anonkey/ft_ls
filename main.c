/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 06:08:12 by tseguier          #+#    #+#             */
/*   Updated: 2014/09/26 15:38:41 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <libft.h>
#include "ft_error.h"
#include "ft_ls.h"
#include "ft_params.h"

int main(int argc, char **argv)
{
	t_params	params;
	int			error;

	params = ft_paramsnew(argc, argv);
	if (!params || (params->status < 0 && params->status != -4))
		return (1);
	if (params->status == -4)
		ft_printerror(params->root, TRUE);
	else if ((error = ft_ls(params->dir, params)))
		return (error);
	ft_getchar();
	return (0);
}
