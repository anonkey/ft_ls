/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 04:38:58 by tseguier          #+#    #+#             */
/*   Updated: 2014/04/20 23:21:11 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include "ft_params.h"
#include "ft_error.h"
#include "libft.h"
#include "ft_bf.h"

char	g_tabparams[] = "lRart";

int				ft_paramtoind(char c)
{
	char	*find;

	find = ft_strchr(g_tabparams, (int)c);
	return (find ? find - g_tabparams : -1);
}

static int		ft_paramstobf(int ac, char **av, t_bf paramsbf)
{
	int		i;
	int		j;
	int		param;

	i = 1;
	*paramsbf = EMPTY_FIELD;
	if (ac < 2)
		return (0);
	while (i < ac && av[i][0] == '-')
	{
		j = 1;
		if (av[i][1] == '\0')
			return (-1);
		while (av[i][j] != '\0')
		{
			if (-1 == (param = ft_paramtoind(av[i][j])))
				return ((int)av[i][j]);
			ft_bfsetbit(paramsbf, param);
			++j;
		}
		++i;
	}
	return (0);
}

static int		ft_paramstodir(int ac, char **av, t_params params)
{
	int		i;
	char	*endslash;

	if (!params)
		return (-1);
	i = 1;
	while (i < ac && av[i][0] == '-')
		++i;
	if (i < ac)
	{
		params->dir = opendir(av[i]);
		params->root = ft_strdup(av[i]);
		if ((endslash = ft_strrchr(params->root, '/'))
			&& endslash[1] == '\0')
			*endslash = '\0';
	}
	else
	{
		params->dir = opendir("./");
		params->root = ft_strdup(".");
	}
	if (!params->root)
		params->status -= 2;
	return (params->dir ? 0 : -4);
}

t_params		ft_paramsnew(int ac, char **av)
{
	t_params	newparams;

	if (!av)
		return (NULL);
	newparams = (t_params)ft_memalloc(sizeof(struct s_params));
	if (!newparams)
		return (NULL);
	newparams->opts = ft_bfnew();
	newparams->curpath = NULL;
	newparams->status = ft_paramstobf(ac, av, newparams->opts);
	if (newparams->status)
	{
		ft_printerror("Bad Arguments", FALSE);
		exit(1);
	}
	newparams->status = ft_paramstodir(ac, av, newparams);
	return (newparams);
}

void			ft_paramsdel(t_params *params)
{
	free((*params)->opts);
	free((*params)->root);
	closedir((*params)->dir);
	ft_memdel((void **)params);
}
