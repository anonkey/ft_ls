/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:17:22 by tseguier          #+#    #+#             */
/*   Updated: 2014/04/19 02:41:56 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdarg.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	newstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!newstr)
		return (NULL);
	ft_strcpy(newstr, s1);
	return (ft_strcat(newstr, s2));
}

/*
** ft_strmjoin join 'nbstr' strings in an new string and return it.
** while empty va_list in the 'strings' char *tab
** measuring total new string's len.
** malloc(totallen + 1) for '\0'.
*/

char	*ft_strmjoin(int nbstr, ...)
{
	char	*newstr;
	va_list	list;
	char	*strings[nbstr];
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	va_start(list, nbstr);
	while (i < nbstr)
	{
		strings[i] = va_arg(list, char *);
		len += (strings[i]) ? ft_strlen(strings[i]) : 0;
		++i;
	}
	newstr = ft_strnew(len + 1);
	i = 0;
	while (i < nbstr)
	{
		if (strings[i])
			ft_strcat(newstr, strings[i]);
		++i;
	}
	va_end(list);
	return (newstr);
}


/*
** Like ft_strmjoin but takes char ** for free and clean all char * pointers
*/
char		*ft_strmjoinclean(int nbstr, ...)
{
	char		*newstr;
	va_list		list;
	char		**strings[nbstr];
	int			i;
	size_t		totallen;

	i = 0;
	totallen = 0;
	va_start(list, nbstr);
	while (i < nbstr)
	{
		strings[i] = va_arg(list, char **);
		totallen += (*strings[i]) ? ft_strlen(*strings[i]) : 0;
		++i;
	}
	newstr = ft_strnew(totallen + 1);
	i = 0;
	while (i < nbstr)
	{
		if (*strings[i])
			ft_strcat(newstr, *strings[i]);
		ft_strdel(strings[i]);
		++i;
	}
	va_end(list);
	return (newstr);
}
