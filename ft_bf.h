/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 20:38:24 by tseguier          #+#    #+#             */
/*   Updated: 2014/04/19 02:17:13 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BF_H
# define FT_BF_H
# define EMPTY_FIELD 0
# include "ft_bool.h"

/*
** Bitfield type
*/
typedef unsigned int		*t_bf;

/*
** Return a new t_bf structure
*/
t_bf		ft_bfnew(void);

/*
** Return 'bf' with 'i'-th bit set to 'TRUE'
*/
void		ft_bfsetbit(t_bf bf, unsigned int i);

/*
** Return 'bf' with 'i'-th bit set to 'FALSE'
*/
void		ft_bfclrbit(t_bf bf, unsigned int i);

/*
** Return the state of the 'i'-th bit of 'bf'
*/
t_bool		ft_bftstbit(t_bf bf, unsigned int i);

#endif
