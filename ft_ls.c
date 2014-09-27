/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 23:25:41 by tseguier          #+#    #+#             */
/*   Updated: 2014/09/26 16:11:50 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <libft.h>
#include <dirent.h>
#include <time.h>
#include "ft_error.h"
#include "ft_bool.h"
#include "ft_params.h"
#include "ft_taskman.h"

static char		ft_gettype(mode_t mode)
{
	if (S_ISDIR(mode))
		return ('d');
	if (S_ISCHR(mode))
		return ('c');
	if (S_ISBLK(mode))
		return ('b');
	if (S_ISLNK(mode))
		return ('l');
	if (S_ISFIFO(mode))
		return ('p');
	if (S_ISSOCK(mode))
		return ('s');
	return ('-');
}

static void		ft_putrights(mode_t mode)
{
	char	str[11];

	ft_memset((void *)str, '-', 10);
	str[10] = '\0';
	str[0] = ft_gettype(mode);
	if (mode & S_IRUSR)
		str[1] = 'r';
	if (mode & S_IWUSR)
		str[2] = 'w';
	if (mode & S_IXUSR)
		str[3] = 'x';
	if (mode & S_IRGRP)
		str[4] = 'r';
	if (mode & S_IWGRP)
		str[5] = 'w';
	if (mode & S_IXGRP)
		str[6] = 'x';
	if (mode & S_IROTH)
		str[7] = 'r';
	if (mode & S_IWOTH)
		str[8] = 'w';
	if (mode & S_IXOTH)
		str[9] = 'x';
	ft_putstr(str);
	ft_putstr("  ");
}

static void		ft_putfinfo(t_finfo *file, t_params params)
{
	char	*date;
	char	*iter;

	if (ft_bftstbit(params->opts, ft_paramtoind('l')))
	{
		ft_putrights(file->rights);
		ft_putnbr(file->lnk);
		ft_putstr(" ");
		ft_putstr(file->uname);
		ft_putstr("  ");
		ft_putstr(file->group);
		ft_putstr("  ");
		if (S_ISCHR(file->rights) || S_ISBLK(file->rights))
		{
			ft_putnbr(file->maj);
			ft_putstr(", ");
			ft_putnbr(file->min);
		}
		else
			ft_putnbr(file->size);
		date = ctime(&(file->ldm_sec));
		date = ft_strchr(date, ' ');
		iter = ft_strrchr(date, ':');
		*iter = '\0';
		ft_putstr(date);
		ft_putstr(" ");
	}
	ft_putstr(file->name);
	if (S_ISLNK(file->rights))
	{
		ft_putstr("->");
		ft_putstr(file->link);
	}
	ft_putendl("");
}

static int		ft_putfilelist(t_ldcd filelist, t_params params)
{
	t_finfo	*file;
	t_bool	haswork;

	if (!filelist || !params->opts)
		return (-11);
	haswork = (ft_ldcdsize(filelist) != 0);
	if (params->curpath)
	{
		ft_putstr(params->curpath);
		ft_putendl(":");
	}
	if (haswork && ft_bftstbit(params->opts, ft_paramtoind('l')))
	{
		ft_putstr("total ");
		ft_putnbr(params->blk);
		ft_putendl("");
		params->blk = 0;
	}
	while (ft_ldcdsize(filelist) != 0)
	{
		if (ft_bftstbit(params->opts, ft_paramtoind('r')))
			file = (t_finfo *)ft_ldcdpop_back(filelist);
		else
			file = (t_finfo *)ft_ldcdpop_front(filelist);
		if (!file)
			return (-12);
		ft_putfinfo(file, params);
		if (!S_ISDIR(file->rights))
			ft_finfodel(&file, params);
	}
	return (0);
}

int				ft_ls(DIR *dir, t_params params)
{
	t_ldcd			filelist;
	t_ldcd			tasklist;
	int				error;

	if (!dir)
		return (0);
	error = 0;
	filelist = ft_ldcdnew();
	if (!filelist || !params->opts)
		return (-2);
	tasklist = ft_ldcdnew();
	if (!tasklist)
	{
		ft_ldcddel(&filelist, &ft_memdel);
		return (-3);
	}
	if ((error = ft_filltasklists(filelist, tasklist, dir, params)))
		return (error);
	ft_getchar();
	if (!params->curpath || *(1 + ft_strrchr(params->curpath, '/')) != '.'
			|| ft_bftstbit(params->opts, ft_paramtoind('a')))
	{
		if (params->curpath)
			ft_putendl("");
		if ((error = ft_putfilelist(filelist, params)))
			return (error);
	}
	ft_ldcddel(&filelist, NULL);
	if (ft_bftstbit(params->opts, ft_paramtoind('R')))
		error += ft_executetasklist(tasklist, params);
	ft_ldcddel(&tasklist, NULL);
	return (error);
}
