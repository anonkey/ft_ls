/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taskman.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 07:18:47 by tseguier          #+#    #+#             */
/*   Updated: 2014/09/26 16:30:57 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include <sys/stat.h>
#include <unistd.h>
#include <libft.h>
#include <errno.h>
#include <stdio.h>
#include "ft_cmpgenfunc.h"
#include "ft_params.h"
#include "ft_error.h"
#include "ft_taskman.h"
#include "ft_ls.h"

static int		ft_refreshpath(char *dir, char **path)
{
	char	*newpath;

	if (!dir || !path || !*path)
		return (-41);
	newpath = ft_strjoin(*path, "/");
	if (!newpath)
		return (-42);
	ft_strdel(path);
	*path = newpath;
	newpath = ft_strjoin(*path, dir);
	ft_strdel(path);
	*path = newpath;
	return ((*path) ? 0 : -43);
}

void			ft_finfodel(t_finfo **info, t_params p)
{
	ft_strdel(&((*info)->name));
	ft_strdel(&((*info)->path));
	if (ft_bftstbit(p->opts, ft_paramtoind('l')))
	{
		ft_strdel(&((*info)->uname));
		ft_strdel(&((*info)->group));
		if (S_ISLNK((*info)->rights))
			ft_strdel(&((*info)->link));
	}
	ft_memdel((void **)info);
}


static void		ft_fillinfosl(struct stat *statf, t_finfo *info)
{
	struct passwd	*passwdf;
	struct group	*grf;

	passwdf = getpwuid(statf->st_uid);
	info->uname = ft_strdup(passwdf->pw_name);
	grf = getgrgid(statf->st_gid);
	info->group = ft_strdup(grf->gr_name);
	info->size = statf->st_size;
	info->blk = statf->st_blocks;
	info->min = minor(statf->st_rdev);
	info->maj = major(statf->st_rdev);
	info->rights = statf->st_mode;
	info->lnk = statf->st_nlink;
	info->size = statf->st_size;
	if (S_ISLNK(statf->st_mode))
	{
		info->link = ft_strnew(statf->st_size);
		readlink(info->path, info->link, statf->st_size + 1);
	}
}

static void		ft_fillinfos(struct dirent *file, t_finfo *info, t_params params)
{
	struct stat		statf;

	info->name = ft_strdup(file->d_name);
	info->path = ft_strdup(params->curpath ? params->curpath : params->root);
	ft_refreshpath(info->name, &(info->path));
	if (ft_bftstbit(params->opts, ft_paramtoind('t'))
		|| ft_bftstbit(params->opts, ft_paramtoind('l')))
	{
		lstat(info->path, &statf);
		info->ldm_sec = statf.st_mtimespec.tv_sec;
		if (ft_bftstbit(params->opts, ft_paramtoind('l')))
		{
			ft_fillinfosl(&statf, info);
			if (ft_bftstbit(params->opts, ft_paramtoind('a')) || (info->name)[0] != '.')
				params->blk += info->blk;
		}
	}
}

int				ft_filltasklists(t_ldcd f, t_ldcd t, DIR *dir, t_params params)
{
	struct dirent	*file;
	t_finfo			info;
	int				free;
	int (*buffcmp)(void *, void *);

	buffcmp = ft_bftstbit(params->opts, ft_paramtoind('t')) ? &inftimecmp : &namecmp;
	if (!dir)
		return (-21);
	file = readdir(dir);
	params->blk = 0;
	while (file)
	{
		free = 1;
		ft_bzero((void *)&info, sizeof(t_finfo));
		ft_fillinfos(file, &info, params);
		if (ft_bftstbit(params->opts, ft_paramtoind('R'))
			&& file->d_type == DT_DIR && ft_strcmp(info.name, ".")
			&& ft_strcmp(info.name, ".."))
			free *= ft_ldcdpush_sorted(t, &info, sizeof(t_finfo), buffcmp);
		if (ft_bftstbit(params->opts, ft_paramtoind('a')) || (info.name)[0] != '.')
			free *= ft_ldcdpush_sorted(f, &info, sizeof(t_finfo), buffcmp);
		if (free)
		{
			ft_putendl(info.name);
			ft_putendl(info.path);
		//	ft_strdel(&info.name);
		//	ft_strdel(&info.path);
		}
		file = readdir(dir);
	}
	return (0);
}

static void		ft_putdirerror(char *path, char **dirname)
{
	ft_putstr(path);
	ft_putendl(":");
	ft_printerror(*dirname, TRUE);
}

static int		ft_executetask(t_ldcd tasklist, t_params params)
{
	t_finfo		*dirname;
	DIR			*dir;
	int			ret;

	if (ft_bftstbit(params->opts, ft_paramtoind('r')))
		dirname = (t_finfo *)ft_ldcdpop_back(tasklist);
	else
		dirname = (t_finfo *)ft_ldcdpop_front(tasklist);
	if (!dirname->name || ft_refreshpath(dirname->name, &(params->curpath)))
		return (-315);
	dir = opendir(params->curpath);
	if (!dir)
		ft_putdirerror(params->curpath, &(dirname->name));
	ret = ft_ls(dir, params);
	if (dir)
		closedir(dir);
	ft_finfodel(&dirname, params);
	if (ret)
		return (-32);
	*(ft_strrchr(params->curpath, '/')) = '\0';
	return (0);
}

int				ft_executetasklist(t_ldcd tasklist, t_params params)
{
	int		error;

	ft_getchar();

	error = 0;
	if (!tasklist || !params)
		return (-32);
	if (!params->curpath)
		params->curpath = ft_strdup(params->root);
	if (!params->curpath)
		return (-32);
	if (ft_ldcdsize(tasklist) == 0)
		return (0);
	while (ft_ldcdsize(tasklist) != 0)
	{
		if ((error = ft_executetask(tasklist, params)))
			return (error);
	}
	return (0);
}
