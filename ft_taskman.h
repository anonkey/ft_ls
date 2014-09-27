/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taskman.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 07:11:01 by tseguier          #+#    #+#             */
/*   Updated: 2014/09/26 16:12:00 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TASKMAN_H
# define FT_TASKMAN_H
# include <dirent.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/types.h>
# include "ft_params.h"

typedef struct		s_finfo
{
	char			*name;
	char			*path;
	char			*link;
	off_t			size;
	time_t			ldm_sec;
	mode_t			rights;
	char			*uname;
	char			*group;
	nlink_t			lnk;
	unsigned int	min;
	unsigned int	maj;
	quad_t			blk;
}					t_finfo;

int		ft_filltasklists(t_ldcd f, t_ldcd t, DIR *dir, t_params params);

int		ft_executetasklist(t_ldcd tasklist, t_params params);

void	ft_finfodel(t_finfo **info, t_params p);

#endif
