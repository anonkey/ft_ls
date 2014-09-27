/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 02:13:15 by tseguier          #+#    #+#             */
/*   Updated: 2014/04/21 03:29:57 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARAMS_H
# define FT_PARAMS_H
# include <dirent.h>
# include <sys/types.h>
# include "ft_bf.h"
# include "ft_bool.h"

typedef struct		s_params
{
	t_bf	opts;
	DIR		*dir;
	char	*root;
	char	*curpath;
	int		status;
	quad_t	blk;
}					t_sparam;

typedef t_sparam	*t_params;

t_params			ft_paramsnew(int ac, char **av);

void				ft_paramsdel(t_params *params);

int					ft_paramtoind(char c);

#endif
